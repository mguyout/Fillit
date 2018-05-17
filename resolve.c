/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:12:05 by mguyout           #+#    #+#             */
/*   Updated: 2016/12/16 19:59:20 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_tetris(char ***map, t_struct *data, char c)
{
	int j;
	int k;

	k = -1;
	while (++k < data->width)
	{
		j = -1;
		while (++j < data->height)
			if (map[data->i][data->miny + j][data->minx + k] == '#')
				data->res[data->y + j][data->x + k] = c;
	}
}

int		check_slot(char ***map, t_struct *data, int x, int y)
{
	int j;
	int k;

	k = -1;
	while (++k < data->width)
	{
		j = -1;
		while (++j < data->height)
			if (map[data->i][data->miny + j][data->minx + k] == '#' &&
					data->res[data->y + j][data->x + k] != '.')
				return (0);
	}
	data->x = x;
	data->y = y;
	put_tetris(map, data, data->c + data->i);
	return (1);
}

int		solve(char ***map, t_struct *data, int i)
{
	int x;
	int y;

	y = -1;
	if (map[i] == NULL)
		return (1);
	data->i = i;
	get_tetris_info(map, data);
	while (++y < data->size - data->height + 1)
	{
		x = -1;
		while (++x < data->size - data->width + 1)
		{
			data->x = x;
			data->y = y;
			if (check_slot(map, data, x, y))
			{
				if (solve(map, data, i + 1))
					return (1);
				else
					erase(map, data, x, y);
			}
		}
	}
	return (0);
}

int		square_size(int bloc)
{
	int size;

	size = 2;
	while (size * size < bloc)
		size++;
	return (size);
}

void	resolve(char ***map, int i, int j)
{
	t_struct	*data;

	data = malloc(sizeof(*data));
	while (map[i])
		i++;
	data->size = square_size(i * 4);
	data->c = 'A';
	data->res = create_res(i, j, data->size);
	i = 0;
	while (!solve(map, data, i))
	{
		free_res(data->res);
		data->size = data->size + 1;
		data->res = create_res(i, j, data->size);
	}
	print_result(data->res, i);
	free_map(map);
	free_res(data->res);
	free(data);
}
