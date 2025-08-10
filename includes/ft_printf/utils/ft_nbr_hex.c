/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:45:09 by luviso-p          #+#    #+#             */
/*   Updated: 2025/05/28 11:25:45 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_nbr_hex(unsigned long nbr, char upper)
{
	char	*set;
	int		count_char;

	count_char = 0;
	if (upper == 'x')
		set = "0123456789abcdef";
	else
		set = "0123456789ABCDEF";
	if (nbr >= 16)
		count_char += ft_nbr_hex((nbr / 16), upper);
	count_char += ft_putchar(set[nbr % 16]);
	return (count_char);
}
