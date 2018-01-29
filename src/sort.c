/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:57:53 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/29 09:45:25 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_mergesort(t_file **file)
{
	t_file *head;
	t_file *a;
	t_file *b;

	head = *file;
	if (!head || !head->next)
		return ;
	split(head, &a, &b);
	ft_mergesort(&a);
	ft_mergesort(&b);
	*file = sorted(a, b);
}

void split (t_file *src, t_file **front, t_file **back)
{
	t_file *fast;
	t_file *slow;

	slow = NULL;
	fast = NULL;
	if (!src || !src->next)
	{
		*front = src;
		*back = NULL;
	}
	else
	{
		slow = src;
		fast = src->next;
		while (fast && fast->next)
		{
			fast = (fast->next)? fast->next->next : fast->next;
			slow = slow->next;
		}
	}
	*front = src;
	*back = slow->next;
	slow->next = NULL;
}

t_file *sorted(t_file *a, t_file *b)
{
	t_file *ret;

	ret = NULL;
	if (!a)
		return(b);
	else if (!b)
		return (a);
	if (ft_strcmp(a->file_name, b->file_name) < 0)
	{
		ret = a;
		ret->next = sorted(a->next, b);
	}
	else
	{
		ret = b;
		ret->next = sorted(a, b->next);
	}
	return (ret);
}
