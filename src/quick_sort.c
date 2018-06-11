/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 00:12:58 by lucien            #+#    #+#             */
/*   Updated: 2018/06/11 17:14:55 by lterrail         ###   ########.fr       */
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
		if ((*a)->value < mediane && (*a)->value < quartile)
		{
			pb(a, b);
			rb(b);
		}
		else if ((*a)->value < mediane)
			pb(a, b);
		else
			ra(a);
	}
	if (get_len(a) < MEDIUM_SIZE)
		sort_selec_a(a, b, get_len(a));
	else
		send_to_b_low_int(a, b, get_len(a), quartile);
}

void		solve_quicksort(t_push **a, t_push **b)
{
	int		max;
	int		max2;
	int		dixieme;
	int		p_intmax;
	int		mediane;

	dixieme = get_len(b) / 10 * 9;
	mediane = get_mediane(b, dixieme);
	while (get_len(b) > MEDIUM_SIZE)
	{
		if (get_len(b) <= dixieme + 1)
			solve_quicksort(a, b);
		if ((*b)->value == (max = get_max(b)))
			pa(a, b);
		else if ((*b)->value == (max2 = get_max_moins_un(b, max)))
			place_max_moins_un(a, b, max);
		else if ((p_intmax = get_position_int(b, get_max(b))) > get_len(b) / 2)
			rrb(b);
		else
			rb(b);
	}
}
