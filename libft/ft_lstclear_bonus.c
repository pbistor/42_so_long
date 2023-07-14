/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprieto- <vprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:28:03 by vprieto-          #+#    #+#             */
/*   Updated: 2022/10/07 21:10:12 by vprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*temp;

	if (del && lst && *lst)
	{
		node = *lst;
		while (node != NULL)
		{
			temp = node;
			del(temp->content);
			node = node->next;
			free(temp);
		}
		*lst = NULL;
	}
}
