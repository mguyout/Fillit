/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolveII.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 21:18:15 by mguyout           #+#    #+#             */
/*   Updated: 2016/12/16 19:59:14 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	erase(char ***map, t_struct *data, int x, int y)
{
	data->x = x;
	data->y = y;
	data->i--;
	get_tetris_info(map, data);
	put_tetris(map, data, '.');
}

void	get_tetris_info_core(t_struct *data, int j, int k)
{
	if (data->minx > k)
		data->minx = k;
	if (data->maxx < k)
		data->maxx = k;
	if (data->miny > j)
		data->miny = j;
	if (data->maxy < j)
		data->maxy = j;
}

void	get_tetris_info(char ***map, t_struct *data)
{
	int j;
	int k;

	data->minx = 3;
	data->maxx = 0;
	data->miny = 3;
	data->maxy = 0;
	j = -1;
	while (map[data->i][++j])
	{
		k = -1;
		while (map[data->i][j][++k])
			if (map[data->i][j][k] == '#')
				get_tetris_info_core(data, j, k);
	}
	data->height = data->maxy - data->miny + 1;
	data->width = data->maxx - data->minx + 1;
}
