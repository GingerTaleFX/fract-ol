/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 10:55:28 by root              #+#    #+#             */
/*   Updated: 2020/09/01 16:10:21 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void			set_defaults(t_fractol *fractol)
{
	fractol->max_iter = 50;
	fractol->min = init_compnums(-2.0, -2.0);
	fractol->max.re = 2.0;
	fractol->max.im = fractol->min.im + \
	(fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
	fractol->constant = init_compnums(-0.4, 0.6);
	fractol->color_shift = 0;
}

int         (*get_fractal(char *name)) (t_fractol *fractol)
{
	size_t		i;
	int			(*formula)(t_fractol *fractol);
//	t_formula   *formula;
	t_formula	formulas[4];

	i = 0;
	formula = NULL;
//	formula = (t_formula *)(ft_memalloc(sizeof(t_formula)));
//	formula->formula = NULL;
	formulas[0].name = "Mandelbrot";
	formulas[0].formula = &iterate_mandelbrot;
	formulas[1].name = "Mandelbar";
	formulas[1].formula = &iterate_mandelbar;
	formulas[2].name = "CelticMandelbrot";
	formulas[2].formula = &iterate_celtic_mandelbrot;
	formulas[3].name = "Julia";
	formulas[3].formula = &iterate_julia;
	while (i < (sizeof(formulas) / sizeof(t_formula)))
	{
		if (ft_strequ(name, formulas[i].name))
			formula = formulas[i].formula;
		i++;
	}
	return (formula);
//	while (i < (sizeof(formulas) / sizeof(t_formula)))
//	{
//		if (ft_strequ(name, formulas[i].name))
//		{
//			formula = formulas[i].name;
////			formula->name = formulas[i].name;
////			formula->formula = formulas[i].formula;
//		}
//		i++;
//	}
////	if (formula->name == NULL)
////		return (0);
//	return (formula);
}

void			start(int number, char **names)
{
	t_fractol	*fracs[THREADS];
	void		*mlx;
	int			i;

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

int				main(int ac, char **av)
{
	int			i;

	ac = 2;
	av[1] = "Mandelbrot";
	if (ac >= 2 && ac <= 11)
	{
		i = 1;
		while (i < ac)
		{
			if (!get_fractal(av[i]))
			{
				ft_putendl("Wrong name, try again");
				break ;
			}
			i++;
		}
		if (i == ac)
			start(ac - 1, &av[1]);
	}
	else
	{
		ft_putendl("Usage: /fractal [name of fractal]");
		ft_putendl("Mandelbrot | Mandelbar | CelticMandelbrot | Julia");
	}
	return (0);
}
