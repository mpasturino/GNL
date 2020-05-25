/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasturi <mpasturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 16:04:15 by mpasturi          #+#    #+#             */
/*   Updated: 2020/05/25 16:52:08 by mpasturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

#include "get_next_line.h"
#include "get_next_line.c"

int     main()
{
    int     fd;
    char    buf[400];
    char    **line[4000];
    
    fd = open("texto_1.rft", O_RDONLY);
    if (fd == -1)
    {
        exit(1);
    }
    get_next_line(fd, **line);

}