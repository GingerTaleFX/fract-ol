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
