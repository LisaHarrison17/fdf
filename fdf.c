#include "fdf.h"

int		close(int key)
{
	if (key == 53)
		exit(1);
	return (0);
}

int		num_digits(char *line)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			len++;
		i++;
	}
	return (len);
}

int		num_lines(char *filename)
{
	int		fd;
	int		numlines;
	char	*line;

	numlines = 0;
	fd = open(filename, O_RDONLY, 1);
	while (get_next_line(fd, &line))
		numlines++;
	free(line);
	close(fd);
	return (numlines);
}

void	ft_init(t_coords *map, char *filename)
{
	map->move_x = 0;
	map->move_y = 0;
	map->z = 2.0;
	map->startx = 200;
	map->starty = 800;
	map->colour = WHITE;
	map->filename = filename;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, 1000, 1000, "fdf");
}

int		main(int argc, char **argv)
{
	int			nbl;
	int			nbi;
	char		**arr;
	t_coords	*map;

	if (argc == 2)
	{
		map = (t_coords *)malloc(sizeof(t_coords));
		arr = ft_read(argv[1]);
		map->tab = convert(arr, argv[1]);
		ft_init(map, argv[1]);
		nbi = num_digits(arr[0]);
		nbl = num_lines(argv[1]);
		map->l = nbl;
		map->i = nbi;
		if (map->l >= map->i)
			map->zoom = 500 / map->l;
		else
			map->zoom = 500 / map->i;
		ft_draw_map(map);
		mlx_key_hook(map->win, close, 0);
		mlx_loop(map->mlx);
	}
	return (0);
}