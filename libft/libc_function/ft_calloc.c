/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:07:24 by tbeyel            #+#    #+#             */
/*   Updated: 2024/11/18 15:46:39 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* allocates memory for an array of nmemb elements of size  bytes  each and  
returns  a  pointer to the allocated memory.  The memory is set to zero.*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;
	int		i;
	size_t	len;

	i = 0;
	len = nmemb * size;
	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (len / nmemb != size)
		return (NULL);
	memory = (void *)malloc(len);
	if (memory == NULL)
		return (NULL);
	ft_bzero(memory, len);
	return (memory);
}
