/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_results.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 17:51:39 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/23 17:52:42 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		select_method_argv(void (*tab[5])(t_push **, t_push **),
int result[5], int argc, char **argv)
{
	int		min;
	int		index;
	t_push	*a;
	t_push	*b;
	int		i;

	b = NULL;
	min = INT_MAX;
	i = 0;
	while (i <= 4)
	{
		if (result[i] >= 0 && result[i] <= min)
		{
			min = result[i];
			index = i;
		}
		i++;
	}
	if (!(a = ft_creat_list(argc, argv, 1)))
		ft_error_push_swap(a, b, "Error", NULL);
	if (!ft_valid_list(a))
		ft_error_push_swap(a, b, "Error", NULL);
	tab[index](&a, &b);
	ft_free_list(&a);
}

void		fill_result_argv(void (*tab[5])(t_push **, t_push **),
int result[5], int argc, char **argv)
{
	t_push	*a;
	t_push	*b;
	int		i;

	b = NULL;
	i = 0;
	while (i <= 4)
	{
		if (!(a = ft_creat_list(argc, argv, 0)))
			ft_error_push_swap(a, b, "Error", NULL);
		if (!ft_valid_list(a))
			ft_error_push_swap(a, b, "Error", NULL);
		tab[i](&a, &b);
		if (ft_is_sort_increasing(a) && !b)
			result[i] = global_count(a);
		else
			result[i] = -1;
		ft_free_list(&a);
		i++;
	}
}

void		select_method_malloc(void (*tab[5])(t_push **, t_push **),
int result[5], int argc, char **argv)
{
	int		min;
	int		index;
	t_push	*a;
	t_push	*b;
	int		i;

	b = NULL;
	min = INT_MAX;
	i = 0;
	while (i <= 4)
	{
		if (result[i] >= 0 && result[i] <= min)
		{
			min = result[i];
			index = i;
		}
		i++;
	}
	if (!(a = ft_creat_list(argc, argv, 1)))
		ft_error_push_swap(a, b, "Error", argv);
	if (!ft_valid_list(a))
		ft_error_push_swap(a, b, "Error", argv);
	tab[index](&a, &b);
	ft_free_list(&a);
}

void		fill_result_malloc(void (*tab[5])(t_push **, t_push **),
int result[5], int argc, char **argv)
{
	t_push	*a;
	t_push	*b;
	int		i;

	b = NULL;
	i = 0;
	while (i <= 4)
	{
		if (!(a = ft_creat_list(argc, argv, 0)))
			ft_error_push_swap(a, b, "Error", argv);
		if (!ft_valid_list(a))
			ft_error_push_swap(a, b, "Error", argv);
		tab[i](&a, &b);
		if (ft_is_sort_increasing(a) && !b)
			result[i] = global_count(a);
		else
			result[i] = -1;
		ft_free_list(&a);
		i++;
	}
}
