/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:33:48 by anzarago          #+#    #+#             */
/*   Updated: 2024/12/16 19:10:07 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		ft_memcpy (dest, src, n);
	}
	else
	{
		while (n > 0)
		{
			n--;
			((char *) dest)[n] = ((char *) src)[n];
		}
	}
	return (dest);
}

// #include <stdio.h>

// int main ()
// {
// 	char str[] = "HOLA QUE TAL";
// 	char a[] = "hooooooooooooooooo";
// 	ft_memmove(a, str, 6);
// 	printf("%s",a);
// 	return(0);
// }