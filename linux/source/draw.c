/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:04:09 by root              #+#    #+#             */
/*   Updated: 2020/08/27 23:08:44 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_color			get_color(int iteration, t_fractol *fractol)
{
	t_color		color;
	double		t;

	t = percent(0, fractol->max_iter, iteration);
	color.channel[0] = 0;
	color.channel[(0 + fractol->color_shift) \
	% 3 + 1] = (int8_t)(3 * (1 - t) * pow(t, 3) * 0xff);
	color.channel[(1 + fractol->color_shift) \
	% 3 + 1] = (int8_t)(15 * pow(1 - t, 2) * pow(t, 2) * 0xff);
	color.channel[(2 + fractol->color_shift) \
	% 3 + 1] = (int8_t)(5 * pow((1 - t), 3) * t * 0xff);
	return (color);
}

void			put_pixel(t_fractol *fractol, int x, int y, t_color color)
{
	int			i;

	i = (x * fractol->img->bits_p_pix / 8) \
	+ (y * fractol->img->line_size);
	fractol->img->data_addr[i] = color.channel[3];
	fractol->img->data_addr[++i] = color.channel[2];
	fractol->img->data_addr[++i] = color.channel[1];
	fractol->img->data_addr[++i] = color.channel[0];
}

void			draw_frac_part(t_fractol *fract)
{
	double		x;
	double		y;
	t_color		color;

	y = fract->start_line;
	while (y < fract->finish_line)
	{
		fract->complex_number.im = fract->max.im - y * fract->factor.im;
		x = 0;
		while (x < WIDTH)
		{
			fract->complex_number.re = fract->min.re + x * fract->factor.re;
			color = get_color(fract->formula(fract), fract);
			put_pixel(fract, x, y, color);
			x++;
		}
		y++;
	}
}

void			draw_fract(t_fractol *fract)
{
	t_fractol	all_fr[THREADS];
	pthread_t	threads[THREADS];
	int			i;

	fract->factor = init_compnums(((fract->max.re - fract->min.re) \
	/ (WIDTH - 1)), ((fract->max.im - fract->min.im) / (HEIGHT - 1)));
	i = 0;
	while (i < THREADS)
	{
		all_fr[i] = *fract;
		all_fr[i].start_line = i * (HEIGHT / THREADS);
		all_fr[i].finish_line = (i + 1) * (HEIGHT / THREADS);
		draw_frac_part(fract);
		pthread_create(&threads[i], NULL, \
		(void *)(void *)draw_frac_part, (void *)&all_fr[i]);
		i++;
	}
	while (i-- > 0)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(fract->mlx, fract->f_window, fract->img->img, 0, 0);
	mlx_string_put(fract->mlx, fract->f_window, 20, 10, PEACH, "H - Help");
}

void			draw_help(t_fractol *fractol)
{
	ft_bzero(fractol->img->data_addr,
		WIDTH * HEIGHT * (fractol->img->bits_p_pix / 8));
	mlx_put_image_to_window(fractol->mlx, fractol->f_window,
		fractol->img->img, 0, 0);
	mlx_string_put(fractol->mlx, fractol->f_window, \
	MENU_W, MENU_H, MINT, "Controls");
	mlx_string_put(fractol->mlx, fractol->f_window, \
	MENU_W, MENU_H + LINER, MINT, "Reset - R");
	mlx_string_put(fractol->mlx, fractol->f_window, \
	MENU_W, MENU_H + LINER, MINT, "Color Shift - C");
	mlx_string_put(fractol->mlx, fractol->f_window, \
	MENU_W, MENU_H + (LINER * 3), MINT, "Move - Arrows");
	mlx_string_put(fractol->mlx, fractol->f_window,\
	MENU_W, MENU_H + (LINER * 4), MINT, "Zoom - Scroll");
	mlx_string_put(fractol->mlx, fractol->f_window, \
	MENU_W, MENU_H + (LINER * 5), MINT, "Iterations - +/-");
	mlx_string_put(fractol->mlx, fractol->f_window, \
	MENU_W, MENU_H + (LINER * 6), MINT, "Julia Constant - Mouse");
	mlx_string_put(fractol->mlx, fractol->f_window, \
	MENU_W, MENU_H + (LINER * 7), MINT, "Mouse Lock - Space");
	mlx_string_put(fractol->mlx, fractol->f_window, \
	MENU_W, MENU_H + (LINER * 8), MINT, "Close Help - H");
}
