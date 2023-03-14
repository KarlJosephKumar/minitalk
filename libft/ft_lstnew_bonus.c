/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:10:15 by kakumar           #+#    #+#             */
/*   Updated: 2023/02/21 18:41:23 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_linlist	*ft_lstnew(void *content)
{
	t_linlist	*l;

	l = malloc(sizeof(t_linlist));
	if (!l)
		return (0);
	l->content = content;
	l->next = 0;
	return (l);
}
