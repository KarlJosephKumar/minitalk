/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:50:52 by kakumar           #+#    #+#             */
/*   Updated: 2023/02/21 18:41:00 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_linlist **lst, t_linlist *new)
{
	t_linlist	*temp_list;	

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp_list = *lst;
	while (temp_list->next != NULL)
		temp_list = temp_list->next;
	temp_list->next = new;
}
