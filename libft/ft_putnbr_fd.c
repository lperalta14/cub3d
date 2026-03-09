/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:33:56 by anzarago          #+#    #+#             */
/*   Updated: 2024/12/13 18:35:27 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		mod;
	int		div;
	char	a;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n = n * -1;
	}
	mod = n % 10;
	div = n / 10;
	if (div > 0)
	{
		ft_putnbr_fd (div, fd);
	}
	a = mod + '0';
	write (fd, &a, 1);
}
// int main()
// {
// 	ft_putnbr_fd(1245,1);
// 	return(0);
// }