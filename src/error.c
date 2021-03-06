/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 16:06:51 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/24 18:31:44 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void		ft_free_list(t_push **begin_list)
{
	t_push	*delete;
	t_push	*tmp;

	tmp = *begin_list;
	while (tmp)
	{
		delete = tmp;
		tmp = tmp->next;
		free(delete);
	}
}

int			ft_error_checker(t_push *a, char *s)
{
	ft_free_list(&a);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	return (E_ERROR);
}

int			ft_error_push_swap(t_push *a, t_push *b, char *s, char **copie)
{
	ft_free_list(&a);
	if (b)
		ft_free_list(&b);
	if (copie)
		free_tab(copie);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	exit(E_ERROR);
}
