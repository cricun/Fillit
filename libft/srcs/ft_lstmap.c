/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:00:39 by djon-con          #+#    #+#             */
/*   Updated: 2018/11/30 18:18:00 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*tmp;

	start = NULL;
	while (lst)
	{
		if (!(tmp = (void *)malloc(sizeof(t_list))))
		{
			ft_lstfree(&start);
			return (NULL);
		}
		tmp = f(lst);
		ft_push_back(&start, f(lst));
		lst = lst->next;
	}
	return (start);
}
