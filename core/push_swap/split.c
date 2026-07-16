/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 19:11:03 by muali             #+#    #+#             */
/*   Updated: 2026/07/16 00:22:42 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(const char *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (count);
}

static char	*get_word(const char *str, int *idx, char c)
{
	int		start;
	int		len;
	char	*word;
	int		i;

	while (str[*idx] && str[*idx] == c)
		(*idx)++;
	start = *idx;
	while (str[*idx] && str[*idx] != c)
		(*idx)++;
	len = *idx - start;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**free_all(char **res, int i)
{
	while (i > 0)
		free(res[--i]);
	free(res);
	return (NULL);
}

char	**ft_split(const char *str, char c)
{
	char	**res;
	int		words;
	int		i;
	int		idx;

	if (!str)
		return (NULL);
	words = count_words(str, c);
	res = malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	idx = 0;
	while (i < words)
	{
		res[i] = get_word(str, &idx, c);
		if (!res[i])
			return (free_all(res, i));
		i++;
	}
	res[i] = NULL;
	return (res);
}
