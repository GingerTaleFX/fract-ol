#include "fractol.h"

int				julia_motion(int x, int y, t_fractol *fractol)
{
	if (!fractol->is_help && !fractol->is_julia_fixed)
	{
		fractol->k = init_complex(
			4 * ((double)x / WIDTH - 0.5),
			4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
		draw_fractal(fractol);
	}
	return (0);
}
