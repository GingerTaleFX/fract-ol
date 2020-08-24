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

#include "../include/fractol.h"

void			set_defaults(t_fractol *fractol)
{
    fractol->max_iter = 50;
    fractol->min =  init_compnums(-2.0, -2.0);
    fractol->max.re = 2.0;
    fractol->max.im = fractol->min.im + (fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
    fractol->constant = init_compnums(-0.4, 0.6);
	fractol->color_shift = 0;
}

int         (*get_fractal(char *name)) (t_fractol *fractol)
{
    size_t  i;
    int     (*formula)(t_fractol *fractol);
    t_formula   formulas[] = {
	{ "Mabdelbrot", &iterate_mandelbrot },
    	{"Mandelbar", &iterate_mandelbar},
	{"CelticMandelbrot", &iterate_celtic_mandelbrot},
	{"Julia", &iterate_julia}
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
    t_fractol   *fracs[THREADS];
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
//    ac = 2;
//    av[1] = "Mandelbrot";

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
	else
	{
	ft_putendl("Usage: /fractal [number of fractal]");
	ft_putendl("[1] - Mandelbrot | [2] - Mandelbar | [3] = Celtic Mandelbrot | [4] - Julia");
	}   
 return (0);
}
