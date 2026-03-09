/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:48:11 by anzarago          #+#    #+#             */
/*   Updated: 2024/10/13 13:27:19 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	i = 0;
	dest_len = 0;
	src_len = 0;
	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (size <= dest_len)
		return (size + src_len);
	while (src[i] != '\0' && dest_len + i < size -1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
//#include <stdio.h>
//
//int main ()
//{
//	char	dest[20] = "Hola, ";
//	char *src = "mundo!";	
//	unsigned int result = ft_strlcat(dest, src, 4);
//	printf("Resultado: %s\n", dest);
//	printf("Longitud total: %u\n", result);
//
//	return 0
//}
