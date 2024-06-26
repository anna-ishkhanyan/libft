/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anishkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:48:25 by anishkha          #+#    #+#             */
/*   Updated: 2024/01/27 21:16:06 by anishkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ischar(char const s, char c)
{
	return (s == c);
}

size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (!ft_ischar(s[i], c)
			&& (ft_ischar(s[i + 1], c) || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	*ft_getword(char const **s, char c)
{
	char	*word;
	size_t	i;
	size_t	start;
	size_t	j;

	i = 0;
	while ((*s)[i] != '\0' && ft_ischar((*s)[i], c))
		i++;
	start = i;
	while ((*s)[i] != '\0' && !ft_ischar((*s)[i], c))
		i++;
	word = (char *)malloc(sizeof(char) * (i - start + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (start < i)
	{
		word[j] = (*s)[start];
		j++;
		start++;
	}
	word[j] = '\0';
	*s = *s + i;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	**res;

	if (!s)
		return (NULL);
	len = ft_wordcount(s, c);
	res = (char **)malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = ft_getword(&s, c);
		i++;
	}
	res[i] = NULL;
	return (res);
}
