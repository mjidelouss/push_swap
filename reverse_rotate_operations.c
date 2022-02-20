/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:12:27 by aelousse          #+#    #+#             */
/*   Updated: 2022/02/06 19:12:52 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **s)
{
	t_stack	*head;
	t_stack	*tail;
	t_stack	*tmp;

	if (!s || !*s)
		return ;
	head = *s;
	while (head -> next != NULL)
	{
		head = head -> next;
	}
	tail = head;
	tmp = ft_lstnew(tail -> data);
	ft_lstadd_front(s, tmp);
	head = *s;
	while (head -> next != tail)
		head = head -> next;
	head -> next = NULL;
	free(tail);
}

void	rra(t_stack **s, char c)
{
	reverse_rotate(s);
	if (c == 's')
		write(1, "rra\n", 4);
}

void	rrb(t_stack **s, char c)
{
	reverse_rotate(s);
	if (c == 's')
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, char c)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (c == 's')
		write(1, "rrr\n", 4);
}
