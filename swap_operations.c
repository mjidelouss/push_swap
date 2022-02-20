/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:47:09 by aelousse          #+#    #+#             */
/*   Updated: 2022/02/14 15:54:37 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **s)
{
	int	t;

	if (!s || !*s || !((*s)-> next))
		return ;
	t = (*s)-> data;
	(*s)-> data = (*s)-> next -> data;
	(*s)-> next -> data = t;
}

void	sa(t_stack **s, char c)
{
	swap(s);
	if (c == 's')
		write(1, "sa\n", 3);
}

void	sb(t_stack **s, char c)
{
	swap(s);
	if (c == 's')
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, char c)
{
	swap(a);
	swap(b);
	if (c == 's')
		write(1, "ss\n", 3);
}
