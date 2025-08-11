/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:30:31 by luviso-p          #+#    #+#             */
/*   Updated: 2025/04/23 14:33:29 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"
//#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*origen;
	size_t		i;
	char		*destino;

	i = 0;
	origen = (char *)(src);
	destino = (char *)(dest);
	if (dest == NULL && src == NULL)
	{
		return (dest);
	}
	while (i < n)
	{
		destino[i] = origen[i];
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	char	destino[30];
	char	*origen = "ESTOY DENTRISIMO";

	//printf("%s\n", memcpy(destino, origen, 1));
	printf("%s\n", ft_memcpy(destino, origen, 0));
	return (0);
}*/
