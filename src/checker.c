/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 16:06:45 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/23 13:24:06 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	// ft_printf("{yellow}FIRST{eoc}\n");
	if (!(a = ft_creat_list(i, copie, 0)))
	{
		// ft_printf("{yellow}SECOND{eoc}\n");
		free_tab(copie);
		return (NULL);
	}
	printf("a = %d\n", a->value);
	// ft_printf("{yellow}THIRD{eoc}\n");
	free_tab(copie);
	return (a);
}

static int		read_op(t_push **a, t_push **b)
{
	char	*op;

	while ((get_next_line(0, &op) > 0))
	{
		if (ft_check_op(op, a, b) == E_ERROR)
		{
			printf("OP1 = %s\n", op);
			free(op);
			printf("OP2 = %s\n", op);
			return (E_ERROR);
		}
		free(op);
	}
	free(op);
	return (E_SUCCES);
}

int				main(int argc, char **argv)
{
	t_push	*a;
	t_push	*b;

	b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		if (!(1 && (a = split_arg(argv[1]))))
		{
			return (ft_error_checker(a, "Error"));
		}
	}
	else if (!(a = ft_creat_list(argc - 1, &argv[1], 0)))
		return (ft_error_checker(a, "Error"));
	if (!ft_valid_list(a))
		return (ft_error_checker(a, "Error"));
	if (read_op(&a, &b) == E_ERROR)
	{
		if (b)
			ft_free_list(&b);
		return (ft_error_checker(a, "Error"));
	}
	ft_is_sort_increasing(a) && !b ? ft_putendl("OK") : ft_putendl("KO");
	ft_free_list(&a);
	ft_free_list(&b);
	return (E_SUCCES);
}
