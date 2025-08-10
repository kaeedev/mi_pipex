/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:26:14 by luviso-p          #+#    #+#             */
/*   Updated: 2025/05/28 12:17:44 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr(int n)
{
	int	count_char;

	count_char = 0;
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == 11)
			count_char = 11;
		return (count_char);
	}
	if (n < 0)
	{
		count_char += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count_char += ft_putnbr(n / 10);
	count_char += ft_putchar((n % 10) + '0');
	return (count_char);
}
