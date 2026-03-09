/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:41:07 by anzarago          #+#    #+#             */
/*   Updated: 2024/12/16 15:05:18 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c < 128)
		return (1);
	return (0);
}

// #include <stdio.h>
// int main ()
// {
// 	int a;
// 	a = 128;
// 	while (a <= 138)
// 	{
// 	printf("%d", ft_isascii(a));
// 	a++;
// 	}
// 	return (0);
// }