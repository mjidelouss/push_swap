/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:13:19 by aelousse          #+#    #+#             */
/*   Updated: 2022/02/14 15:55:47 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **s)
{
	t_stack	*head;
	t_stack	*tmp;

	if (!s || !*s)
		return ;
	head = *s;
	tmp = ft_lstnew(head -> data);
	ft_lstadd_back(s, tmp);
	*s = (*s)-> next;
	free(head);
}

void	ra(t_stack **s, char c)
{
	rotate(s);
	if (c == 's')
		write(1, "ra\n", 3);
}

void	rb(t_stack **s, char c)
{
	rotate(s);
	if (c == 's')
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, char c)
{
	rotate(a);
	rotate(b);
	if (c == 's')
		write(1, "rr\n", 3);
}
