/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 23:38:10 by khou              #+#    #+#             */
/*   Updated: 2018/10/23 16:07:19 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define MAP_SIZE 5000

/*
** -------------------------- External Headers ---------------------------------
*/

# include "../libft/libft.h"

/*
** ------------------------- Structure Definition ------------------------------
*/
typedef struct	s_map
{
	char map[MAP_SIZE][MAP_SIZE];
	int row;
	int player;
}		t_map;

t_map g_map;

typedef struct  s_p
{
	char piece[MAP_SIZE][MAP_SIZE];
	int row;
	int row_id;
}				t_p;

t_p g_p;
	
#endif
