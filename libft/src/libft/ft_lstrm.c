/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:26:27 by elebouch          #+#    #+#             */
/*   Updated: 2017/11/14 11:57:55 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrm(t_list **head, t_list *to_remove)
{
	t_list *list;
	t_list *prev;

	list = *head;
	prev = 0;
	if (!list)
		return ;
	while (list)
	{
		if (list == to_remove)
		{
			if (prev == 0)
				*head = (*head)->next;
			else
			{
				prev->next = list->next;
				free(list);
				list = prev;
			}
		}
		prev = list;
		list = list->next;
	}
}
