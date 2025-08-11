/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:25:21 by luviso-p          #+#    #+#             */
/*   Updated: 2025/04/30 10:02:24 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	i = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}

/*int main() {
    char buffer1[] = "Hola, mundo!";
    char buffer2[] = " ola, mundo!";

    int result = ft_memcmp(buffer1, buffer2, sizeof(buffer1));

    if (result == 0) {
        printf("Los bloques de memoria son iguales.\n");
    } else if (result < 0) {
        printf("El primer bloque es menor que el segundo.\n");
    } else {
        printf("El primer bloque es mayor que el segundo.\n");
    }

    return 0;
}*/
