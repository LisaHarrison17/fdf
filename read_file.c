#include "fdf.h"

char	**read_map(char *filename)
{
	int		fd;
	char	*line;
	char	**map;
	int		k;

	k = 0;
	map = (char **)malloc(sizeof(char *) * 25);
	fd = open(filename, O_RDONLY, 1);
	while (get_next_line(fd, &line))
	{
		map[k] = line;
		map[k][ft_strlen(line)] = '\0';
		k++;
	}
	map[k] = NULL;
	close(fd);
	free(line);
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
	int		i;
	int		j;
	int		k;
	int		**tab;
	char	**arr;

	k = 0;
	(void)filename;
	tab = (int **)malloc(sizeof(int *) * count(map));
	while (k < count(map))
	{
		i = 0;
		arr = ft_strsplit(map[k], ' ');
		j = count(arr);
		tab[k] = (int *)malloc(sizeof(int) * j);
		while (i < j)
		{
			tab[k][i] = ft_atoi(arr[i]);
			free(arr[i]);
			i++;
		}
		free(arr);
		k++;
	}
	return (tab);
}