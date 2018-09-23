/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 16:07:03 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/23 18:14:50 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			global_count(t_push *a)
{
	int		nb;

	nb = 0;
	if (a && a->count == -1)
		return (E_ERROR);
	while (a)
	{
		nb += a->count;
		a = a->next;
	}
	return (nb);
}

int			ft_valid_list(t_push *p)
{
	t_push *c;

	c = p;
	while (c->next)
	{
		c = c->next;
		if (c->value == p->value)
			return (0);
	}
	if (!p->next || (p->next && ft_valid_list(p->next)))
		return (1);
	else
		return (0);
}

int			ft_bigger_than_integer(char *p, int value, int i)
{
	if (((value > 0 || i > 11) && p[0] == '-')
	|| (value >= 0 && (value % 10) != (p[i] - 48))
	|| (value < 0 && (value % 10) != -(p[i] - 48))
	|| ((value < 0 || i > 11) && p[0] != '-'))
		return (1);
	return (0);
}

t_push		*ft_creat_list(int argc, char **argv, int display)
{
	t_push	*p;
	int		i;

	p = NULL;
	i = -1;
	if (argc > 0)
	{
		while (argv[0][++i])
			if (argv[0][0] != '-' && (argv[0][i] < '0' || argv[0][i] > '9'))
				return (NULL);
		if (!(p = (t_push *)malloc(sizeof(t_push))))
			return (NULL);
		p->value = ft_atoi(argv[0]);
		p->count = 0;
		p->display = display;
		p->next = NULL;
		if (ft_bigger_than_integer(argv[0], p->value, i - 1) || (argc > 1
			&& !(p->next = ft_creat_list(argc - 1, &argv[1], display))))
		{
			free(p);
			return (NULL);
		}
	}
	return (p);
}
