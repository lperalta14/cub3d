/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:19:00 by anzarago          #+#    #+#             */
/*   Updated: 2025/04/04 17:48:17 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				count;
	unsigned int	nb;

	count = ft_counter(n);
	str = (char *)malloc(count + 1);
	if (!str)
		return (0);
	str[count] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		nb = -n;
	}
	else
		nb = n;
	while (count > 0)
	{
		if (n < 0 && count == 1)
			break ;
		str[count - 1] = (nb % 10) + '0';
		nb = nb / 10;
		count--;
	}
	return (str);
}

// #include <stdio.h>
// int main()
// {
// 	char *a = ft_itoa(142);
// 	printf("%s", a);
// 	return(0);
// }
