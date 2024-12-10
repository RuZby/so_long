/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:36:03 by tbeyel            #+#    #+#             */
/*   Updated: 2024/11/18 15:46:41 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*copues n bytes from memory area src to memory area dest but the copy is more
secure than ft_memecpy*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src2;
	unsigned char	*dest2;

	if (dest == NULL && src == NULL)
		return (NULL);
	src2 = (unsigned char *)src;
	dest2 = (unsigned char *)dest;
	if ((src < dest) && (src + n > dest))
	{
		while (n - 1 > 0)
		{
			dest2[n - 1] = src2[n - 1];
			n--;
		}
		dest2[n - 1] = src2[n - 1];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
