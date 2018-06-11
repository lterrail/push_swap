/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 19:07:30 by lucien            #+#    #+#             */
/*   Updated: 2018/06/11 17:06:46 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_max_moins_un(t_push **a, int max_b)
{
	t_push	*tmp;
	int		int_max;

	int_max = 0;
	tmp = (*a);
	while (tmp != NULL)
	{
		if (int_max < tmp->value && tmp->value < max_b)
			int_max = tmp->value;
		tmp = tmp->next;
	}
	return (int_max);
}

void		place_max_moins_un(t_push **a, t_push **b, int max)
{
	int		p_intmax;

	pa(a, b);
	while ((*b)->value != max)
	{
		if ((p_intmax = get_position_int(b, get_max(b))) > get_len(b) / 2)
			rrb(b);
		else
			rb(b);
	}
	pa(a, b);
	sa(a);
}
