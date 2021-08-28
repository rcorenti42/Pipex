/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:25:40 by rcorenti          #+#    #+#             */
/*   Updated: 2020/01/18 21:50:02 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_linejoin(char **s1, char **s2, int i)
{
	char	*str;
	size_t	len;

	if (*s1 && *s2)
	{
		len = ft_strlen(*s1) + ft_strlen(*s2);
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (str)
		{
			ft_memcpy(str, *s1, ft_strlen(*s1));
			ft_memcpy(str + ft_strlen(*s1), *s2, ft_strlen(*s2));
			str[len] = '\0';
		}
	}
	else
		str = *s1 ? ft_strndup(*s1, ft_strlen(*s1)) : ft_strndup(*s2, ft_strlen(*s2));
	free(*s1);
	*s1 = NULL;
	if (i == 2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (str);
}

static int		get_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int		get_line(char **ptr, char **line)
{
	char	*tmp;
	int		size;
	int		result;

	result = 0;
	tmp = NULL;
	if (!*ptr)
		return (result);
	size = get_newline(*ptr);
	if (**ptr != '\0')
	{
		result = 1;
		if (size == -1)
			*line = ft_linejoin(line, ptr, 2);
		else
		{
			tmp = ft_strndup(*ptr, size);
			*line = ft_linejoin(line, &tmp, 2);
			tmp = ft_strndup(*ptr + size + 1, ft_strlen(*ptr + size + 1));
		}
	}
	free(*ptr);
	*ptr = tmp;
	return (result);
}

static int		read_line(int fd, char **ptr, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	char	*ptr_buff;
	char	*str;
	int		size;

	str = *ptr;
	ft_memset(buff, 0, BUFFER_SIZE + 1);
	while ((size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[BUFFER_SIZE] = '\0';
		ptr_buff = buff;
		*ptr = ft_linejoin(ptr, &ptr_buff, 1);
		ft_memset(buff, 0, BUFFER_SIZE + 1);
		if (get_newline(*ptr) != -1)
			break;
	}
	if (size == 0 && (!str || *str == '\0'))
	{
		get_line(ptr, line);
		free(*ptr);
		return (0);
	}
	return ((size != -1 && *ptr) ? get_line(ptr, line) : size);
}

int				get_next_line(int fd, char **line)
{
	static char	*ptr;
	int			result;

	result = -1;
	if (fd >= 0 && BUFFER_SIZE > 0)
	{
		*line = ft_strndup("", 0);
		result = get_line(&ptr, line);
		if (!ptr || !*line)
			result = read_line(fd, &ptr, line);
	}
	return (result);
}
