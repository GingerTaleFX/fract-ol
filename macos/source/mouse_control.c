/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 12:55:05 by root              #+#    #+#             */
/*   Updated: 2020/09/07 12:55:05 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int				julia_motion(int x, int y, t_fractol *fractol)
{
	if (!fractol->help_menu && !fractol->about_julia)
	{
		fractol->constant = init_compnums(
			4 * ((double)x / WIDTH - 0.5),
			4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
		draw_fract(fractol);
	}
	return (0);
}
