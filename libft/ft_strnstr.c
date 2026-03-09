/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:02:05 by anzarago          #+#    #+#             */
/*   Updated: 2024/12/13 17:46:43 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		while (little[j] != '\0' && little[j] == big[i + j] && (i + j) < len)
			j++;
		if (little[j] == '\0')
		{
			return ((char *)big + i);
		}
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int main ()
// {
// 	char	a[] = "Hola, amigui! ";
// 	char	b[] = "amig";
// 	char *result = ft_strnstr(a,b,12);
// 	printf("%s",result);
// }