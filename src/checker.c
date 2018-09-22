/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 16:06:45 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/22 17:23:35 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static t_push	*split_arg(char *tab)
{
	char	**copie;
	t_push	*a;
	int		i;

	i = 0;
	if (!(copie = ft_strsplit(tab, ' ')))
		return (NULL);
	while (copie[i])
		i++;
	a = ft_creat_list(i, copie, 0);
	free_tab(copie);
	return (a);
}

int				main(int argc, char **argv)
{
	t_push	*a;
	t_push	*b;
	char	*op;

	b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2 && ft_strchr(argv[1], ' '))
		a = split_arg(argv[1]);
	else if (!(a = ft_creat_list(argc - 1, &argv[1], 0)))
		ft_error("failed to creat list");
	if (!ft_valid_list(a))
		ft_error("Error");
	while ((get_next_line(0, &op) > 0))
	{
		ft_check_op(op, &a, &b);
		free(op);
	}
	ft_is_sort_increasing(a) && !b ? ft_putendl("OK") : ft_putendl("KO");
	ft_free_list(&a);
	ft_free_list(&b);
	free(op);
	return (0);
}
