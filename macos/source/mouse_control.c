#include "../include/fractol.h"

int				julia_motion(int x, int y, t_fractol *fractol)
{
	if (!fractol->help_menu && !fractol->about_julia)
	{
		fractol->constant = init_vectors(
			4 * ((double)x / WIDTH - 0.5),
			4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
		draw_fract(fractol);
	}
	return (0);
}
