/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 00:12:58 by lucien            #+#    #+#             */
/*   Updated: 2018/06/10 15:52:28 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		send_to_b_low_int(t_push **a, t_push **b, int len, int quartile)
{
	int		mediane;
	int		half;

	half = len / 2 + 1;
	mediane = get_mediane(a, half);
	while ((*a) && get_len(a) != half)
	{
		if ((*a)->value < mediane)
		{
			pb(a, b);
		}
		else if ((*b) && (*b)->value < quartile)
			rr(a, b);
		else
			ra(a);
	}
	if (get_len(a) < MEDIUM_SIZE)
		sort_selec_a(a, b, get_len(a));
	else
		send_to_b_low_int(a, b, get_len(a), quartile);
}

static void	save_newintmax_in_top_a(t_push **a, t_push **b, int top_b)
{
	while (top_b > (*a)->next->value)
	{
		sa(a);
		pb(a, b);
	}
}

int			solve_quicksort(t_push **a, t_push **b, int mediane)
{
	int		max;
	int		half;
	int		top_b;

	half = get_len(b) / 6 * 5 + 1;
	top_b = (*b)->value;
	while (get_len(b) > MEDIUM_SIZE)
	{
		if (get_len(b) <= half)
			solve_quicksort(a, b, (mediane =
										get_mediane(b, (get_len(b) / 2))));
		if ((*b)->value > mediane && (*b)->value == (max = get_max(b)))
		{
			pa(a, b);
			top_b = (*a)->value;
			save_newintmax_in_top_a(a, b, top_b);
		}
		else if ((*b)->value > mediane && (*b)->value != (max = get_max(b)))
		{
			pa(a, b);
		}
		else if ((*b)->value <= mediane)
			rb(b);
	}
	return (top_b);
}
