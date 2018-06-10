/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 15:55:23 by lucien            #+#    #+#             */
/*   Updated: 2018/06/10 15:52:37 by lucien           ###   ########.fr       */
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
		sort_selec_a(a, b, len);
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

void		sort_selec_a(t_push **a, t_push **b, int len)
{
	int		int_min;
	int		lenght;
	int		p_intmin;

	while ((*a) != NULL && ft_is_sort_increasing(*a) != 1)
	{
		if ((*a)->value == (int_min = get_min(a)))
			pb(a, b);
		else if ((p_intmin = get_position_int(a, int_min)) > len / 2)
			rra(a);
		else
			ra(a);
	}
	while ((lenght = get_len(a)) != len)
		pa(a, b);
}

void		sort_selec_b(t_push **a, t_push **b)
{
	int		int_max;

	while ((*b) != NULL && ft_is_sort_decreasing(*b) != 1)
	{
		if ((*b)->value == (int_max = get_max(b)))
			pa(a, b);
		else
			rb(b);
	}
	while ((*b) != NULL)
		pa(a, b);
}

void		quick_sort(t_push **a, t_push **b, int len)
{
	int		quartile;
	int		b_mediane;
	int		top_b;

	quartile = get_mediane(a, len / 4);
	send_to_b_low_int(a, b, len, quartile);
	b_mediane = get_mediane(b, (get_len(b) / 2));
	top_b = solve_quicksort(a, b, b_mediane);
	while (top_b > (*a)->value)
		pb(a, b);
	sort_selec_b(a, b);
}
