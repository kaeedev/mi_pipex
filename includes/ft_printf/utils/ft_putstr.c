/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:02:07 by luviso-p          #+#    #+#             */
/*   Updated: 2025/05/28 11:25:28 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr(char *s)
{
	size_t	len;

	if (!s)
	{
		if (write(1, "(null)", 6) == 6)
			return (6);
		return (0);
	}
	len = ft_strlen(s);
	write(1, s, len);
	return ((int)len);
}
