/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:25:38 by tbeyel            #+#    #+#             */
/*   Updated: 2024/12/09 14:02:38 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen_char(char *s, char c)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s && s[len] && s[len] != c)
		len++;
	if (s[len] == c && c != '\0')
		len++;
	return (len);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen_char(s2, '\n') + 1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dst = (char *)malloc((len) * sizeof(char));
	if (dst == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(dst, s1, len);
	ft_strlcat(dst, s2, len);
	free(s1);
	return (dst);
}
