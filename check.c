/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:46:48 by mguyout           #+#    #+#             */
/*   Updated: 2016/12/15 22:10:26 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	check_bloc_core(char ***map, int *connection, int *bloc, int i)
{
	int j;
	int k;

	k = -1;
	j = -1;
	while (map[i][++j])
	{
		while (map[i][j][++k])
		{
			if (map[i][j][k] == '#')
			{
				if (k < 3 && map[i][j][k + 1] == '#')
					*connection = *connection + 1;
				if (k > 0 && map[i][j][k - 1] == '#')
					*connection = *connection + 1;
				if (j < 3 && map[i][j + 1][k] == '#')
					*connection = *connection + 1;
				if (j > 0 && map[i][j - 1][k] == '#')
					*connection = *connection + 1;
				*bloc = *bloc + 1;
			}
		}
		k = -1;
	}
}

char	***check_bloc(char *str, int i, int j, int k)
{
	char	***map;
	int		connection;
	int		tetri_bloc;

	tetri_bloc = 0;
	connection = 0;
	if (!(map = create_map(str, i, j, k)))
		return (0);
	while (map[i])
	{
		check_bloc_core(map, &connection, &tetri_bloc, i);
		if ((connection != 6 && connection != 8) || tetri_bloc != 4)
		{
			free_map(map);
			return (0);
		}
		connection = 0;
		tetri_bloc = 0;
		j = 0;
		i++;
	}
	return (map);
}

char	*ft_convert_string(int fd, char **argv)
{
	char	buf[1 + 1];
	char	*str;
	int		i;

	i = 0;
	if (fd <= 0)
		return (0);
	while (read(fd, buf, 1))
		i++;
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (read(fd, buf, 1))
		str[i++] = buf[0];
	str[i] = '\0';
	close(fd);
	return (str);
}

int		check_file(const char *str, int x, int y, int i)
{
	while (str[i])
	{
		if (y == 4)
		{
			if (str[i] == '\n' && str[i++])
				y = 0;
			else
				return (0);
		}
		while (y < 4 && str[i])
		{
			while (x++ < 4 && str[i])
			{
				if (str[i] != '.' && str[i] != '#')
					return (0);
				i++;
			}
			if (str[i] != '\n')
				return (0);
			i++;
			x = 0;
			y++;
		}
	}
	return (1);
}
