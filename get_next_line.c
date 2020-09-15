/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasturi <mpasturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 19:42:13 by mpasturi          #+#    #+#             */
/*   Updated: 2020/09/14 21:44:52 by mpasturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

#define BUFFER_SIZE 2

int ft_srchline( char *s)
{
    size_t  i;
    
    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

int ft_readfile(int fd, int ret, char **buf)
{
    int     nbytes;
    char    *new;
    char    *tmp;

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
        ret = 1;
    new = ft_free(new);
    return (ret);
}

int get_next_line(int fd, char **line)
{
    
    static char     *buf[OPEN_MAX];
    int             ret;
    int             i;
    char            *tmp;

    if  (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
        return (-1);
    if  (buf[fd] == NULL)
        if  ((buf[fd] = ft_strdup("")) == NULL)
            return (-1);
    ret = 0;
    while (ret == 0)
        if ((ret = ft_readfile(fd, ret, &buf[fd])) == -1)
            return (-1);
    i = 0;
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

