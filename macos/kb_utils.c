#include "fractol.h"
void	help_menu(t_fractol *fractol)
{
	fractol->help_menu = !fractol->help_menu;
	if (fractol->help_menu)
		draw_help(fractol);
	else
		draw_fract(fractol);
}


void	move(int key, t_fractol *fractol)
{
	t_vectors	delta;

	delta = init_vectors(FT_ABS(fractol->max.re - fractol->min.re),
		FT_ABS(fractol->max.im - fractol->min.im));
	if (key == ARROW_LEFT)
	{
		fractol->min.re -= delta.re * 0.05;
		fractol->max.re -= delta.re * 0.05;
	}
	else if (key == ARROW_RIGHT)
	{
		fractol->min.re += delta.re * 0.05;
		fractol->max.re += delta.re * 0.05;
	}
	else if (key == ARROW_UP)
	{
		fractol->min.im += delta.im * 0.05;
		fractol->max.im += delta.im * 0.05;
	}
	else if (key == ARROW_DOWN)
	{
		fractol->min.im -= delta.im * 0.05;
		fractol->max.im -= delta.im * 0.05;
	}
	draw_fract(fractol);
}

void	change_max_iteration(int key, t_fractol *fractol)
{
	if (key == MAIN_PAD_PLUS || key == NUM_PAD_PLUS)
	{
		if (fractol->max_iter < 50)
			fractol->max_iter += 1;
		else if (fractol->max_iter < 1000000000)
			fractol->max_iter = (int)(fractol->max_iter * 1.05);
	}
	if (key == MAIN_PAD_MINUS || key == NUM_PAD_MINUS)
	{
		if (fractol->max_iter > 50)
			fractol->max_iter = (int)(fractol->max_iter * 0.95);
		else if (fractol->max_iter > 1)
			fractol->max_iter -= 1;
	}
	draw_fract(fractol);
}

void	change_color_shift(t_fractol *fractol)
{
	fractol->color_shift = fractol->color_shift + 1 % 4;
	draw_fract(fractol);
}
