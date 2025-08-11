/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:13:54 by luviso-p          #+#    #+#             */
/*   Updated: 2025/04/30 09:43:13 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*copy;

	i = 0;
	copy = (char *)malloc(ft_strlen(s) + 1);
	if (!copy)
	{
		return (NULL);
	}
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/*int main(void)
{
    char *original = "Hola mundo";
    char *copia = strdup(original);

    printf("Original: %s\n", original);
    printf("Copia: %s\n", copia);

    free(copia);
    return 0;
}*/
