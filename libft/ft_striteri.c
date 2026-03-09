/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:24:22 by anzarago          #+#    #+#             */
/*   Updated: 2024/12/13 18:39:17 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))

{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>
// void ft_tolower_striteri(unsigned int i, char *c)
// {
//     (void)i;
//     if (*c >= 'A' && *c <= 'Z')
//         *c = *c + ('a' - 'A');
// }
// int main()
// {
// 	char str[] = "TEAR";
// 	char *result = str;
// 	ft_striteri(str,ft_tolower_striteri);
// 	printf("%s",result);
// 	return (0);
// }