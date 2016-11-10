/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 00:02:06 by pba               #+#    #+#             */
/*   Updated: 2015/04/29 10:06:15 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char *s2;

	s2 = (char *)malloc(ft_strlen(s1) * sizeof(*s2) + 1);
	if (s1 != NULL)
	{
		if (s2 != NULL)
			ft_strcpy(s2, s1);
	}
	return (s2);
}
