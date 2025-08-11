/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:56:57 by luviso-p          #+#    #+#             */
/*   Updated: 2025/04/30 09:53:45 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!big && len == 0)
	{
		return (0);
	}
	if (!*little)
	{
		return ((char *)big);
	}
	while (*big && len > 0)
	{
		i = 0;
		while ((i < len) && (big[i] == little[i]) && little[i])
		{
			i++;
		}
		if (little[i] == '\0')
		{
			return ((char *)big);
		}
		big++;
		len--;
	}
	return (0);
}

/*int	main(void)
{
	const char	*text = "Hola mundo";
	const char	*word = "lA";
	char	*found = ft_strnstr(text, word, 8);

	if (found)
	{
		printf("Encontrado: %s\n", found);
	}
	else
	{
		printf("No encontrado\n");
	}
	return (0);
}*/
