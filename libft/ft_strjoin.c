/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:20:27 by anzarago          #+#    #+#             */
/*   Updated: 2024/12/13 17:51:37 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	dest = malloc ((ft_strlen((char *)s1) + ft_strlen((char *)s2)) + 1);
	if (!dest)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		dest[i] = s2[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
// #include <stdio.h>
// int main() {
//     const char *s1 = "Hola, ";
//     const char *s2 = "mundo!";
//     char *result = ft_strjoin(s1, s2);
// 	printf("Resultado: %s\n", result);
//         free(result);
//     return 0;
// }