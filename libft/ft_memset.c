/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:16:30 by anzarago          #+#    #+#             */
/*   Updated: 2024/12/13 16:55:56 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *) s;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}

// #include <stdio.h>
// int main ()
// {
// 	char str[] = "hola que tal?";
// 	int		a = 's';
// 	ft_memset(str, a, 4);
// 	printf("%s",str);
// 	return (0);
// }