/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:12:14 by lharris           #+#    #+#             */
/*   Updated: 2018/08/13 12:16:26 by lharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			check_line(char **stack, char **line)
{
	char			*tmp;
	char			*str;
	int				i;

	i = 0;
	str = *stack;
	while (str[i] != '\n')
		if (!str[i++])
			return (0);
	tmp = &str[i];
	*tmp = '\0';
	*line = ft_strdup(*stack);
	*stack = ft_strdup(tmp + 1);
	free(str);
	return (1);
}

static	int			read_file(int fd, char *heap, char **stack, char **line)
{
	int				ret;
	char			*tmp;

	while ((ret = read(fd, heap, BUFF_SIZE)) > 0)
	{
		heap[ret] = '\0';
		if (*stack)
		{
			tmp = *stack;
			*stack = ft_strjoin(tmp, heap);
			free(tmp);
			tmp = NULL;
		}
		else
			*stack = ft_strdup(heap);
		if (check_line(stack, line))
			break ;
	}
	if(ret > 0)
		return (1);
	else
		return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static char		*stack[MAX_FD];
	char			*heap;
	int				ret;
	int				i;

	if (!line || (fd < 0 || fd >= MAX_FD) || (read(fd, stack[fd], 0) < 0) \
		|| !(heap = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	if (stack[fd])
		if (check_line(&stack[fd], line))
			return (1);
	i = 0;
	while (i < BUFF_SIZE)
		heap[i++] = '\0';
	ret = read_file(fd, heap, &stack[fd], line);
	free(heap);
	if (ret != 0 || stack[fd] == NULL || stack[fd][0] == '\0')
	{
		if (!ret && *line)
			*line = NULL;
		return (ret);
	}
	*line = stack[fd];
	stack[fd] = NULL;
	return (1);
}