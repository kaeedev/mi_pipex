/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:43:34 by luviso-p          #+#    #+#             */
/*   Updated: 2025/05/28 11:24:47 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *s);
int		ft_putnbr(int n);
int		ft_putnbru(unsigned int n);
int		ft_nbr_hex(unsigned long nbr, char upper);
int		ft_nbr_pointer(unsigned long ptr);
int		ft_printf(const char *format, ...);
int		ft_search_types(char specifier, va_list args);
#endif
