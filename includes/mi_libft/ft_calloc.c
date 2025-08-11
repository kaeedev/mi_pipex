/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:15:12 by luviso-p          #+#    #+#             */
/*   Updated: 2025/04/30 11:34:50 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
	{
		return (NULL);
	}
	while (i < nmemb * size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

/*int	main(void)
{
	int	*nums;
	int	i;

	nums = (int *)ft_calloc(5, sizeof(int));
	i = 0;
	while (i < 5)
	{
		printf("%d ", nums[i]);
		i++;
	}
	printf("\n");

	free(nums);
	return (0);
}*/
