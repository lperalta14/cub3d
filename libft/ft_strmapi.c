/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:41:53 by anzarago          #+#    #+#             */
/*   Updated: 2024/12/13 18:42:20 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new_str;

	new_str = malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!new_str)
		return (0);
	i = 0;
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// #include <stdio.h>
// char ft_tolower_mapi(unsigned int i, char c)
// {
//     (void)i;
//     if (c >= 'A' && c <= 'Z')
//         c = c + ('a' - 'A');
//     return c;
// }
// int main()
// {
// 	char *str = "TEAR";
// 	char *result = ft_strmapi(str,ft_tolower_mapi);
// 	printf("%s",result);
// 	return (0);
// }