/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:13:19 by aelousse          #+#    #+#             */
/*   Updated: 2022/02/05 17:13:21 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define BUFFER_SIZE 1

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

// get_next_Line_functions :

char	*get_next_line(int fd);
char	*ft_read_buff(char *buff, int fd);
char	*ft_get_line(char *buff);
char	*ft_get_leftovers(char *buff);
int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);

// libft_functions :

int		ft_isdigit(int c);
long	ft_atoi(const char *str);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
char	**ft_split(char const *s, char c);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int data);
char	*ft_strjoin1(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);

// push_swap functions :

t_stack	**stack_init(t_stack **s);
void	fillstack(t_stack **a, t_stack **b, int ac, char **av);
void	sort_stack(t_stack **a, t_stack **b);
void	freeall(char **tab, char *tmp, t_stack **a, t_stack **b);
void	push_inf(t_stack **a, t_stack **b, int nb);
void	push_sup(t_stack **a, t_stack **b, int nb);
void	push_near(t_stack **a, t_stack **b, int j);
void	sa(t_stack **s, char c);
void	sb(t_stack **s, char c);
void	ss(t_stack **a, t_stack **b, char c);
void	ra(t_stack **s, char c);
void	rb(t_stack **s, char c);
void	rr(t_stack **a, t_stack **b, char c);
void	rra(t_stack **s, char c);
void	rrb(t_stack **s, char c);
void	rrr(t_stack **a, t_stack **b, char c);
void	pb(t_stack **a, t_stack **b, char c);
void	pa(t_stack **a, t_stack **b, char c);
void	free_stack(t_stack **s);
int		stacksize(t_stack *s);
int		check_sorted(t_stack **s);
int		*sorted_stack(t_stack **a);
int		get_max(t_stack **a);
int		get_min_index(t_stack **a);
int		get_index(t_stack **a, int data);
void	free_table(char **tab);

// checker functions :
char	*ft_strchr(char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);

#endif
