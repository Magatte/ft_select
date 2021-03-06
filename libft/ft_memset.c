/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 18:13:02 by pba               #+#    #+#             */
/*   Updated: 2015/10/04 15:02:45 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	char *my_b;

	my_b = b;
	if (my_b)
	{
		while (len--)
		{
			*my_b = (unsigned char)c;
			++my_b;
		}
	}
	return (b);
}
