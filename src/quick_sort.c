/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 00:12:58 by lucien            #+#    #+#             */
/*   Updated: 2018/06/10 01:28:09 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		split_mediane(t_push **a, t_push **b, int len, int quartile)
{
	int		mediane;
	int		half;

	if (len % 2 == 0)
		half = (len / 2) + 1;
	else
		half = len / 2;
	mediane = get_mediane(a, half);
	while ((*a) && get_len(a) != half)
	{
		if ((*a)->value < mediane)
		{
			pb(a, b);
			printf("b = %d\n", (*b)->value);
		}
		else if ((*b) && (*b)->value < quartile)
			rr(a, b);
		else
			ra(a);
	}
	if (get_len(a) < MEDIUM_SIZE)
		sort_20less_int(a, b, get_len(a));
	else
		split_mediane(a, b, get_len(a), quartile);
}
