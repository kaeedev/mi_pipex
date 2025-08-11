/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:29:05 by luviso-p          #+#    #+#             */
/*   Updated: 2025/04/30 09:44:17 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] == ' ') || ((nptr[i] >= 9) && (nptr[i] <= 13)))
		i++;
	while ((nptr[i] == '+') || (nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
		if ((nptr[i] == '+') || (nptr[i] == '-'))
			return (0);
	}
	while ((nptr[i] >= 48) && (nptr[i] <= 57))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

/*int	main(void)
{
	char	str[] = " -+-+1234dvf54";
	char	str2[] = "+dwd43";
	char	str3[] = "-42";
	printf("%d\n", ft_atoi(str));
	printf("%d\n", ft_atoi(str2));
	printf("%d\n", ft_atoi(str3));
	printf("%d\n", atoi(str3));
	printf("%d\n", atoi(str2));
	return (0);
}*/
