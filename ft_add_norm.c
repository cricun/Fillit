/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epouros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 12:02:10 by epouros           #+#    #+#             */
/*   Updated: 2019/01/14 16:24:37 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_board(char **board, short board_size)
{
	short i;

	i = 0;
	while (i < board_size)
	{
		ft_putstr(board[i++]);
		write(1, "\n", 1);
	}
}

int		ft_add_to_board(char ***bd, t_tetris *t, short bd_s, short p[2])
{
	short i;

	i = -1;
	while (++i < FIG_SIZE)
	{
		if ((t->y)[i] + p[1] >= bd_s || (t->x)[i] + p[0] >= bd_s ||
				(t->y)[i] + p[1] < 0 || (t->x)[i] + p[0] < 0
				|| (*bd)[(t->y)[i] + p[1]][(t->x)[i] + p[0]] != '.')
			return (0);
	}
	i = -1;
	while (++i < FIG_SIZE)
		(*bd)[(t->y)[i] + p[1]][(t->x)[i] + p[0]] = t->alpha;
	return (1);
}
