/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:55:08 by luviso-p          #+#    #+#             */
/*   Updated: 2025/04/24 14:10:48 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*origen;
	char	*destino;
	size_t	i;

	origen = (char *)src;
	destino = (char *)dest;
	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	if (destino > origen)
	{
		while (n-- > 0)
			destino[n] = origen[n];
	}
	else
	{
		while (i < n)
		{
			destino[i] = origen[i];
			i++;
		}
	}
	return (dest);
}

/*int	main(void)
{
	char	str[] = "Holaaaaa";
	char	destino[50];

	ft_memmove(destino, str, strlen(str) + 1);
	//memmove(destino, str, strlen(str) + 1);
	printf("Resultado: %s\n", destino);
	return (0);
}*/
