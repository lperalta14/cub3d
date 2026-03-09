/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:38:39 by anzarago          #+#    #+#             */
/*   Updated: 2024/12/17 19:44:27 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new ->next = *lst;
	*lst = new;
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	t_list *lst = NULL;
// 	t_list *node1 = ft_lstnew("Argelia");
// 	t_list *node2 = ft_lstnew("Belgica");
// 	t_list *node3 = ft_lstnew("Canada");
// 	lst = node1;
// 	node1->next = node2;
// 	node2->next = node3;
// 	node3->next = NULL;
// 	printf("before: ");
// 	t_list *temp = lst;
// 	while (temp)
// 	{
// 		printf(" %s ->",(char *)temp->content);
// 		temp = temp -> next;
// 	}
// 	printf("NULL");
// 	t_list *new_node = ft_lstnew("Alemania");
// 	ft_lstadd_front(&lst, new_node);
// 	printf("\nafter: ");
// 	temp = lst;
// 	while(temp)
// 	{
// 		printf("%s ->", (char *)temp->content);
// 		temp = temp -> next;
// 	}
// 	printf("NULL");
// 	free(node1);
// 	free(node2);
// 	free(node3);
// 	free(new_node);
// 	return (0);
// }