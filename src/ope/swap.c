/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:37:48 by lucien            #+#    #+#             */
/*   Updated: 2018/09/23 07:15:08 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sa(t_push **a)
{
	ft_swap(a);
	if (*a && (*a)->next)
	{
		(*a)->count++;
		if ((*a)->display)
			ft_putendl("sa");
	}
	return (E_SUCCES);
}

int		sb(t_push **b)
{
	ft_swap(b);
	if (*b && (*b)->next)
	{
		(*b)->count++;
		if ((*b)->display)
			ft_putendl("sb");
	}
	return (E_SUCCES);
}

int		ss(t_push **a, t_push **b)
{
	ft_swap(a);
	ft_swap(b);
	if (*a && *b && (*a)->next && (*b)->next)
	{
		(*a)->count++;
		if ((*a)->display)
			ft_putendl("ss");
	}
	else if (*a && (*a)->next)
	{
		(*a)->count++;
		if ((*a)->display)
			ft_putendl("sa");
	}
	else if (*b && (*b)->next)
	{
		(*b)->count++;
		if ((*b)->display)
			ft_putendl("sb");
	}
	return (E_SUCCES);
}
