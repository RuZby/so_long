/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:47:57 by tbeyel            #+#    #+#             */
/*   Updated: 2024/11/18 15:46:42 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*return a pointer of the last occurence of the character c in the string s or 
NULL if the character is not found*/

char	*ft_strrchr(const char *s, int c)
{
	char	*s2;
	int		i;

	s2 = (char *)s;
	i = ft_strlen(s2) - 1;
	c = (unsigned char)c;
	if (c == '\0')
		return (s2 + ft_strlen(s2));
	while (i >= 0)
	{
		if (s2[i] == c)
			return (s2 + i);
		i--;
	}
	return (NULL);
}
