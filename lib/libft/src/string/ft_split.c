/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:22:56 by fschnorr          #+#    #+#             */
/*   Updated: 2025/10/29 15:05:52 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	*ft_fill_words(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static void	ft_initiate_vars(t_size *i, t_size *j, int *start_word)
{
	*i = 0;
	*j = 0;
	*start_word = -1;
}

char	**ft_split(const char *s, char c)
{
	char	**wrd_arr;
	size_t	i;
	size_t	j;
	int		word_start;

	ft_initiate_vars(&i, &j, &word_start);
	wrd_arr = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!wrd_arr)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && word_start < 0)
			word_start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && word_start >= 0)
		{
			wrd_arr[j] = ft_fill_words(s, word_start, i);
			if (!wrd_arr[j])
				return (ft_free(wrd_arr, j));
			word_start = -1;
			j++;
		}
		i++;
	}
	wrd_arr[j] = 0;
	return (wrd_arr);
}
