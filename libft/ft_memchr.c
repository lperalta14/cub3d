/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:47:08 by anzarago          #+#    #+#             */
/*   Updated: 2024/12/13 17:26:43 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((((unsigned char *)s)[i]) == ((unsigned char)c))
		{
			return ((unsigned char *)&s[i]);
		}
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int main ()
// {
//  char a[] = "hola";
// 	int x = 'l';
// 	void *result = ft_memchr(a,x,4);
// 	printf("%s",(char*)result);
//     return(0);
// }