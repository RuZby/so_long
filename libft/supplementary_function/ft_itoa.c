/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:50:06 by tbeyel            #+#    #+#             */
/*   Updated: 2024/11/18 15:46:43 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

static char	*ft_itoa2(int n, char *tab, int size)
{
	int	i;

	i = 0;
	if (n < 0)
		tab[0] = '-';
	if (n == 0)
		tab[size - 1] = '0';
	while (n != 0)
	{
		tab[size - i - 1] = ft_abs(n % 10) + 48;
		n = n / 10;
		i++;
	}
	tab[size] = '\0';
	return (tab);
}

char	*ft_itoa(int n)
{
	int		size;
	int		n2;
	char	*tab;

	size = 0;
	n2 = n;
	while (n2 != 0)
	{
		n2 = n2 / 10;
		size++;
	}
	if (n <= 0)
		size++;
	tab = (char *)malloc((size + 1) * (sizeof(char)));
	if (tab == NULL)
		return (NULL);
	return (ft_itoa2(n, tab, size));
}
