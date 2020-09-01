/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 10:55:45 by root              #+#    #+#             */
/*   Updated: 2020/09/01 15:51:53 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/include/libft.h"
# include "errors.h"
# include "linux_keys.h"
# include "../minilibx/mlx.h"
# include <X11/X.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include <pthread.h>

# define WIDTH 600
# define HEIGHT 600
# define MENU_W (WIDTH / 3) - 30
# define MENU_H (HEIGHT / 3)
# define LINER 30
# define THREADS 10
# define PEACH 0xfc9649
# define MINT 0x46ba89

typedef enum
{
	false,
	true
}	t_bool;

/*
** re - real part
** im - imaginary part
*/

typedef struct	s_compnums
{
	double		re;
	double		im;

}				t_compnums;

/*
** img		- image identifier
** data_addr	- image
** bits_p_pix	- depth of image
** line_size	- number of bytes used to store one line of image
** endian	- little or big endian
*/

typedef	struct	s_img
{
	void		*img;
	char		*data_addr;
	int			bits_p_pix;
	int			line_size;
	int			endian;
}				t_img;

/*
** mlx						- for minilibx lib and window
** f_window					- for minilibx and window
** complex_number			- for pool of numbers, which will use for drawing
** constant					- for correct julia working
** min amd max				- 'mooving' pic in coords 2 and -2
** factor					- dependency between complex numbers and pixels
** max_iter					- default number for 1st pic
** formula					- saves the fractol formula
** start and finish lines	- start/end for correct work of threads
** help_menu				- for help menu
** about_julia				- shows if it is fixed or not
** img						- info about image
*/

typedef struct	s_fractol
{
	void		*mlx;
	void		*f_window;
	t_compnums	complex_number;
	t_compnums	constant;
	t_compnums	min;
	t_compnums	max;
	t_compnums	factor;
	int			max_iter;
	int			color_shift;
	int			(*formula)(struct s_fractol *fractol);
	int			start_line;
	int			finish_line;
	t_bool		help_menu;
	t_bool		about_julia;
	t_img		*img;
}				t_fractol;

/*
** t_formula for saving and sharing fractol formulas
*/

typedef struct	s_formula
{
	char		*name;
	int			(*formula)(struct s_fractol *fractol);
}				t_formula;

typedef	struct	s_color
{
	int8_t		channel[4];
}				t_color;

t_fractol	*init_fract(char *name, void *mlx);
t_compnums	init_compnums(double re, double im);
t_img		*init_img(void *mlx);
t_color		get_color(int iteration, t_fractol *fractol);
double		interpolate(double start, double end, double interpolation);
double		percent(int start, int end, int current);
double		interpolate(double start, double end, double interpolation);
void		set_defaults(t_fractol *fractol);
void		put_pixel(t_fractol *fractol, int x, int y, t_color color);
void		draw_frac_part(t_fractol *fract);
void		draw_fract(t_fractol *fract);
void		change_color_shift(t_fractol *fractol);
void		change_max_iteration(int key, t_fractol *fractol);
void		move(int key, t_fractol *fractol);
void		draw_help(t_fractol *fractol);
void		help_menu(t_fractol *fractol);
void		terminate(char *s);
int			key_press(int key, t_fractol *fractol);
int			zoom(int button, int x, int y, t_fractol *fractol);
int			julia_motion(int x, int y, t_fractol *fractol);
int			(*get_fractal(char *name))(t_fractol *fractol);
//t_formula		*get_fractal(char *name);
int			iterate_mandelbrot(t_fractol *fractol);
int			iterate_mandelbar(t_fractol *fractol);
int			iterate_celtic_mandelbrot(t_fractol *fractol);
int			iterate_julia(t_fractol *fractol);

#endif
