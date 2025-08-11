/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:28:25 by luviso-p          #+#    #+#             */
/*   Updated: 2025/05/06 10:40:02 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del(void *content)
{
	free(content);
}
void	ft_lstdelone(t_list *lst, void(*del)(void *))
{
	if(lst && del)
		del(lst->content);
	free(lst);
}
