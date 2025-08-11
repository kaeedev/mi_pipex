/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:49:56 by luviso-p          #+#    #+#             */
/*   Updated: 2025/04/24 14:09:47 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && s1[i] && s2[i] && (s1[i] == s2[i]))
	{
		i++;
	}
	if ((i == n) || (s1[i] == s2[i]))
	{
		return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*int   main(void)
{
	char    str1[] = "Ha salido el silksong";
	char    str2[] = " a salido el silksong";

	printf("Comparando las dos cadenas: %d\n", ft_strncmp(str1, str2, 20));
	return (0);
}*/
