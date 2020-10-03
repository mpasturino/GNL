/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasturi <mpasturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 17:50:20 by mpasturi          #+#    #+#             */
/*   Updated: 2020/10/03 18:04:50 by mpasturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

int	ft_srchline(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_readfile(int fd, int ret, char **buf)
{
	int		nbytes;
	char	*new;
	char	*tmp;

	if ((new = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))) == NULL)
		return (-1);
	if ((nbytes = read(fd, new, BUFFER_SIZE)) < 0)
	{
		new = ft_free(new);
		return (-1);
	}
	new[nbytes] = '\0';
	tmp = ft_strjoin(*buf, new);
	*buf = ft_free(*buf);
	*buf = tmp;
	ret = ft_srchline(*buf);
	if (new[0] == '\0')
		ret = 0;
	new = ft_free(new);
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static char		*buf[OPEN_MAX];
	int				i;
	char			*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	if (buf[fd] == NULL)
		if ((buf[fd] = ft_strdup("")) == NULL)
			return (-1);
	i = 1;
	while (i == 1)
		if ((i = ft_readfile(fd, i, &buf[fd])) == -1)
			return (-1);
	while (buf[fd][i] != '\n' && buf[fd][i] != '\0')
		i++;
	*line = ft_substr(buf[fd], 0, i);
	if (buf[fd][i] == '\0')
	{
		buf[fd] = ft_free(buf[fd]);
		return (0);
	}
	tmp = ft_substr(buf[fd], i + 1, (ft_strlen(buf[fd]) - i));
	buf[fd] = ft_free(buf[fd]);
	buf[fd] = tmp;
	return (1);
}
