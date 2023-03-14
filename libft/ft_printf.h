/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:31:19 by kakumar           #+#    #+#             */
/*   Updated: 2022/12/17 15:08:39 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_putchar_count(char c, int count);
int		ft_printf(const char *input, ...);
int		ft_putstr_count(char *s, int count);
int		ft_putpointer_count(uintptr_t ptr, int counter);
int		ft_putnbr_count(int n, int count);
int		ft_putusnbr_count(unsigned int n, int count);
int		ft_putuphex_count(unsigned int n, int counter);
int		ft_putlohex_count(unsigned int n, int counter);
#endif