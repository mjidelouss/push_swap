/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:36:00 by aelousse          #+#    #+#             */
/*   Updated: 2022/02/14 15:57:28 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	small_sort(t_stack **a)
{
	int		max;

	max = get_max(a);
	if (stacksize(*a) == 2 && (*a)-> data > (*a)->next -> data)
	{
		sa(a, 's');
		return ;
	}
	if (max == (*a)-> data)
	{
		ra(a, 's');
		if ((*a)-> data > (*a)-> next -> data)
			sa(a, 's');
	}
	if (max == ((*a)-> next -> data))
	{
		rra(a, 's');
		if ((*a)-> data > (*a)-> next -> data)
			sa(a, 's');
	}
	if (max == (*a)-> next -> next -> data
		&& (*a)-> data > (*a)-> next -> data)
		sa(a, 's');
}

static void	minimum_sort(t_stack **a, t_stack **b)
{
	int	i;

	i = stacksize(*a) - 3;
	push_near(a, b, i);
	small_sort(a);
	while (stacksize(*b))
		pa(a, b, 's');
}

static void	meduim_sort(t_stack **a, t_stack **b)
{
	int		*tab;
	int		j;
	int		len;

	len = stacksize(*a);
	tab = sorted_stack(a);
	push_inf(a, b, tab[len / 5]);
	push_inf(a, b, tab[len * 2 / 5]);
	push_inf(a, b, tab[len * 3 / 5]);
	push_inf(a, b, tab[len * 4 / 5]);
	j = len - 4 * len / 5;
	push_near(a, b, j);
	j = len / 5;
	while (j--)
		pa(a, b, 's');
	push_sup(a, b, len * 4 / 5);
	if (*b)
		pa(a, b, 's');
	free(tab);
}

static void	maximum_sort(t_stack **a, t_stack **b)
{
	int		*tab;
	int		j;
	int		len;

	len = stacksize(*a);
	tab = sorted_stack(a);
	push_inf(a, b, tab[len / 10]);
	push_inf(a, b, tab[len * 2 / 10]);
	push_inf(a, b, tab[len * 3 / 10]);
	push_inf(a, b, tab[len * 4 / 10]);
	push_inf(a, b, tab[len * 5 / 10]);
	push_inf(a, b, tab[len * 6 / 10]);
	push_inf(a, b, tab[len * 7 / 10]);
	push_inf(a, b, tab[len * 8 / 10]);
	push_inf(a, b, tab[len * 9 / 10]);
	j = len - 9 * len / 10;
	push_near(a, b, j);
	j = len / 10;
	while (j--)
		pa(a, b, 's');
	push_sup(a, b, len * 9 / 10);
	if (*b)
		pa(a, b, 's');
	free(tab);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	if (check_sorted(a))
	{
		free_stack(a);
		free_stack(b);
		exit(1);
	}
	if (stacksize(*a) == 3 || stacksize(*a) == 2)
		small_sort(a);
	else if (stacksize(*a) > 3 && stacksize(*a) <= 10)
		minimum_sort(a, b);
	else if (stacksize(*a) > 10 && stacksize(*a) <= 100)
		meduim_sort(a, b);
	else if (stacksize(*a) > 100)
		maximum_sort(a, b);
}
