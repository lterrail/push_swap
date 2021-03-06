/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 18:32:07 by jsobel            #+#    #+#             */
/*   Updated: 2018/09/23 17:56:32 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# define SMALL_SIZE 4
# define MEDIUM_SIZE 9
# define E_SUCCES 1
# define E_ERROR -1

typedef struct		s_push
{
	int				value;
	int				count;
	int				display;
	struct s_push	*next;
}					t_push;

/*
** push_swap -- list
*/

int					global_count(t_push *a);
t_push				*ft_creat_list(int argc, char **argv, int display);
int					ft_valid_list(t_push *p);
int					ft_bigger_than_integer(char *p, int value, int i);
void				ft_free_list(t_push **begin_list);

/*
** push_swap -- error
*/

int					ft_error_checker(t_push *a, char *s);
int					ft_error_push_swap(t_push *a, t_push *b,
					char *s, char **copie);
void				free_tab(char **tab);

/*
** push_swap -- simple_case
*/

void				end_reverse(t_push **a, t_push **b);
void				simple_case(t_push **a, t_push **b);

/*
** push_swap -- operator
*/

int					ft_check_op(char *op, t_push **a, t_push **b);
int					ft_swap(t_push **p);
int					ft_rotate(t_push **p);
int					ft_push(t_push **p1, t_push **p2);
int					ft_reverse_rotate(t_push **p);

/*
** push_swap -- get_data
*/

int					get_min(t_push *a);
int					get_max(t_push *a);
int					get_len(t_push *a);
int					get_position_int(t_push *a, int nb);
int					get_mediane(t_push *a, int len);

/*
** push_swap -- push
*/

void				pa(t_push **a, t_push **b);
void				pb(t_push **b, t_push **a);

/*
** push_swap -- rotate
*/

int					ra(t_push **a);
int					rb(t_push **b);
int					rr(t_push **a, t_push **b);

/*
** push_swap -- reverse
*/

int					rra(t_push **a);
int					rrb(t_push **b);
int					rrr(t_push **a, t_push **b);

/*
** push_swap -- swap
*/

int					sa(t_push **a);
int					sb(t_push **b);
int					ss(t_push **a, t_push **b);

/*
** push_swap -- sort
*/

int					ft_is_sort_increasing(t_push *p);
int					ft_is_sort_decreasing(t_push *p);
int					ft_sort(t_push **a, t_push **b);
int					check(t_push **a, t_push **b);

/*
** push_swap -- shaker
*/

void				shake_it_all_2(t_push **a, t_push **b);
void				shake_it_all(t_push **a, t_push **b);
int					divide_to_conquer(t_push **a, t_push **b, int med);
void				ft_shaker(t_push **a, t_push **b);

/*
** push_swap -- quick_sort
*/

void				ft_process(t_push **a, t_push **b);
void				sort_3less_int(t_push **a, int len, int int_min,
					int int_max);
void				basic_selective_sort(t_push **a, t_push **b, int len);
void				launch_quick_sort(t_push **a, t_push **b);

/*
**push_swap -- quick_sort
*/

void				process_distri_pyramid(t_push **a, t_push **b);
void				process_selec_sort_opti(t_push **a, t_push **b);
int					opti_get_max_moins_un(t_push **a, int max_b);
void				opti_place_ints_max(t_push **a, t_push **b, int ret);
int					where_is_next(t_push *a, int mediane);

/*
** push_swap -- fill_results
*/

void				fill_result_malloc(void (*tab[5])(t_push **, t_push **),
int result[5], int argc, char **argv);
void				select_method_malloc(void (*tab[5])(t_push **, t_push **),
int result[5], int argc, char **argv);
void				fill_result_argv(void (*tab[5])(t_push **, t_push **),
int result[5], int argc, char **argv);
void				select_method_argv(void (*tab[5])(t_push **, t_push **),
int result[5], int argc, char **argv);

#endif
