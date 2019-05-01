/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epouros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 22:16:41 by epouros           #+#    #+#             */
/*   Updated: 2019/01/18 21:41:11 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft.h"
# include <stdio.h>
# define FAIL (-1)
# define OK (1)
# define FIG_SIZE (4)
# define CONTENT ((t_tetris*)lst->content)
# define COND (tmp[r][c] == '#')

typedef struct	s_tetris
{
	int		*x;
	int		*y;
	char	alpha;
}				t_tetris;

char			**ft_board_init(short size);
char			**ft_recursive_shit(t_list *lst, char ***board, int board_side);
int				ft_add_to_board(char ***board, t_tetris *t, short board_size,
								short p[2]);
void			ft_print_board(char **board, short board_size);
void			ft_undo_adding(char **board, short board_side, char a);
void			ft_fill_list_with_alpha(t_list *lst);
void			ft_usage(void);
void			ft_exit(void);
int				ft_valid_check(char tmp[FIG_SIZE + 1][FIG_SIZE + 1]);
void			ft_move_top_left(char tmp[FIG_SIZE + 1][FIG_SIZE + 1], int left,
				int top);
void			ft_move_top_left_if_possible(char
				tmp[FIG_SIZE + 1][FIG_SIZE + 1]);
t_tetris		*ft_new_tetris(void);
void			ft_move_left_minus(char tmp[FIG_SIZE + 1][FIG_SIZE + 1],
				t_tetris *t);
void			ft_fig_to_index(char tmp[FIG_SIZE + 1][FIG_SIZE + 1],
				t_tetris *tet);
int				ft_fig_to_list(char tmp[FIG_SIZE + 1][FIG_SIZE + 1],
				t_list **ft_head);
int				ft_newstrlen(char *line);
int				ft_read_file(int fd, t_list **ft_head);
int				ft_lst_count(t_list *lst);
int				ft_sqrt_round_up(int i);
void			ft_board_del(char ***board, short board_size);
int				hash_count(char tmp[FIG_SIZE + 1][FIG_SIZE + 1]);

#endif
