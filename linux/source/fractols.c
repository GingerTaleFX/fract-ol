/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 23:16:17 by root              #+#    #+#             */
/*   Updated: 2020/08/27 23:16:47 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int             iterate_mandelbrot(t_fractol *fractol)
{
    int         i;
    t_compnums  z;

    i = 0;
    z = init_compnums(fractol->complex_number.re, fractol->complex_number.im);
    while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && i <= fractol->max_iter)
    {
        z = init_compnums(
                pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->complex_number.re,
                2.0 * z.re * z.im + fractol->complex_number.im);
        i++;
    }
    return (i);
}

int                     iterate_mandelbar(t_fractol *fractol)
{
        int		i;
        t_compnums	z;

        i = 0;
        z = init_compnums(fractol->complex_number.re, fractol->complex_number.im);
        while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
                && i < fractol->max_iter)
        {
                z = init_compnums(
                        pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->complex_number.re,
                        -2.0 * z.re * z.im + fractol->complex_number.im);
                i++;
        }
        return (i);
}

int			iterate_celtic_mandelbrot(t_fractol *fractol)
{
	int		i;
	t_compnums	z;

	i = 0;
	z = init_compnums(fractol->complex_number.re, fractol->complex_number.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& i < fractol->max_iter)
	{
		z = init_compnums(
			fabs(pow(z.re, 2.0) - pow(z.im, 2.0)) + fractol->complex_number.re,
			2.0 * z.re * z.im + fractol->complex_number.im);
		i++;
	}
	return (i);
}

int			iterate_julia(t_fractol *fractol)
{       
        int		i;
        t_compnums	z;
        
        i = 0;
        z = init_compnums(fractol->complex_number.re, fractol->complex_number.im);
        while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
                && i < fractol->max_iter)
        {       
                z = init_compnums( 
                        pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->constant.re,
                        2.0 * z.re * z.im + fractol->constant.im);
                i++;
        }
        return (i);
}
