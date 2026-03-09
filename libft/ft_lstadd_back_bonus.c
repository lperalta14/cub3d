/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:11:42 by anzarago          #+#    #+#             */
/*   Updated: 2024/12/18 11:59:13 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

// #include <stdio.h>
// int main()
// {
// 	t_list *node1;
// 	t_list *node2;
// 	t_list *node_new;
// 	node1 = (t_list*)malloc(sizeof(t_list));
// 	node2 = (t_list*)malloc(sizeof(t_list));
// 	node_new = (t_list*)malloc(sizeof(t_list));
// 	node1->next = node2;
// 	node2->next = NULL;
// 	node1->content = "CA";
// 	node2->content = "GB";
// 	node_new->content = "NEW";
// 	ft_lstadd_back(&node1,node_new);
// 	t_list	*list = node1;
// 	while(list)
// 	{
// 		printf("%s\n",(char *)list->content);
// 		list = list->next;
// 	}
// 	free(node1);
// 	free(node2);
// 	free(node_new);
// 	return (0);	
// }
