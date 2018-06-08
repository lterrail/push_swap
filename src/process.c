/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 15:55:23 by lucien            #+#    #+#             */
/*   Updated: 2018/06/08 19:26:19 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_mediane(t_push **a)
{
	t_push	*tmp;
	int		i;
	int		i_min;
	int		med;

	med = 0;
	tmp = (*a);
	i_min = 2147483647;
	while (tmp->next)
	{
		if (i_min > tmp->value)
			i_min = tmp->value;
		tmp = tmp->next;
		i++;
	}
	med = i_min;
	i = i / 2;
	while (i > 0)
	{
		tmp = (*a);
		i_min = 2147483647;
		while (tmp->next)
		{
			if (i_min > tmp->value && tmp->value > med)
				i_min = tmp->value;
			tmp = tmp->next;
		}
		med = i_min;
		i--;
	}
	return (med);
}

void		ft_process(t_push **listA, t_push **listB)
{
	int		med;
	int		i;

	med = get_mediane(listA);
	while (i < med)
	{
		if (listA->value < med)
		{
			pb(listB, listA);
			i++;
		}
		else
			ra(listA);
	}
}
