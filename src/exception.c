/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 19:50:50 by jsobel            #+#    #+#             */
/*   Updated: 2018/09/17 17:22:26 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exception(char *s)
{
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
