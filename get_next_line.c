/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasturi <mpasturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 19:42:13 by mpasturi          #+#    #+#             */
/*   Updated: 2020/05/25 16:52:08 by mpasturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     BUFFER_SIZE = 32;

int get_next_line(int fd, char **line)
{

    if (line == 0 || fd < 0 || BUFFER_SIZE == 0)
        return (-1);
    
}

