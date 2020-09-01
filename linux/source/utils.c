/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 15:11:03 by root              #+#    #+#             */
/*   Updated: 2020/09/01 15:11:03 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double			percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return ((placement / distance));
}

double			interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void			terminate(char *s)
{
	ft_putendl_fd(s, 2);
	exit(0);
}
