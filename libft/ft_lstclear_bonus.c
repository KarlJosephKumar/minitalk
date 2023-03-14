/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:17:04 by kakumar           #+#    #+#             */
/*   Updated: 2023/02/21 18:41:09 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_linlist **lst, void (*del)(void *))
{
	t_linlist	*temp;
	t_linlist	*next;

	if (*lst == NULL || del == NULL)
		return ;
	temp = *lst;
	if (temp == NULL)
		return ;
	next = temp->next;
	while (next)
	{
		next = temp->next;
		del(temp->content);
		free(temp);
		temp = next;
	}
	free(temp);
	free(next);
	*lst = NULL;
}
