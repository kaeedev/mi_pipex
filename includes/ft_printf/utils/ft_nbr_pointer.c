/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:14:22 by luviso-p          #+#    #+#             */
/*   Updated: 2025/05/28 11:25:52 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_nbr_pointer(unsigned long ptr)
{
	int		len;

	len = 0;
	if (!ptr)
	{
		len += ft_putstr("(nil)");
		return (5);
	}
	len += ft_putstr("0x");
	len += ft_nbr_hex(ptr, 'x');
	return (len);
}
