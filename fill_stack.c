/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:29:37 by aelousse          #+#    #+#             */
/*   Updated: 2022/02/08 18:29:39 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_for_duplicates(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_atoi(tab[j]) == ft_atoi(tab[i]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_stack	**stack_init(t_stack **s)
{
	s = malloc(sizeof(t_stack **));
	if (!s)
		return (NULL);
	*s = NULL;
	return (s);
}

static void	error_manager(t_stack **a, t_stack **b, char *t, char **tab)
{
	int	i;
	int	j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		if (ft_atoi(tab[i]) > MAX_INT || ft_atoi(tab[i]) < MIN_INT)
		{
			freeall(tab, t, a, b);
			write(2, "Error\n", 6);
			exit(1);
		}
		while (tab[i][++j])
		{
			if (tab[i][j] == '-' || tab[i][j] == '+')
				j++;
			if ((!ft_isdigit(tab[i][j])) || !check_for_duplicates(tab))
			{
				freeall(tab, t, a, b);
				write(2, "Error\n", 6);
				exit(1);
			}
		}
	}
}

static char	*parser(char **av)
{
	char	*t;
	char	*tmp;
	int		i;

	t = (char *)malloc(1 * sizeof(char));
	*t = '\0';
	i = 1;
	while (av[i])
	{
		tmp = t;
		t = ft_strjoin1(t, av[i]);
		free(tmp);
		i++;
	}
	return (t);
}

void	fillstack(t_stack **a, t_stack **b, int ac, char **av)
{
	char	**tab;
	int		i;
	t_stack	*s;
	char	*t;

	if (ac < 2)
	{
		free_stack(a);
		free_stack(b);
		exit(1);
	}
	t = parser(av);
	tab = ft_split(t, ' ');
	error_manager(a, b, t, tab);
	i = 1;
	*a = ft_lstnew(ft_atoi(tab[0]));
	while (tab[i])
	{	
		s = ft_lstnew(ft_atoi(tab[i]));
		ft_lstadd_back(a, s);
		i++;
	}
	free(t);
	free_table(tab);
}
