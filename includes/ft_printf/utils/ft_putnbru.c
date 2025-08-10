/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:25:37 by luviso-p          #+#    #+#             */
/*   Updated: 2025/05/28 11:24:39 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbru(unsigned int n)
{
	int	count_char;

	count_char = 0;
	if (n >= 10)
		count_char += ft_putnbr(n / 10);
	count_char += ft_putchar((n % 10) + '0');
	return (count_char);
}
