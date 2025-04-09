/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnesgar <agnesgar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-04 21:27:57 by agnesgar          #+#    #+#             */
/*   Updated: 2025-04-04 21:27:57 by agnesgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_nums(char *s, char c)
{
	int		count;
	int		i;
	int		in_number;

	i = 0;
	count = 0;
	in_number = 0;
	while (s[i])
	{
		if (s[i] != c && in_number == 0)
		{
			in_number = 1;
			count ++;
		}
		else if (s[i] == c)
			in_number = 0;
		i++;
	}
	return (count);
}

static char	*malloc_number(char *s, char c)
{
	int		len;
	int		i;
	char	*number;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	number = malloc(sizeof(char) * (len + 1));
	if (!number)
		return (NULL);
	i = 0;
	while (i < len)
	{
		number[i] = s[i];
		i++;
	}
	number[i] = '\0';
	return (number);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		index;
	char	**res;

	res = malloc(sizeof(char *) * (count_nums(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			res[index++] = malloc_number(&s[i], c);
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	res[index] = NULL;
	return (res);
}
