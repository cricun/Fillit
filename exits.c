/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 18:03:19 by djon-con          #+#    #+#             */
/*   Updated: 2019/01/18 21:32:44 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_usage(void)
{
	ft_putstr_fd("usage: fillit source_file\n", 2);
	exit(3);
}

void		ft_exit(void)
{
	ft_putstr("error\n");
	exit(3);
}

void		ft_board_del(char ***board, short board_size)
{
	short i;

	i = 0;
	while (i < board_size)
	{
		free((*board)[i]);
		i++;
	}
	free(*board);
	*board = NULL;
}

int			ft_sqrt_round_up(int i)
{
	int a;

	a = 0;
	while (a * a < i)
		a++;
	return (a);
}

int			ft_newstrlen(char *line)
{
	int i;
	
	i = 0;
	while (i < 4)
	{
		if (line[i] != '#' && line[i] != '.')
			return (0);
		i++;
	}
	if (line[i] != '\n')
		return (0);
	return (i);
}
