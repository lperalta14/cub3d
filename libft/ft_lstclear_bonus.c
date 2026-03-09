/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:08:49 by anzarago          #+#    #+#             */
/*   Updated: 2024/12/18 17:34:55 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!*lst || !del || !lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}
// void	del(void *content)
// {
// 	free(content);
// }

// void lstprint(t_list *lst)
// {
// 	while (lst)
//     {
// 	printf("%s -> ", (char *)lst->content);
// 		lst = lst->next;
// 	}
// }

// #include <stdio.h>
// int main()
// {
// 	t_list *list = NULL;
// 	t_list *node1;
// 	t_list *node2;
// 	t_list *node3;

// 	node1 = (t_list*)malloc(sizeof(t_list));
// 	node2 = (t_list*)malloc(sizeof(t_list));
// 	node3 = (t_list*)malloc(sizeof(t_list));

// 	if (!node1 || !node2 || !node3)
// 		return (0);

// 	node1->next = node2;
// 	node2->next = node3;
// 	node3->next = NULL;

// 	node1->content = "CA";
// 	node2->content = "GB";
// 	node3->content = "US";

// 	list = node1;
// 	printf("before:");
// 	lstprint(list);

// 	ft_lstclear(&list, del);
// 	printf("after");
// 	lstprint(list);

// 	return(0);
// }
