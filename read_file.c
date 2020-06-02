#include "fdf.h"

char	**ft_read(char *fname)
{
	int			fd;
	int			numlines;
	char		*line;
	char		**map;
	t_counters	counters;

	counters.k = 0;
	numlines = 0;
	fd = open(fname, O_RDONLY, 1);
	while (get_next_line(fd, &line))
		numlines++;
	map = (char **)malloc(sizeof(char *) * (numlines + 1));
	map[numlines] = 0;
	close(fd);
	fd = open(fname, O_RDONLY, 1);
	while (get_next_line(fd, &line))
	{
		counters.i = 0;
		map[counters.k] = (char *)malloc(sizeof(char *) * (ft_strlen(line) + 1));
		while (counters.i++ < numlines){
			map[counters.k] = line;
			map[counters.k][ft_strlen(line) + 1] = '\0';
		}
		counters.k++;
	}
	map[numlines] = NULL;
	close(fd);
	return (map);
}

int		count(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		**convert(char **map, char *filename)
{
	t_counters	counters;
	int			y;
	int			**tab;
	char		**arr;

	counters.k = 0;
	(void)filename;
	tab = (int **)malloc(sizeof(int *) * num_lines(filename));
	while (counters.k < num_lines(filename))
	{
		counters.i = 0;
		y = 0;
		counters.j = 0;
		arr = ft_strsplit(map[counters.k], ' ');
		counters.j = count(arr);
		tab[counters.k] = (int *)malloc(sizeof(int) * counters.j);
		while (counters.i < counters.j){
			tab[counters.k][counters.i] = ft_atoi(arr[counters.i]);
			counters.i++;
		}
		while (--counters.i >= 0)
			free(arr[counters.i--]);
		++counters.k;
	}
	return (tab);
}