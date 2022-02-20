/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:34:56 by aelousse          #+#    #+#             */
/*   Updated: 2022/02/17 22:13:06 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_ops_errors(t_stack **a, t_stack **b, char *line)
{
	if (ft_strcmp(line, "ra\n") && ft_strcmp(line, "rb\n")
		&& ft_strcmp(line, "sa\n") && ft_strcmp(line, "sb\n")
		&& ft_strcmp(line, "ss\n") && ft_strcmp(line, "rr\n")
		&& ft_strcmp(line, "rra\n") && ft_strcmp(line, "rrb\n")
		&& ft_strcmp(line, "rrr\n") && ft_strcmp(line, "pa\n")
		&& ft_strcmp(line, "pb\n"))
	{
		write(2, "Error\n", 6);
		free(line);
		free_stack(a);
		free_stack(b);
		exit(1);
	}
}

static void	check_and_sort(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(a, 'c');
	else if (!ft_strcmp(line, "sb\n"))
		sb(b, 'c');
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b, 'c');
	else if (!ft_strcmp(line, "ra\n"))
		ra(a, 'c');
	else if (!ft_strcmp(line, "rb\n"))
		rb(b, 'c');
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b, 'c');
	else if (!ft_strcmp(line, "pa\n"))
		pa(a, b, 'c');
	else if (!ft_strcmp(line, "pb\n"))
		pb(a, b, 'c');
	else if (!ft_strcmp(line, "rra\n"))
		rra(a, 'c');
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b, 'c');
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b, 'c');
}

static void	check_sort(t_stack **a, t_stack **b)
{
	if (!b || !a)
		return ;
	if (check_sorted(a) && !*b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(a);
	free_stack(b);
	exit(1);
}

int	main(int ac, char **av)
{
	t_stack	**a;
	t_stack	**b;
	char	*line;

	a = NULL;
	b = NULL;
	a = stack_init(a);
	b = stack_init(b);
	fillstack(a, b, ac, av);
	line = get_next_line(0);
	while (line)
	{
		check_ops_errors(a, b, line);
		check_and_sort(a, b, line);
		free(line);
		line = get_next_line(0);
	}
	check_sort(a, b);
	return (0);
}
