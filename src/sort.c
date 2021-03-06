/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 16:07:25 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/23 19:16:10 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_is_sort_increasing(t_push *p)
{
	while (p && p->next)
	{
		if (p->value > p->next->value)
			return (0);
		p = p->next;
	}
	return (E_SUCCES);
}

int			ft_is_sort_decreasing(t_push *p)
{
	while (p && p->next)
	{
		if (p->value < p->next->value)
			return (0);
		p = p->next;
	}
	return (E_SUCCES);
}

int			ft_sort(t_push **a, t_push **b)
{
	if (ft_is_sort_increasing(*a) && ft_is_sort_decreasing(*b)
	&& (!*a || !*b || (*a)->value > (*b)->value))
		return (E_SUCCES);
	else
		return (0);
}

int			check(t_push **a, t_push **b)
{
	if (ft_is_sort_increasing(*a) && ft_is_sort_decreasing(*b)
	&& (!*a || !*b || (*a)->value > (*b)->value))
	{
		while (*b)
		{
			pa(a, b);
		}
		return (E_SUCCES);
	}
	else
		return (0);
}
