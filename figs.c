/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:00:36 by djon-con          #+#    #+#             */
/*   Updated: 2019/01/18 21:34:24 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_init(int *c, int *r, int *count)
{
	*c = 0;
	*r = 0;
	*count = 0;
}

int			ft_valid_check(char tmp[FIG_SIZE + 1][FIG_SIZE + 1])
{
	int	c;
	int r;
	int count;

	ft_init(&c, &r, &count);
	while (r < 4)
	{
		while (c < 4)
		{
			(COND && r < 3 && tmp[r + 1][c] == '#') ? count++ : 0;
			(COND && c < 3 && tmp[r][c + 1] == '#') ? count++ : 0;
			if (COND && r == 0 && c == 0)
			{
				c++;
				continue ;
			}
			(COND && r > 0 && tmp[r - 1][c] == '#') ? count++ : 0;
			(COND && c > 0 && tmp[r][c - 1] == '#') ? count++ : 0;
			c++;
		}
		c = 0;
		r++;
	}
	if (hash_count(tmp) != 4)
		return (0);
	return (count == 6 || count == 8);
}

void		ft_move_top_left(char tmp[FIG_SIZE + 1][FIG_SIZE + 1],
							int left, int top)
{
	int		c;
	int		r;

	c = 0;
	r = 0;
	while (r < 4)
	{
		while (c < 4)
		{
			if (tmp[r][c] == '#')
			{
				tmp[r][c] = '.';
				tmp[r - top][c - left] = '#';
			}
			c++;
		}
		c = 0;
		r++;
	}
}

void		ft_move_top_left_if_possible(char tmp[FIG_SIZE + 1][FIG_SIZE + 1])
{
	int		c;
	int		r;
	int		left;
	int		top;

	c = 0;
	r = 0;
	left = 10;
	top = 10;
	while (r < 4)
	{
		while (c < 4)
		{
			if (tmp[r][c] == '#')
			{
				left = (c + r * 4) % 4 < left ? (c + r * 4) % 4 : left;
				top = (c + r * 4) / 4 < top ? (c + r * 4) / 4 : top;
			}
			c++;
		}
		c = 0;
		r++;
	}
	ft_move_top_left(tmp, left, top);
}

t_tetris	*ft_new_tetris(void)
{
	t_tetris *tmp;

	if (!(tmp = (t_tetris*)malloc(sizeof(t_tetris))))
		return (NULL);
	if (!(tmp->y = (int*)malloc(sizeof(int) * FIG_SIZE)))
		return (NULL);
	if (!(tmp->x = (int*)malloc(sizeof(int) * FIG_SIZE)))
		return (NULL);
	return (tmp);
}
