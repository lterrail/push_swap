/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 16:07:09 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/23 18:08:13 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_init_tab(void (*tab[5])(t_push **, t_push **))
{
	tab[0] = &ft_process;
	tab[1] = &ft_shaker;
	tab[2] = &simple_case;
	tab[3] = &end_reverse;
	tab[4] = &shake_it_all;
}

int				main(int argc, char **argv)
{
	void	(*tab[5])(t_push **, t_push **);
	int		result[5];
	char	**copie;
	int		i;

	copie = NULL;
	ft_init_tab(tab);
	i = 0;
	if (argc < 2)
		return (E_ERROR);
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		if (!(copie = ft_strsplit(argv[1], ' ')))
			return (E_ERROR);
		i = ft_tablen(copie);
		fill_result_malloc(tab, result, i, copie);
		select_method_malloc(tab, result, i, copie);
		free_tab(copie);
	}
	else
	{
		fill_result_argv(tab, result, argc - 1, &argv[1]);
		select_method_argv(tab, result, argc - 1, &argv[1]);
	}
	return (E_SUCCES);
}
