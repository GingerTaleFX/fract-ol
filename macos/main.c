/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 10:55:28 by root              #+#    #+#             */
/*   Updated: 2020/08/07 20:03:59 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set_defaults(t_fractol *fractol)
{
    fractol->max_iter = 25;
    fractol->min =  init_vectors(-2.0, -2.0);
    fractol->max.re = 2.0;
    fractol->max.im = fractol->min.im + (fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
    fractol->color_shift = 0;
}

int         iterate_mandelbrot(t_fractol *fractol)
{
    int it;
    t_vectors z;

    it = 0;
    z = init_vectors(fractol->complex_number.re, fractol->complex_number.im);
//    printf("Before while\n z.re = %f\n z.im = %f\n", z.re, z.im);
    while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && it <= fractol->max_iter)
    {
        z = init_vectors(
                pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->complex_number.re,
                2.0 * z.re * z.im + fractol->complex_number.im);
        it++;
    }
    return (it);
}

int         (*get_fractal(char *name)) (t_fractol *fractol)
{
    size_t  i;
    int     (*formula)(t_fractol *fractol);
    t_formula   formulas[] = {
            { "Mandelbrot", &iterate_mandelbrot }
    };

    i = 0;
    formula = NULL;
    while (i < (sizeof(formulas) / sizeof(t_formula)))
    {
        if (ft_strequ(name, formulas[i].name))
            formula = formulas[i].formula;
        i++;
    }
    return (formula);
}

void        start(int number, char **names)
{
    t_fractol   *fracs[3];
    void        *mlx;
    int         i;

    i = 0;
    mlx = mlx_init();
    while (i < number)
    {
        fracs[i] = init_fract(names[i], mlx);
        draw_fract(fracs[i]);
        i++;
    }
    mlx_loop(mlx);
}

int         main(int ac, char **av) {
    int i;
    ac = 2;
    av[1] = "Mandelbrot";

    if (ac >= 2 && ac <= 11)
    {
        i = 1;
        while (i < ac)
        {
            if (!get_fractal(av[i]))
                break ;
            i++;
        }
        if ( i == ac)
            start(ac - 1, &av[1]);
    }
    return (0);
}
