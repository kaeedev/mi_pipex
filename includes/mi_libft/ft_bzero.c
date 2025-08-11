/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:43:13 by luviso-p          #+#    #+#             */
/*   Updated: 2025/04/22 15:14:03 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

/*int	main(void)
{
	char str[] = "Hola Pacooo";
	int		i;
	
	i = 0;
	ft_bzero(str, 3);
	while(i < 11)
	{
		printf("%d\n", str[i]);
		i++;
	}
	return (0);
}*/
