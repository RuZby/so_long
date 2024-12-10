/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:52:07 by tbeyel            #+#    #+#             */
/*   Updated: 2024/11/18 15:46:41 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*copies n bytes from memory area src to memory area dest*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			n2;
	unsigned char	*dest2;
	unsigned char	*src2;

	n2 = 0;
	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n2 < n)
	{
		dest2[n2] = src2[n2];
		n2++;
	}
	return (dest);
}
