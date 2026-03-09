/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:17:30 by anzarago          #+#    #+#             */
/*   Updated: 2024/12/13 13:16:55 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(char *s, size_t n)
{
	ft_memset(s, 0, n);
}
// #include <stdio.h>

// int main ()
// {
// 	char str[] = "hola que tal?";
// 	char *test = str;
// 	ft_bzero(str, 4);
// 	printf("%s",test);
// 	return (0);
// }