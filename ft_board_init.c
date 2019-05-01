/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epouros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:00:28 by epouros           #+#    #+#             */
/*   Updated: 2019/01/02 12:59:27 by epouros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_board_init(short size)
{
	char	**board;
	short	i;
	short	j;

	i = 0;
	j = 0;
	if (!(board = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	while (i < size)
	{
		board[i] = ft_strnew(size);
		while (j < size)
		{
			board[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (board);
}
