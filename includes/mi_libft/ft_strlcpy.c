/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:40:48 by luviso-p          #+#    #+#             */
/*   Updated: 2025/04/24 08:53:45 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

/*int	main(void)
{
	char	dst[10];
	char	*src = "PO VALEEEEEEEEEE";
	size_t	len1;
	
	len1 = ft_strlcpy(dst, src, sizeof(dst));
	printf("Cadena destino: '%s'\n", dst);
	printf("Longitud retornada: %zu\n", len1);
	printf("Longitud original de src: %zu\n", strlen(src));
	printf("Tamaño del destino: %zu\n", sizeof(dst));
	return (0);
}*/
