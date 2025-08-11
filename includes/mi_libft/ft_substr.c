/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:55:03 by luviso-p          #+#    #+#             */
/*   Updated: 2025/04/30 09:58:15 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	maxlen;
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	maxlen = slen - start;
	if (len > maxlen)
		len = maxlen;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/*int	main(void)
{
    char *original = "Hola mundo!";
    char *sub1 = ft_substr(original, 0, 4);  
    char *sub2 = ft_substr(original, 5, 5); 
    char *sub3 = ft_substr(original, 20, 5);
    char *sub4 = ft_substr(original, 3, 50);

    printf("Sub1: '%s'\n", sub1);
    printf("Sub2: '%s'\n", sub2);
    printf("Sub3: '%s'\n", sub3);
    printf("Sub4: '%s'\n", sub4);

    free(sub1);
    free(sub2);
    free(sub3);
    free(sub4);

    return 0;
}*/
