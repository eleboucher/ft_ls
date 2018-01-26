/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:40:03 by elebouch          #+#    #+#             */
/*   Updated: 2017/12/12 14:11:56 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strtolower(char *str)
{
	char *s;

	s = str;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
	return (s);
}