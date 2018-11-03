/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 23:39:54 by khou              #+#    #+#             */
/*   Updated: 2018/10/23 14:34:34 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../incl/filler.h"

void	store_map(char *line)
{
	int i = 0;
	
//	printf("I am here\n");
	while (*line)
		g_map.map[g_map.row][i++] = *line++;
	g_map.map[g_map.row][i] = '\0';
//	printf("%s\n", g_map.map[g_map.row]);
//	printf("I am here two\n");
	g_map.row++;
}

void	is_myplayer(char *line)
{
	if (line[10] == '1')
	{
		g_map.player = 1;
		printf("I m player ONE! o O\n");
	}
	else
	{
		g_map.player = 2;
		printf("I m player TWO! x X\n");
	}
}

void	store_p(char *line)
{
	int i = 0;
	while (*line)
        g_p.piece[g_p.row_id][i++] = *line++;
    g_p.piece[g_p.row_id][i] = '\0';
	g_p.row_id++;
}

int main(){
	char *line;
	int n = 0;
	while (get_next_line(0, &line))//read line by line
	{
//		printf("%s\n", line);
		if (ft_strstr(line, "khou.filler"))
			is_myplayer(line);
//			printf("found my filler\n");
		else if (ft_strstr(line, "Plateau"))
			printf("found board line\n");
		else if (ft_isdigit((int)line[0]))
			store_map(line + 4);
		else if (ft_strstr(line, "Piece"))
		{
			g_p.row = ft_atoi(&line[6]);
			printf("number of rows are going to be read: %d\n", g_p.row);
		}
		else if (g_p.row > 0 && n++ < g_p.row)
			store_p(line);
//			printf("%s\n", line);
		else //do nothing
			;
	}

	
//	printf("g_p.row_id: %d\n", g_p.row_id);
//print map and piece that were stored

	int i = 0;
	while (i < g_map.row)
 	printf("%s\n", g_map.map[i++]);
	i = 0;
	while ( i < g_p.row_id)
		printf("piece: %s\n", g_p.piece[i++]);
}
