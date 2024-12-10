/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:52:08 by tbeyel            #+#    #+#             */
/*   Updated: 2024/12/09 14:01:40 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*copy strings, it take the full size of the buffer (length + '\0')*/

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	int		len;

	i = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	if (len == 0)
	{
		dst[0] = '\0';
		return (len);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
