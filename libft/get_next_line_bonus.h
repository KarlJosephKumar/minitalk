/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:02:47 by kakumar           #+#    #+#             */
/*   Updated: 2022/12/16 18:12:33 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_variables
{
	int		i;
	int		j;
	char	*ret;
	char	*buff;
	char	*temp;
	int		bytes;
	int		eol;
	int		k;
}				t_variable;

char	*get_next_line(int fd);
char	*read_buffer(int fd, t_variable var, char *holder);
char	*get_line(t_variable var, char *holder);
char	*update_holder(t_variable var, char *holder);
int		slen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
#endif