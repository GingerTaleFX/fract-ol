#include "../include/fractol.h"

double          percent(int start, int end, int current)
{
        double  placement;
        double  distance;

        placement = current - start;
        distance = end - start;
        if (distance == 0)
                return (1.0);
        else
                return ((placement / distance));
}

double  interpolate(double start, double end, double interpolation)
{
        return (start + ((end - start) * interpolation));
}

void	terminate(char *s)
{
	ft_putendl_fd(s, 2);
	exit(0);
}

int			check_name(char *name)
{   int		i;

	i = 0;
	if (ft_strcmp(name, "Mandelbrot") == 0)
		i = 1;
	else if (ft_strcmp(name, "Julia") == 0)
		i = 2;
	else if (ft_strcmp(name, "CelticMandelbrot") == 0)
		i = 3;
	else if (ft_strcmp(name, "Burningship") == 0)
		i = 4;
	else
		terminate(ERR_FRACTAL_NAME);
	return (i);
}

void		get_formula(t_fractol *fractol)
{
	if (fractol->name_index == 1)
		fractol->formula = &iterate_mandelbrot;
	else if (fractol->name_index == 2)
		fractol->formula = &iterate_mandelbar;
	else if (fractol->name_index == 3)
		fractol->formula = iterate_celtic_mandelbrot;
	else if (fractol->name_index == 4)
		fractol->formula = &iterate_julia;
	else
		terminate(ERR_FRACTAL_NAME);
}
