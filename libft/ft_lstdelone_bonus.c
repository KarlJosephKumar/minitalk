/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:07:03 by kakumar           #+#    #+#             */
/*   Updated: 2023/02/21 18:41:13 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_linlist *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	(*del)((void *)lst);
	free(lst->content);
}
