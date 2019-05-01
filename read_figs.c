/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_figs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 17:56:41 by djon-con          #+#    #+#             */
/*   Updated: 2019/01/18 21:33:12 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_move_left_minus(char tmp[FIG_SIZE + 1][FIG_SIZE + 1],
			t_tetris *t)
{
	short i;
	short a;

	i = 0;
	a = -1;
	while (tmp[0][i] != '#')
		i++;
	while (++a < FIG_SIZE)
		t->x[a] -= i;
}

void		ft_fig_to_index(char tmp[FIG_SIZE + 1][FIG_SIZE + 1], t_tetris *tet)
{
	int			c;
	int			r;
	int			k;

	c = 0;
	r = 0;
	k = 0;
	while (r < FIG_SIZE + 1)
	{
		while (c < FIG_SIZE + 1)
		{
			if (tmp[r][c] == '#')
			{
				tet->x[k] = c;
				tet->y[k] = r;
				k++;
			}
			c++;
		}
		c = 0;
		r++;
	}
}

int			ft_fig_to_list(char tmp[FIG_SIZE + 1][FIG_SIZE + 1],
			t_list **ft_head)
{
	t_tetris	*tet;
	t_list		*lst;

	if (!(tet = ft_new_tetris()))
		ft_exit();
	ft_move_top_left_if_possible(tmp);
	ft_fig_to_index(tmp, tet);
	if (!(lst = ft_lstnew(NULL, 1)))
		ft_exit();
	lst->content = tet;
	ft_push_back(ft_head, lst);
	ft_move_left_minus(tmp, tet);
	return (1);
}

int			ft_read_tetr(char tmp[FIG_SIZE + 1][FIG_SIZE + 1], int fd)
{
	int row;
	int k;

	row = 0;
	k = 1;
	while (row < 4)
	{
		k = read(fd, tmp[row], FIG_SIZE + 1);
		if (/*tmp[row][0] == '\n' ||*/k != 5 || ft_newstrlen(tmp[row]) != 4)
			ft_exit();
		row++;
	}
	return (1);
}

int			ft_read_file(int fd, t_list **ft_head)
{
	char	tmp[FIG_SIZE + 1][FIG_SIZE + 1];
	int		row;
	int		k;
	char	tmp_ch;

	row = 0;
	k = 1;
	while (k != 0)
	{
		row = ft_read_tetr(tmp, fd);
		k = read(fd, &tmp_ch, 1);
		if (row > 0)
		{
			if (k == -1 || ft_valid_check(tmp) == 0)
				return (0);
			ft_fig_to_list(tmp, ft_head);
		}
		row = 0;
		if (k != 0 && tmp_ch != '\n')
			ft_exit();
	}
	return (1);
}
