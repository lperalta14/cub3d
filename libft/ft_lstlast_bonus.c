/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:11:51 by anzarago          #+#    #+#             */
/*   Updated: 2024/12/18 11:56:28 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
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
// 	node1->content = "CA";
// 	node2->content = "GB";
// 	node3->content = "SP";
// 	t_list	*last_node = ft_lstlast(node1);
// 	printf("%s\n", (char *)last_node->content);
// 	free(node1);
// 	free(node2);
// 	free(node3);
// 	return (0);	
// }