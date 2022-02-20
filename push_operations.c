/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:14:13 by aelousse          #+#    #+#             */
/*   Updated: 2022/02/14 15:54:23 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (!a || !b || !*b)
		return ;
	tmp = ft_lstnew((*b)-> data);
	if (!*a)
		*a = tmp;
	else
		ft_lstadd_front(a, tmp);
	tmp1 = *b;
	*b = (*b)-> next;
	free(tmp1);
}

void	pb(t_stack **a, t_stack **b, char c)
{
	push(b, a);
	if (c == 's')
		write(1, "pb\n", 3);
}

void	pa(t_stack **a, t_stack **b, char c)
{
	push(a, b);
	if (c == 's')
		write(1, "pa\n", 3);
}
