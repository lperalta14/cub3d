/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:34:34 by anzarago          #+#    #+#             */
/*   Updated: 2024/12/13 17:45:39 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	ptr = malloc(size * nmemb);
	if (ptr == 0)
		return (0);
	if (ptr)
		ft_bzero(ptr, (size * nmemb));
	return (ptr);
}

// #include <stdio.h>
// int main() 
// {
//     int *arr;
//     int n = 5;
//     arr = (int*) ft_calloc(n, sizeof(int));
//     if (arr == NULL) {
//         printf("Error al asignar memoria.\n");
//         return 1;
//     }
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }
//     free(arr);  // Liberar memoria
//     return 0;
// }