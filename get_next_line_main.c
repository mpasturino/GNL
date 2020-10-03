/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasturi <mpasturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 17:52:14 by mpasturi          #+#    #+#             */
/*   Updated: 2020/10/03 18:04:52 by mpasturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main()
{
	int		txt1;
	int		txt2;
	char	*line;

	txt1 = open("texto1", O_RDONLY);
	txt2 = open("texto2", O_RDONLY);
	printf("Rodada 1: Txt1 lin1\n");
	printf("Retorno %d\n", get_next_line(txt1, &line));
	printf("linha encontrada: %s\n", line);
	printf("\n");
	free(line);
	printf("Rodada 2: Txt1 Lin2\n");
	printf("Retorno %d\n", get_next_line(txt1, &line));
	printf("linha encontrada: %s\n", line);
	printf("\n");
	free(line);
	printf("Rodada 3: Txt2 Lin1\n");
	printf("Retorno %d\n", get_next_line(txt2, &line));
	printf("linha encontrada: %s\n", line);
	printf("\n");
	free(line);
	printf("Rodada 4:Txt1 Lin3\n");
	printf("Retorno %d\n", get_next_line(txt1, &line));
	printf("linha encontrada: %s\n", line);
	printf("\n");
	free(line);
	printf("Rodada 5:Txt1 Lin4\n");
	printf("Retorno %d\n", get_next_line(txt1, &line));
	printf("linha encontrada: %s\n", line);
	printf("\n");
	free(line);
	printf("Rodada 6:Txt2 Lin2\n");
	printf("Retorno %d\n", get_next_line(txt2, &line));
	printf("linha encontrada: %s\n", line);
	printf("\n");
	free(line);
	printf("Rodada 7:Txt2 Lin3\n");
	printf("Retorno %d\n", get_next_line(txt2, &line));
	printf("linha encontrada: %s\n", line);
	printf("\n");
	free(line);
	printf("Rodada 8:Txt2 Lin4\n");
	printf("Retorno %d\n", get_next_line(txt2, &line));
	printf("linha encontrada: %s\n", line);
	printf("\n");
	free(line);
	return (0);
}
