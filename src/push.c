/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:23:26 by lucien            #+#    #+#             */
/*   Updated: 2018/06/08 16:26:30 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_push **p1, t_push **p2)
{
	t_push *tmp;

	if (*p2)
	{
		tmp = (*p2)->next;
		(*p2)->next = *p1;
		*p1 = *p2;
		*p2 = tmp;
	}
	ft_putendl("pa");
}

void	pb(t_push **p1, t_push **p2)
{
	t_push *tmp;

	if (*p2)
	{
		tmp = (*p2)->next;
		(*p2)->next = *p1;
		*p1 = *p2;
		*p2 = tmp;
	}
	ft_putendl("pb");
}
