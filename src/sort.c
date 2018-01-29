/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:57:53 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/29 17:34:21 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ascii_sort(t_file *a, t_file *b)
{
	return (ft_strcmp(a->file_name, b->file_name));
}

static int	time_sort(t_file *a, t_file *b)
{
	if (a->stat.st_mtimespec.tv_sec == b->stat.st_mtimespec.tv_sec)
		return (ft_strcmp(a->file_name, b->file_name));
	if (a->stat.st_mtimespec.tv_sec > b->stat.st_mtimespec.tv_sec)
		return (-1);
	return (1);
}

void ft_mergesort(t_file **file, t_ls *data)
{
	t_file *head;
	t_file *a;
	t_file *b;

	head = *file;
	if (!head || !head->next)
		return ;
	split(head, &a, &b);
	ft_mergesort(&a, data);
	ft_mergesort(&b, data);
	if (!data->fg_t)
		*file = sorted(a, b, &ascii_sort);
	else
		*file = sorted(a, b, &time_sort);
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

t_file *sorted(t_file *a, t_file *b,int (*f)(t_file *a, t_file *b))
{
	t_file *ret;

	ret = NULL;
	if (!a)
		return(b);
	else if (!b)
		return (a);
	if ((*f)(a, b) < 0)
	{
		ret = a;
		ret->next = sorted(a->next, b, f);
	}
	else
	{
		ret = b;
		ret->next = sorted(a, b->next, f);
	}
	return (ret);
}
