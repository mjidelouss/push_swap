/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:07:18 by aelousse          #+#    #+#             */
/*   Updated: 2022/02/17 22:14:55 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_elements(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	tmp = 0;
	i = 0;
	while (i < size)
	{
		j = i;
		while (j > 0 && tab[j - 1] > tab[j])
		{
			tmp = tab[j];
			tab[j] = tab[j - 1];
			tab[j - 1] = tmp;
			j--;
		}
		i++;
	}
}

int	*sorted_stack(t_stack **a)
{
	t_stack	*tmp;
	int		*tab;
	int		i;

	i = 0;
	tab = malloc(stacksize(*a) * sizeof(int));
	tmp = *a;
	while (tmp)
	{
		tab[i] = tmp -> data;
		tmp = tmp -> next;
		i++;
	}
	sort_elements(tab, stacksize(*a));
	return (tab);
}

void	push_inf(t_stack **a, t_stack **b, int push)
{
	t_stack	*tmp;
	int		pos;

	tmp = *a;
	while (tmp)
	{
		if (tmp -> data < push)
		{
			pos = get_index(a, tmp -> data);
			if (pos <= stacksize(*a) / 2)
			{
				while (pos-- > 1)
					ra(a, 's');
			}
			else
			{
				while (pos++ <= stacksize(*a))
					rra(a, 's');
			}
			pb(a, b, 's');
			tmp = *a;
			continue ;
		}
		tmp = tmp -> next;
	}
}

void	push_near(t_stack **a, t_stack **b, int j)
{
	int	pos;

	while (j--)
	{
		pos = get_min_index(a);
		if (pos <= stacksize(*a) / 2)
		{
			while (pos-- > 1)
				ra(a, 's');
		}
		else
		{
			while (pos++ <= stacksize(*a))
				rra(a, 's');
		}
		pb(a, b, 's');
	}
}

void	push_sup(t_stack **a, t_stack **b, int push)
{
	int		pos;

	while (push--)
	{
		pos = get_index(b, get_max(b));
		if (pos <= stacksize(*b) / 2)
		{
			while (pos-- > 1)
				rb(b, 's');
		}
		else
		{
			while (pos++ <= stacksize(*b))
				rrb(b, 's');
		}
		if (*a)
			pa(a, b, 's');
	}
}
