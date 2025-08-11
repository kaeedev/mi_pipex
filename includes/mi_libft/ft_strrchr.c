/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:02:14 by luviso-p          #+#    #+#             */
/*   Updated: 2025/04/29 11:33:12 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ultima_ocurrencia;

	ultima_ocurrencia = NULL;
	if ((char)c == '\0')
		return ((char *)(s + ft_strlen(s)));
	if (*s == '\0')
		return (NULL);
	if ((char)c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == (char)c)
			ultima_ocurrencia = s;
		s++;
	}
	return ((char *)ultima_ocurrencia);
}

/*int	main(void)
{
    char texto[] = "Hola mundo";
    char caracter = 'a';

    char *resultado = ft_strrchr(texto, caracter);
    if (resultado != NULL) {
        printf("Última aparición de '%c': %s\n", caracter, resultado);
    } else {
        printf("Carácter '%c' no encontrado.\n", caracter);
    }

    return 0;
}*/
