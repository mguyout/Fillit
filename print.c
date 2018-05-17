/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 18:06:34 by mguyout           #+#    #+#             */
/*   Updated: 2016/12/16 18:10:20 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	int i;

	i = -1;
	while (s[++i])
		ft_putchar(s[i]);
}

void	print_result(char **map, int i)
{
	i = -1;
	while (map[++i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
	}
}
