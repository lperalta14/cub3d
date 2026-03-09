/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:38:43 by anzarago          #+#    #+#             */
/*   Updated: 2024/12/17 15:51:33 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node1;

	node1 = (t_list *)malloc(sizeof(t_list));
	if (!node1)
		return (NULL);
	node1 -> content = content;
	node1 -> next = NULL;
	return (node1);
}
// #include <stdio.h>
// int main()
// {
// 	char *test = "Belgium";
// 	t_list *node1 = ft_lstnew(test);
// 	if (node1 != NULL)
// 		printf("%s",((char *)node1 -> content));
// 	free(node1);
// 	return 0;
// }
