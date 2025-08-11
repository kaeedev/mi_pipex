/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:42:14 by luviso-p          #+#    #+#             */
/*   Updated: 2025/04/30 11:34:23 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*ptr;
	char		target;

	ptr = (const char *)s;
	target = (char)c;
	if (n > 0)
	{
		if (*ptr == target)
		{
			return ((void *)ptr);
		}
		return (ft_memchr(ptr + 1, c, n - 1));
	}
	return (NULL);
}

/*int	main(void) 
{
    unsigned char buffer[] = {'h', 'r', '4', 'e','0'};

    void *result = ft_memchr(buffer, 'g', sizeof(buffer));

    if (result != NULL) {
        printf("Valor encontrado en la posicion: %ld\n", 
	(unsigned char *)result - buffer);
    } else {
        printf("Valor no encontrado\n");
    }

    return 0;
}*/
