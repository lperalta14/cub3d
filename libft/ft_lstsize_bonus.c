/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:50:43 by anzarago          #+#    #+#             */
/*   Updated: 2024/12/18 11:59:51 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// #include <stdio.h>
// int main()
// {
// 	t_list *node1;
// 	t_list *node2;
// 	t_list *node3;
// 	node1 = (t_list*)malloc(sizeof(t_list));
// 	node2 = (t_list*)malloc(sizeof(t_list));
// 	node3 = (t_list*)malloc(sizeof(t_list));
// 	node1->next = node2;
// 	node2->next = node3;
// 	node3->next = NULL;
// 	printf("%d \n", ft_lstsize(node1));
// 	free(node1);
// 	free(node2);
// 	free(node3);
// 	return (0);
// }