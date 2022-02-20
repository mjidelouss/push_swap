/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:43:29 by aelousse          #+#    #+#             */
/*   Updated: 2022/02/08 17:43:49 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c > '9' || c < '0')
		return (0);
	return (1);
}

long	ft_atoi(const char *str)
{
	long	i;
	long	s;
	long	result;

	i = 0;
	s = 1;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -s;
		i++;
	}
	while ((str[i] <= '9' && str[i] >= '0') && str[i] != '\0')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * s);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*first;

	if (!lst)
		return ;
	if (*lst)
	{
		first = *lst;
		while (first -> next)
			first = first -> next;
		first -> next = new;
	}
	else
		*lst = new;
}

t_stack	*ft_lstnew(int data)
{
	t_stack	*lst;

	lst = (t_stack *)malloc(sizeof(t_stack));
	if (!lst)
		return (NULL);
	lst -> data = data;
	lst -> next = NULL;
	return (lst);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst)
		return ;
	new -> next = *lst;
	*lst = new;
}
