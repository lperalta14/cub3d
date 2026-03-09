/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:59:58 by anzarago          #+#    #+#             */
/*   Updated: 2024/12/13 17:56:41 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*dest;

	start = 0;
	i = 0;
	end = ft_strlen((char *)s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	dest = (char *)malloc(end - start + 2);
	if (!dest)
		return (0);
	while (start <= end)
	{
		dest[i] = s1[start];
		start ++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// #include <stdio.h>
// int main(){
// 	const char *x = "hola mundo hola mundo hola";
// 	const char *c = "hola";
// 	char *ptr = ft_strtrim(x, c);
// 	printf("%s", ptr);
// 	free(ptr);
// 	return 0;
// }