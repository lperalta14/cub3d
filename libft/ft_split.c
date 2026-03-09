/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:40:48 by anzarago          #+#    #+#             */
/*   Updated: 2024/12/16 15:36:55 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	while (--i >= 0)
		free(split[i]);
	free(split);
	return (NULL);
}

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	count = 0;
	if (!s || !*s)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count ++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

static size_t	ft_word_len(char const *s, char c)
{
	char	*next_delim;

	next_delim = ft_strchr(s, c);
	if (next_delim)
		return (next_delim - s);
	return (ft_strlen(s));
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	len;
	int		i;

	i = 0;
	dest = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!s || !dest)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			len = ft_word_len(s, c);
			dest[i++] = ft_substr(s, 0, len);
			if (!dest[i - 1])
				return (ft_free_split(dest));
			s += len;
		}
	}
	dest[i] = 0;
	return (dest);
}

// #include <stdio.h>
// int main()
// {
// 	char str[] = "Hola,esto,es,un,ejemplo";
// 	char delimiter = ',';
// 	char **result = ft_split(str, delimiter);
// 	int i = 0;
// 	while (result[i] != NULL)
// 	{
// 		printf("Parte %d: %s\n", i + 1, result[i]);
// 		i++;
// 	}
// 	ft_free_split(result);
// 	return (0);
// }