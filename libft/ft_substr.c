/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:59:17 by anzarago          #+#    #+#             */
/*   Updated: 2024/12/16 18:42:23 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen((s));
	if (!s)
		return (NULL);
	if (start >= l)
		return (ft_strdup (""));
	if (len > (l - start))
		len = l - start;
	dest = (char *)malloc(len * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// #include <stdio.h>
// int main() {
//     const char *str = "Hola, mundo!";
//     unsigned int start = 7;
//     size_t len = 5;
//     // Llamamos a la función ft_substr para obtener el substring
//     char *substr = ft_substr(str, start, len);
//     if (substr) {
//         printf("Substring: %s\n", substr);  // Debería imprimir "mundo"
//         free(substr);  // No olvidar liberar la memoria
//     } else {
//         printf("No se pudo crear el substring.\n");
//     }
//     return 0;
// }