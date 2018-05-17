/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:39:18 by mguyout           #+#    #+#             */
/*   Updated: 2016/12/16 19:21:09 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	***map;
	char	*check;
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	if (argc != 2)
	{
		ft_putstr("usage: fillit map_file\n");
		return (1);
	}
	if (!(check = ft_convert_string(open(argv[1], O_RDONLY), argv))
		|| !(check_file(check, x, y, i)) || !(map = check_bloc(check, x, y, i)))
	{
		ft_putstr("error\n");
		return (1);
	}
	resolve(map, i, x);
	return (0);
}
