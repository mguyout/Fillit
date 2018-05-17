/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 20:27:26 by mguyout           #+#    #+#             */
/*   Updated: 2016/12/16 19:05:45 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_res(char **res)
{
	int i;

	i = -1;
	while (res[++i])
		free(res[i]);
}

char	**create_res(int i, int j, int size)
{
	char **res;

	i = -1;
	j = -1;
	res = (char**)malloc(sizeof(char*) * (size + 1));
	while (++i < size + 1)
		res[i] = (char*)malloc(sizeof(char) * (size + 1));
	i = -1;
	while (++i < size)
	{
		while (++j < size)
			res[i][j] = '.';
		res[i][j] = '\0';
		j = -1;
	}
	res[i] = NULL;
	return (res);
}

void	free_map(char ***map)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
			free(map[i][j]);
		j = -1;
		free(map[i]);
	}
}

char	***init_map(int i, int j, char *str)
{
	char	***map;
	int		size_fd;

	size_fd = 1;
	while (str[++i])
		if (str[i] == '\n' && str[i + 1] == '\n')
			size_fd++;
	if (size_fd > 26)
		return (0);
	map = (char***)malloc(sizeof(char**) * (size_fd + 1));
	i = -1;
	while (++i < size_fd)
		map[i] = (char**)malloc(sizeof(char*) * 5);
	map[i] = NULL;
	i = -1;
	while (++i < size_fd)
	{
		while (++j < 4)
			map[i][j] = (char*)malloc(sizeof(char) * 5);
		j = -1;
	}
	return (map);
}

char	***create_map(char *str, int i, int j, int k)
{
	int		z;
	char	***map;

	i = -1;
	j = -1;
	k = -1;
	z = -1;
	if (!(map = init_map(i, j, str)))
		return (0);
	while (map[++i])
	{
		while (++j < 4)
		{
			while (++k < 4)
				map[i][j][k] = str[++z];
			z++;
			map[i][j][k] = '\0';
			k = -1;
		}
		map[i][j] = NULL;
		j = -1;
		z++;
	}
	free(str);
	return (map);
}
