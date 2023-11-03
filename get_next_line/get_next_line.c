/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nben-ais <nben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:22:02 by nben-ais          #+#    #+#             */
/*   Updated: 2023/01/21 11:41:22 by nben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	if (ft_strchr(str, '\n') != NULL)
	{
		while (str[j] != '\n')
			j++;
		s = (char *)malloc(sizeof(char) * j + 2);
		if (s == NULL)
			return (NULL);
		while (str[i] != '\n')
		{
			s[i] = str[i];
			i++;
		}
		s[i++] = '\n';
		s[i] = '\0';
		return (s);
	}
	return (ft_strdup(str));
}

char	*ft_rest(char *str, char *line)
{
	char	*s;

	s = ft_strdup(str + ft_strlen(line));
	free (str);
	return (s);
}

char	*ft_read(char *stock, char *str, int fd, ssize_t r)
{
	r = read(fd, str, BUFFER_SIZE);
	if (r < 0)
	{
		free (str);
		free (stock);
		stock = NULL;
		return (NULL);
	}
	str[r] = '\0';
	stock = ft_strjoin(stock, str);
	while (ft_strchr(stock, '\n') == NULL && r)
	{
		r = read(fd, str, BUFFER_SIZE);
		str[r] = '\0';
		stock = ft_strjoin(stock, str);
	}
	free (str);
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*str;
	char		*line;
	ssize_t		r;

	r = 0;
	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (str == NULL || BUFFER_SIZE <= 0 || fd < 0)
	{
		free (str);
		return (NULL);
	}
	stock = ft_read(stock, str, fd, r);
	if (!stock || stock[0] == '\0')
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}
	line = ft_line(stock);
	stock = ft_rest(stock, line);
	return (line);
}
