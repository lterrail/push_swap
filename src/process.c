/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 15:55:23 by lucien            #+#    #+#             */
/*   Updated: 2018/06/09 02:11:39 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_nb_total(t_push **a)
{
	t_push	*tmp;
	int		nb_int;
	int		int_min;

	nb_int = 0;
	int_min = 2147483647;
	tmp = (*a);
	while (tmp->next)
	{
		if (int_min > tmp->value)
			int_min = tmp->value;
		nb_int++;
		tmp = tmp->next;
	}
	(*a)->int_min = int_min;
	(*a)->nb_int = nb_int;
	return (nb_int);
}

int			get_mediane(t_push **a)
{
	t_push	*tmp;
	int		nb_int;
	int		int_min;
	int		mediane;

	mediane = 0;
	tmp = (*a);
	nb_int = (get_nb_total(&tmp) / 2);
	while (nb_int >= 0)
	{
		tmp = (*a);
		int_min = 2147483647;
		while (tmp->next)
		{
			if (int_min > tmp->value && tmp->value > mediane)
				int_min = tmp->value;
			tmp = tmp->next;
		}
		mediane = int_min;
		nb_int--;
	}
	return (mediane);
}

//printf("int_min = %d\n", int_min);
//printf("nb_int %d\n", ((*listA)->nb_int / 2));

void		ft_process(t_push **a, t_push **b)
{
	int		mediane;
	int		i;
	int		int_min;
	int		half;

	i = 0;
	mediane = get_mediane(a);
	int_min = (*a)->int_min;
	half = ((*a)->nb_int / 2);
	while (i < half) //probleme avec la mediane
	{
		if ((*a)->value == int_min)
		{
			opti_int_min(a, b);
			i++;
		}
		/*else if (((*a)->value <= mediane) && (*b) && ((*a)->value < (*b)->value))
		{
			pb(b, a);
			sb(b);
			i++;
		}*/
		else if ((*a)->value <= mediane)
		{
			pb(b, a);
			i++;
		}
		else
			ra(a);
	}
	if (ft_is_sort_increasing(*a) == 1 && ft_is_sort_decreasing(*b) == 1)
	{
		while((*b) != NULL)
			pa(a, b);
	}
}
