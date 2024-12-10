/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:49:56 by tbeyel            #+#    #+#             */
/*   Updated: 2024/11/18 15:46:41 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*fills the first n bytes of the memory area pointed to by s with the constant 
byte c*/

void	*ft_memset(void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*s2;

	i = 0;
	s2 = (unsigned char *)s;
	while (i < n)
	{
		s2[i] = c;
		i++;
	}
	return (s);
}
