/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:29:17 by aelousse          #+#    #+#             */
/*   Updated: 2022/02/11 22:29:30 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack **a)
{
	t_stack	*tmp;

	if (!a || !*a)
		return (0);
	tmp = *a;
	while (tmp -> next)
	{
		if ((tmp -> data) > (tmp -> next -> data))
		{
			break ;
		}
		tmp = tmp -> next;
	}
	if (!tmp -> next)
		return (1);
	return (0);
}

int	get_max(t_stack **a)
{
	int		max;
	t_stack	*tmp;

	tmp = *a;
	max = tmp -> data;
	while (tmp)
	{
		if (tmp -> data > max)
			max = tmp -> data;
		tmp = tmp -> next;
	}
	return (max);
}

int	get_min_index(t_stack **a)
{
	int		min;
	int		pos;
	t_stack	*tmp;

	tmp = *a;
	pos = 1;
	min = tmp -> data;
	while (tmp)
	{
		if (tmp -> data < min)
			min = tmp -> data;
		tmp = tmp -> next;
	}
	tmp = *a;
	while (tmp && min != tmp -> data)
	{
		pos++;
		tmp = tmp -> next;
	}
	return (pos);
}

int	get_index(t_stack **a, int data)
{
	t_stack	*tmp;
	int		pos;

	pos = 1;
	tmp = *a;
	while (tmp && data != tmp -> data)
	{
		pos++;
		tmp = tmp -> next;
	}
	return (pos);
}

int	stacksize(t_stack *lst)
{
	int	len;

	len = 1;
	if (!lst)
		return (0);
	while ((lst -> next) != NULL)
	{
		len++;
		lst = lst -> next;
	}
	return (len);
}
