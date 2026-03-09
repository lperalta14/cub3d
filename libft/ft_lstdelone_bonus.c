/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:02:59 by anzarago          #+#    #+#             */
/*   Updated: 2024/12/18 11:59:27 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst && !del)
		return ;
	del(lst->content);
	free (lst);
}
// void	del(void *content)
// {
// 	free(content);
// }
// #include<stdio.h>

// int main()
// {
// 	t_list *node=malloc(sizeof(t_list));
// 	if (!node)
// 		return (0);
// 	char *content = malloc(ft_strlen("Italy") + 1);
// 	if(!content)
// 	{
// 		free(node);
// 		return(0);
// 	}
// 	node->content = "Italy";
// 	node->next = NULL;
// 	printf("before: %s\n",(char*)node->content);
// 	ft_lstdelone(node,del);
// 	printf("after: %s\n",(char *)node->content);
// 	return(0);
// }
