/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:01:49 by aelousse          #+#    #+#             */
/*   Updated: 2022/02/17 17:02:05 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freeall(char **tab, char *tmp, t_stack **a, t_stack **b)

{
	free_table(tab);
	free(tmp);
	free_stack(a);
	free_stack(b);
}

void	free_stack(t_stack **s)
{
	while (*s)
	{
		free(*s);
		*s = (*s)->next;
	}
	free(s);
}
