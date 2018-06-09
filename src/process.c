/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 15:55:23 by lucien            #+#    #+#             */
/*   Updated: 2018/06/10 01:16:30 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_process(t_push **a, t_push **b)
{
	int		int_min;
	int		int_max;
	int		len;

	int_min = get_min(a);
	int_max = get_max(a);
	len = get_len(a);
	if (len < SMALL_SIZE)
		sort_3less_int(a, len, int_min, int_max);
	else if (len < MEDIUM_SIZE)
		sort_20less_int(a, b, len);
	else
		quick_sort(a, b, len);
}

void		sort_3less_int(t_push **a, int len, int int_min, int int_max)
{
	if (len == 2 && (*a)->value == int_max)
		sa(a);
	else if (len == 3)
	{
		if ((*a)->value == int_max && (*a)->next->value != int_min)
		{
			ra(a);
			sa(a);
		}
		else if ((*a)->value == int_max && (*a)->next->value == int_min)
			ra(a);
		else if ((*a)->value == int_min && (*a)->next->value == int_max)
		{
			rra(a);
			sa(a);
		}
		else if ((*a)->next->value == int_max)
			rra(a);
		else if ((*a)->next->value == int_min)
			sa(a);
	}
}

void		sort_20less_int(t_push **a, t_push **b, int len)
{
	int		int_min;
	int		lenght;

	while ((*a) != NULL && ft_is_sort_increasing(*a) != 1)
	{
		if ((*a)->value == (int_min = get_min(a)))
			pb(a, b);
		else
			ra(a);
	}
	while ((lenght = get_len(a)) != len)
		pa(a, b);
}

void		quick_sort(t_push **a, t_push **b, int len)
{
	int		quartile;

	quartile = get_mediane(a, len / 4);
	split_mediane(a, b, len, quartile);

}
