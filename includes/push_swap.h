/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:08:47 by lucien            #+#    #+#             */
/*   Updated: 2018/06/08 16:57:32 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 18:32:07 by jsobel            #+#    #+#             */
/*   Updated: 2018/06/07 19:54:16 by jsobel           ###   ########.fr       */
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

# define BUFF_SIZE  32

typedef struct		s_push
{
	int				value;
	struct s_push	*next;
}					t_push;

typedef struct		s_data
{
	char			*line;
	char			*tmp;
	int				index;
	struct s_data	*next;
}					t_data;

/*
** checker -- checks
*/

int					ft_is_sort_increasing(t_push *p);
int					ft_is_sort_decreasing(t_push *p);
void				ft_check_op(char *op, t_push **listA, t_push **listB);

/*
** checker -- operators
*/

int					ft_swap(t_push **p);
int					ft_rotate(t_push **p);
int					ft_reverse_rotate(t_push **p);

/*
** checker -- utils
*/

int					get_next_line(const int fd, char **line);
void				ft_exception(char *s);

/*
** push_swap -- checks
*/

/*
** push_swap -- operators
*/

int					sa(t_push **p);
int					sb(t_push **p);
int					ss(t_push **a, t_push **b);
void				pa(t_push **p1, t_push **p2);
void				pb(t_push **p1, t_push **p2);
int					ra(t_push **p);
int					rb(t_push **p);
int					rr(t_push **a, t_push **b);
int					rra(t_push **p);
int					rrb(t_push **p);
int					rrr(t_push **a, t_push **b);

/*
** push_swap -- process
*/

void				ft_process(t_push **listA, t_push **listB);
int					get_mediane(t_push **listA);

/*
** push_swap -- utils
*/

#endif
