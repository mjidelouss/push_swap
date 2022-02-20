/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:13:07 by aelousse          #+#    #+#             */
/*   Updated: 2022/02/18 17:56:33 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	**a;
	t_stack	**b;

	a = NULL;
	b = NULL;
	a = stack_init(a);
	b = stack_init(b);
	fillstack(a, b, ac, av);
	sort_stack(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
