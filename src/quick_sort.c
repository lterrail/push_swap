/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 00:12:58 by lucien            #+#    #+#             */
/*   Updated: 2018/06/12 18:40:28 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		process_distri_pyramid(t_push **a, t_push **b)
{
	int		div_mediane;

	if ((div_mediane = get_len(a) / 100) <= 2)
		div_mediane = 3;
	opti_clear_bottom(a, div_mediane);
	while (get_len(a) > MEDIUM_SIZE)
	{
		if ((*a)->value < get_mediane(a, get_len(a) / div_mediane / 2))
		{
			pb(a, b);
			rb(b);
		}
		else if ((*a)->value < get_mediane(a, get_len(a) / div_mediane))
			pb(a, b);
		else
			ra(a);
	}
	basic_selective_sort(a, b, get_len(a));
}

void		process_selec_sort_opti(t_push **a, t_push **b, int sort)
{
	int		max;
	int		max2;
	int		p_intmax;
	int		ret;

	ret = 0;
	while ((*b) != NULL && ft_sort(a, b, sort) != 1)
	{
		if ((*b)->value == (max = get_max(b)))
		{
			opti_place_ints_max(a, b, ret);
			ret = 0;
		}
		else if ((*b)->value == (max2 = opti_get_max_moins_un(b, max)))
		{
			pa(a, b);
			ret++;
		}
		else if ((p_intmax = get_position_int(b, get_max(b))) > get_len(b) / 2)
			rrb(b);
		else
			rb(b);
	}
}

void		opti_clear_bottom(t_push **a, int div_mediane)
{
	t_push	*tmp;
	int		len;
	int		i;

	i = 0;
	len = get_len(a) / 10 * 9;
	tmp = (*a);
	while (len--)
		tmp = tmp->next;
	while (tmp != NULL)
	{
		if (tmp->value < get_mediane(a, get_len(a) / div_mediane / 2))
			i++;
		tmp = tmp->next;
	}
	if (i >= (div_mediane))
	{
		while (i > 0)
		{
			rra(a);
			i--;
		}
	}
}

int			opti_get_max_moins_un(t_push **a, int max_b)
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

void		opti_place_ints_max(t_push **a, t_push **b, int ret)
{
	int ret2;

	ret2 = ret;
	if (ret == 0)
		pa(a, b);
	else if (ret == 1)
	{
		pa(a, b);
		sa(a);
	}
	else if (ret > 1)
	{
		while (ret > 0)
		{
			ra(a);
			ret--;
		}
		pa(a, b);
		while (ret2 > 0)
		{
			rra(a);
			ret2--;
		}
	}
}
