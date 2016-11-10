/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_block_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 09:35:26 by pba               #+#    #+#             */
/*   Updated: 2015/10/07 09:00:51 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int			*cumulate(int *arr, int len)
{
	int				i;

	arr[0] = arr[0] + 5;
	i = 1;
	while (i < len)
	{
		arr[i] += arr[i - 1] + 5;
		i++;
	}
	return (arr);
}

static int			*tabmax_fill(int *arr, t_dlist *list, size_t block_len)
{
	size_t			tmp_len;
	t_dcell			*tmp;
	int				i;

	i = 0;
	tmp = list->head;
	arr[i] = ft_strlen((char *)tmp->data);
	tmp = tmp->next;
	tmp_len = 2;
	while (tmp != list->head)
	{
		while (tmp_len < block_len && tmp != list->head)
		{
			if ((int)(ft_strlen((char *)tmp->data)) > arr[i])
				arr[i] = ft_strlen((char *)tmp->data);
			tmp = tmp->next;
			tmp_len++;
		}
		tmp_len = 1;
		i++;
	}
	return (cumulate(arr, i));
}

int					*dlist_block_max(t_dlist *list, int block_len)
{
	int				block_nb;
	int				*arr;

	arr = NULL;
	if (block_len - 1 == 1)
		block_nb = (int)list->len;
	else
		block_nb = (list->len + block_len - 1) / block_len;
	if ((arr = (int *)malloc(sizeof(int) * block_nb)) == NULL)
		return (NULL);
	return (tabmax_fill(arr, list, block_len));
}
