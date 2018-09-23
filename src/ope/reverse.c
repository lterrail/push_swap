/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 15:00:30 by lucien            #+#    #+#             */
/*   Updated: 2018/09/23 07:14:48 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rra(t_push **a)
{
	ft_reverse_rotate(a);
	if (*a && (*a)->next)
	{
		(*a)->count++;
		if ((*a)->display)
			ft_putendl("rra");
	}
	return (E_SUCCES);
}

int		rrb(t_push **b)
{
	ft_reverse_rotate(b);
	if (*b && (*b)->next)
	{
		(*b)->count++;
		if ((*b)->display)
			ft_putendl("rrb");
	}
	return (E_SUCCES);
}

int		rrr(t_push **a, t_push **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	if (*a && *b && (*a)->next && (*b)->next)
	{
		(*a)->count++;
		if ((*a)->display)
			ft_putendl("rrr");
	}
	else if (*a && (*a)->next)
	{
		(*a)->count++;
		if ((*a)->display)
			ft_putendl("rra");
	}
	else if (*b && (*b)->next)
	{
		(*b)->count++;
		if ((*b)->display)
			ft_putendl("rrb");
	}
	return (E_SUCCES);
}
