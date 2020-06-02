#ifndef FDF_H
# define FDF_H

#include "./libft/libft.h"
# include <string.h>
# include <math.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>

# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define RED 0x00EE0000
# define BLUE 0x000000EE
# define GREEN 0x0000EE00
# define PURPLE 0x00EE00EE
# define YELLOW 0x0000EEDD

typedef struct s_counters
{
    int     i;
    int     j;
    int     k;
}              t_counters;

typedef	struct	s_coords
{
	double		x;
	double		y;
	int			line;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	int			i;
	int			l;
	int			z;
	int			j;
	int			dy;
	int			move_x;
	int			move_y;
	int			startx;
	int			starty;
	int			dx;
	int			xincr;
	int			yincr;
	char		*filename;
	int			**tab;
	int			colour;
	void		*mlx;
	void		*win;
}				t_coords;

char			**read_map(char *filename);
int				num_lines(char *filename);
int				num_digits(char *line);
int				**convert(char **map, char *filename);
int		        ft_draw_map(t_coords *f);

#endif