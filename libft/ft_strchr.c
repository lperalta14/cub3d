/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:17:22 by anzarago          #+#    #+#             */
/*   Updated: 2024/12/16 16:24:35 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == uc)
		{
			return ((char *)(&s[i]));
		}
		i++;
	}
	if (uc == '\0')
		return ((char *)(&s[i]));
	return (NULL);
}

// #include <stdio.h>
// int main ()
// {
//     printf("%s",ft_strchr("hola",'l'));
//     return(0);
// }