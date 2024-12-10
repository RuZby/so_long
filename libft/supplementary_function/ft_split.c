/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:01:20 by tbeyel            #+#    #+#             */
/*   Updated: 2024/11/18 15:46:44 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	if (ft_strlen(s) == 0)
		return (0);
	if (s[0] != c)
		count++;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static char	*ft_strndup(const char *s, char c)
{
	char	*dst;
	int		i;

	i = 0;
	while (s && s[i] != '\0' && s[i] != c)
		i++;
	dst = (char *)malloc(i * sizeof(char) + 1);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (s && s[i] != '\0' && s[i] != c)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static void	*ft_free(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*s2;
	size_t	i;
	size_t	j;

	s2 = (char *)s;
	((void)0, i = 0, j = 0);
	if (s == NULL)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (count_words(s2, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (j <= ft_strlen(s2))
	{
		tab[i] = ft_strndup((s2 + j), c);
		if (tab[i] == NULL)
			return (ft_free(tab, (int)i));
		j = j + ft_strlen(tab[i]) + 1;
		if (tab[i][0] != '\0')
			i++;
		else
			free(tab[i]);
	}
	tab[i] = NULL;
	return (tab);
}
