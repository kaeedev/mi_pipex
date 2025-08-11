/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:49:30 by luviso-p          #+#    #+#             */
/*   Updated: 2025/04/30 10:02:59 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	while (*s)
	{
		if ((unsigned char)*s == ch)
		{
			return ((char *)s);
		}
		s++;
	}
	if (ch == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}

/*int	main(void)
{
    const char *texto = "Hola, mundo";
    char caracter = 'H';
    char *resultado = ft_strchr(texto, caracter);

    if (resultado != NULL) {
    printf("El carácter '%c' fue encontrado en la posición: 
    			%ld\n", caracter, resultado - texto);
    } else {
        printf("El carácter '%c' no fue encontrado.\n", caracter);
    }

    return 0;
}*/
