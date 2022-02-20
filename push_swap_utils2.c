/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:43:55 by aelousse          #+#    #+#             */
/*   Updated: 2022/02/14 15:59:34 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*substr;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	substr = (char *) malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (start < ft_strlen(s) && i < len)
	{
		substr[i] = (char)s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

static int	ft_total(char const *s, char c)
{
	int	t;

	t = 0;
	while (*s)
	{
		if (*s != c)
		{
			t++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (t);
}

char	**ft_split(char const *s, char c)
{
	char	*start;
	int		i;
	int		len;
	char	**str;

	i = 0;
	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char **) * (ft_total(s, c) + 1));
	if (!str)
		return (0);
	while (*s)
	{
		if (*s == c)
			s++;
		start = (char *)s;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		s += len;
		if (*(s - 1) != c)
			str[i++] = ft_substr(start, 0, len);
	}
	str[i] = NULL;
	return (str);
}

void	free_table(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	int		total;
	char	*s;

	if (!s2 || !s1)
		return (NULL);
	total = ft_strlen(s1) + ft_strlen(s2) + 2;
	s = (char *)malloc(total * sizeof(char));
	if (!s)
		return (NULL);
	while (*s1)
		*s++ = *s1++;
	*s++ = ' ';
	while (*s2)
		*s++ = *s2++;
	*s = '\0';
	return (s - total + 1);
}
