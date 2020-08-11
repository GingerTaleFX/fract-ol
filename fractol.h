/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 10:55:45 by root              #+#    #+#             */
/*   Updated: 2020/08/07 15:10:52 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_FRACTOL_H
#define FRACTOL_FRACTOL_H

#include "libft/libft.h"
#include "linux_keys.h"
#include <math.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <X11/X.h>
#include "minilibx/mlx.h"
#include <pthread.h>

#define WIDTH 600
#define HEIGHT 600
#define THREADS 10
#define RED 0xef5734
# define COLOR_TUNDORA		0x444444

/*
** re — real part
** im — imaginary part
*/

typedef struct s_vectors
{
    double re;
    double im;

}               t_vectors;

typedef struct s_img
{
    void        *img;
    char        *data_addr;
    int         bits_p_pix;
    int         line_size;
    int         endian;
}               t_img;

typedef struct s_fractol
{
    void    *mlx;
    void    *f_window;
    t_vectors complex_number;
    t_vectors		min;
    t_vectors		max;
    t_vectors		factor;
    int         max_iter;
    int         color_shift;
    int			(*formula)(struct s_fractol *fractol);
    t_img       *img;
    int			start_line;
    int			finish_line;
//    int				max_iteration;

}           t_fractol;

typedef struct s_formula
{
    char    *name;
    int		(*formula)(struct s_fractol *fractol);

}               t_formula;

typedef	struct		s_color
{
    int8_t			channel[4];
}					t_color;


t_fractol   *init_fract(char *name, void *mlx);
t_vectors   init_vectors(double re, double im);
t_img       *init_img(void  *mlx);
void        set_defaults(t_fractol *fractol);
int         (*get_fractal(char *name)) (t_fractol *fractol);
t_color     get_color(int iteration, t_fractol *fractol);
void        put_pixel(t_fractol *fractol, int x, int y, t_color color);
void        draw_frac_part(t_fractol *fract);
void        draw_fract(t_fractol *fract);

#endif