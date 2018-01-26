/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 16:40:20 by elebouch          #+#    #+#             */
/*   Updated: 2017/11/06 11:29:39 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *temp;

	list = *alst;
	if (!list)
		return ;
	while (list)
	{
		temp = list->next;
		ft_lstdelone(&list, del);
		list = temp;
	}
	*alst = NULL;
}
