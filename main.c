/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 17:55:36 by djon-con          #+#    #+#             */
/*   Updated: 2019/01/14 16:02:47 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	int		o;
	int		tmp;
	t_list	*ft_head;
	char	**board;

	ft_head = NULL;
	if (argc != 2)
		ft_usage();
	if ((o = open(argv[1], O_RDONLY)) == -1)
		ft_exit();
	if (ft_read_file(o, &ft_head) == 0)
		ft_exit();
	tmp = ft_sqrt_round_up(ft_lstcount(ft_head) * 4);
	board = ft_board_init(tmp);
	ft_fill_list_with_alpha(ft_head);
	while (ft_recursive_shit(ft_head, &board, tmp) == NULL)
	{
		ft_board_del(&board, tmp);
		tmp++;
		board = ft_board_init(tmp);
	}
	ft_print_board(board, tmp);
	close(o);
	return (1);
}
