/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:18:01 by anzarago          #+#    #+#             */
/*   Updated: 2024/12/16 18:06:10 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == uc)
		{
			return ((char *)(&s[i]));
		}
		i--;
	}
	return (0);
}
// #include <stdio.h>
// int main ()
// {
//     printf("%s",ft_strrchr("holaquepasalapasamosbien?",'l'));
//     return(0);
// }