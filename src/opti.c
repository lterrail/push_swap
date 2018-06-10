/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 19:07:30 by lucien            #+#    #+#             */
/*   Updated: 2018/06/10 20:08:25 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_max_moins_un(t_push **a, t_push **b, int max_b)
{
	t_push	*tmp;
	t_push	*tmp2;
	int		a_int_max;
	int		b_int_max;

	a_int_max = 0;
	b_int_max = 0;
	tmp = (*a);
	tmp2 = (*b);
	while (tmp != NULL)
	{
		if (a_int_max < tmp->value && tmp->value < max_b)
			a_int_max = tmp->value;
		tmp = tmp->next;
	}
	while (tmp2 != NULL)
	{
		if (b_int_max < tmp2->value && tmp2->value < max_b)
			b_int_max = tmp2->value;
		tmp2 = tmp2->next;
	}
	if (a_int_max > b_int_max)
		return (a_int_max);
	return (b_int_max);
}

static void	process_intmax2(t_push **a, t_push **b, int max_b)
{
	int		ret;

	if ((ret = get_max_moins_un(a, b, max_b)) == ((*a)->value) &&
	((*a)-> value < max_b))
	{
		rr(a, b);
		while (max_b > (*a)->value)
			pb(a, b);
		rrb(b);
		pa(a, b);
		rra(a);
	}
	else if (ret == ((*a)->value) && ((*a)->value > max_b))
	{
		pa(a, b);
		sa(a);
	}
	else
	{
		rb(b);
		while (max_b > (*a)->value)
			pb(a, b);
		rrb(b);
		pa(a, b);
	}
}

int			save_newintmax_in_top_a(t_push **a, t_push **b)
{
	int		max_b;

	max_b = (*b)->value;
	if ((*a)->value > max_b)
		pa(a, b);
	else
		process_intmax2(a, b, max_b);
	return (max_b);
}
