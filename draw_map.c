#include "fdf.h"

void	ft_draw_line(t_coords *f)
{
	double		tx;
	double		dx;
	double		dy;

	tx = 0;
	dx = f->x2 - f->x1;
	dy = f->y2 - f->y1;
	while (tx <= 1)
	{
		f->x = f->x1 + (dx * tx);
		f->y = f->y1 + (dy * tx);
		mlx_pixel_put(f->mlx, f->win, f->x + f->move_x,
				f->y + f->move_y, f->colour);
		tx += 1 / sqrt((dx * dx) + (dy * dy));
	}
}

void	draw_vert(t_coords *f, int j, int i)
{
	f->x1 = f->startx + (i * f->zoom) + (j * f->zoom);
	f->x2 = f->startx + (i * f->zoom) + ((j + 1) * f->zoom);
	f->y1 = ((f->starty + (j * f->zoom)) * 1 / 2) - (((i * f->zoom)
				+ (f->z * f->tab[j][i])) * 1 / 2);
	f->y2 = ((f->starty + ((j + 1) * f->zoom)) * 1 / 2) - (((i * f->zoom)
				+ (f->z * f->tab[j + 1][i])) * 1 / 2);
	ft_draw_line(f);
}

void	draw_horiz(t_coords *f, int j, int i)
{
	f->x1 = f->startx + (i * f->zoom) + (j * f->zoom);
	f->x2 = f->startx + (((i + 1) * f->zoom) + (j * f->zoom));
	f->y1 = ((f->starty + (j * f->zoom)) * 1 / 2) - (((i * f->zoom)
				+ (f->z * f->tab[j][i])) * 1 / 2);
	f->y2 = ((f->starty + (j * f->zoom)) * 1 / 2) - ((((i + 1) * f->zoom)
				+ (f->z * f->tab[j][i + 1])) * 1 / 2);
	ft_draw_line(f);
}

int		ft_draw_map(t_coords *f)
{
	int			i;
	int			j;

	j = 0;
	while (j < f->l)
	{
		i = 0;
		while (i < f->i - 1)
			draw_horiz(f, j, i++);
		j++;
	}
	j = 0;
	while (j < f->l - 1)
	{
		i = 0;
		while (i < f->i)
			draw_vert(f, j, i++);
		j++;
	}
	return (0);
}