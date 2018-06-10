/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 00:12:58 by lucien            #+#    #+#             */
/*   Updated: 2018/06/10 19:07:49 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		send_to_b_low_int(t_push **a, t_push **b, int len, int quartile)
{
	int		mediane;
	int		half;

	half = len / 2 + 1;
	mediane = get_mediane(a, half);
	while ((*a) && get_len(a) >= half + 1)
	{
		if ((*a)->value < mediane)
			pb(a, b);
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

int			solve_quicksort(t_push **a, t_push **b, int mediane)
{
	int		max;
	int		half;
	int		max_b;
	int		p_intmax;

	half = get_len(b) / 6 * 5 + 1;
	max_b = (*b)->value;
	while (get_len(b) > MEDIUM_SIZE)
	{
		if (get_len(b) <= half)
			solve_quicksort(a, b, (mediane =
										get_mediane(b, (get_len(b) / 6 * 5))));
		if ((*b)->value > mediane && (*b)->value == (max = get_max(b)))
			max_b = save_newintmax_in_top_a(a, b);
		else if ((*b)->value > mediane && (*b)->value != (max = get_max(b)))
			pa(a, b);
		else if ((p_intmax = get_position_int(b, get_max(b))) > get_len(b) / 2)
			rrb(b);
		else
			rb(b);
	}
	return (max_b);
}
