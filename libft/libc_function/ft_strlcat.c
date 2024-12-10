/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:07:28 by tbeyel            #+#    #+#             */
/*   Updated: 2024/12/09 14:02:12 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*concatenate strings, it take the full size of the buffer (lenngth + '\0')*/

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	unsigned int	sizedst;
	unsigned int	sizesrc;
	unsigned int	i;

	sizesrc = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (sizesrc);
	sizedst = ft_strlen(dst);
	if (size <= sizedst)
		return (size + sizesrc);
	while (src[i] != '\0' && sizedst + i < size - 1)
	{
		dst[sizedst + i] = src[i];
		i++;
	}
	dst[i + sizedst] = '\0';
	return (sizedst + sizesrc);
}
