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

static int	clear(char *str, char **line)
{
	if (*str)
	{
		*line = ft_strdup(str);
		ft_strclr(str);
		return (1);
	}
	return (0);
}

static int	read_line(char **str, char **line)
{
	char	*temp;
	int		i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '\n')
		{
			temp = *str;
			*line = ft_strsub(*str, 0, i);
			*str = ft_strsub(*str, i + 1, ft_strlen(*str) - i);
			free(temp);
			return (1);
		}
		++i;
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char		*str;
	char			*s;
	char			buff[BUFF_SIZE + 1];
	int				ret;

	if (!str)
		str = ft_strnew(BUFF_SIZE);
	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (read_line(&str, line))
		return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		s = str;
		str = ft_strjoin(str, buff);
		free(s);
		if (read_line(&str, line))
			return (1);
	}
	if (clear(str, line))
		return (1);
	return (0);
}
