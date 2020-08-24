/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:02:36 by root              #+#    #+#             */
/*   Updated: 2020/08/07 17:51:07 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_img		*init_img(void  *mlx)
{
    t_img	*img;

    img = (t_img *)(ft_memalloc(sizeof(t_img)));
    img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
    img->data_addr = mlx_get_data_addr(img->img, &(img->bits_p_pix), &(img->line_size), &(img->endian));
    return (img);
}


t_fractol	*init_fract(char *name, void *mlx)
{
    t_fractol	*fract;

    fract = (t_fractol *)(ft_memalloc(sizeof(t_fractol)));
    fract->mlx = mlx;
    fract->f_window = mlx_new_window(mlx, WIDTH, HEIGHT, name);
    fract->img = init_img(mlx);
    set_defaults(fract);
    fract->formula = get_fractal(name);
	fract->about_julia = true;
	mlx_hook(fract->f_window, 2, 0, key_press, fract);
    mlx_hook(fract->f_window, 4, 0, zoom, fract);
	if (ft_strequ(name, "julia"))
		mlx_hook(fract->f_window, 6, 0, julia_motion, fract);
    return(fract);
}

t_compnums	init_compnums(double re, double im)
{
    t_compnums compnums;

    compnums.re = re;
    compnums.im = im;
    return (compnums);
}
