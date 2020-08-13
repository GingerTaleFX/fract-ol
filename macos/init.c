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

#include "fractol.h"

int			key_press(int key, t_fractol *fractol)
{
//	printf("%i\n", key);
    if (key == MAIN_PAD_ESC)
        exit(0);
    else if (key == MAIN_PAD_H)
        help_menu(fractol);
    else if (!fractol->help_menu)
    {
        if (key == MAIN_PAD_R)
        {
            set_defaults(fractol);
            draw_fract(fractol);
        }
        else if (key == MAIN_PAD_MINUS || key == NUM_PAD_MINUS
                || key == MAIN_PAD_PLUS || key == NUM_PAD_PLUS)
            change_max_iteration(key, fractol);
        else if (key == ARROW_LEFT || key == ARROW_RIGHT
                 || key == ARROW_UP || key == ARROW_DOWN)
            move(key, fractol);
        else if (key == MAIN_PAD_C)
            change_color_shift(fractol);
        else if (key == MAIN_PAD_SPACE)
           fractol->about_julia = !fractol->about_julia;
    }
    return (0);
}

t_img       *init_img(void  *mlx)
{
    t_img       *img;

    img = (t_img *)(ft_memalloc(sizeof(t_img)));
    img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
    img->data_addr = mlx_get_data_addr(img->img, &(img->bits_p_pix), &(img->line_size), &(img->endian));
    return (img);
}


t_fractol   *init_fract(char *name, void *mlx)
{
    t_fractol *fract;

    fract = (t_fractol *)(ft_memalloc(sizeof(t_fractol)));
    fract->mlx = mlx;
    fract->f_window = mlx_new_window(mlx, WIDTH, HEIGHT, name);
    fract->img = init_img(mlx);
    set_defaults(fract);
    fract->formula = get_fractal(name);
	fract->about_julia = true;
	mlx_hook(fract->f_window, 2, 0, key_press, fract);
    mlx_hook(fract->f_window, 4, 0, zoom, fract);
	if (ft_strequ(name, "Julia"))
		mlx_hook(fract->f_window, 6, 0, julia_motion, fract);
    return(fract);
}

t_vectors   init_vectors(double re, double im)
{
    t_vectors vectors;

    vectors.re = re;
    vectors.im = im;
    return (vectors);
}
