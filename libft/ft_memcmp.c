/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:32:10 by anzarago          #+#    #+#             */
/*   Updated: 2024/12/16 18:16:01 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		if (((((unsigned char *)s1)[i])) > (((unsigned char *)s2)[i]))
			return (1);
		if (((((unsigned char *)s1)[i])) < (((unsigned char *)s2)[i]))
			return (-1);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int main ()
// {
//  	char a[] = "hola";
// 	char x[]= "holaa";
// 	int result = ft_memcmp(a,x,7);
// 	printf("%d",result);
//     return(0);
// }