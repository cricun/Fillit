/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_shit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:26:06 by djon-con          #+#    #+#             */
/*   Updated: 2019/01/14 16:03:13 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fill_list_with_alpha(t_list *lst)
{
	char	a;

	a = 'A';
	if (lst)
	{
		while (lst)
		{
			((t_tetris*)lst->content)->alpha = a++;
			if (a > 'Z')
				return ;
			lst = lst->next;
		}
	}
}

void	ft_undo_adding(char **board, short board_side, char a)
{
	short i;
	short j;

	i = -1;
	j = -1;
	while (++i < board_side)
	{
		while (++j < board_side)
		{
			if (board[i][j] == a)
				board[i][j] = '.';
		}
		j = -1;
	}
}

char	**ft_recursive_shit(t_list *lst, char ***board, int board_side)
{
	short p[2];

	p[0] = 0;
	p[1] = 0;
	if (p[1] < board_side && p[0] < board_side && lst)
	{
		while (p[1] < board_side)
		{
			while (p[0] < board_side)
			{
				if (ft_add_to_board(board, CONTENT, board_side, p))
					if (ft_recursive_shit(lst->next, board, board_side) != NULL)
						return (*board);
				ft_undo_adding(*board, board_side, CONTENT->alpha);
				p[0]++;
			}
			p[0] = 0;
			p[1]++;
		}
	}
	return ((!lst) ? (*board) : (NULL));
}
