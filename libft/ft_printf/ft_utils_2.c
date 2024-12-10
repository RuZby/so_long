/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:04:38 by tbeyel            #+#    #+#             */
/*   Updated: 2024/12/09 14:22:34 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int nb)
{
	int		i;
	char	a;

	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
		i += 1;
	}
	if (nb >= 10)
		i += ft_putnbr(nb / 10);
	a = nb % 10 + '0';
	write(1, &a, 1);
	return (i + 1);
}

int	int_to_hexa(unsigned long int nb, int a)
{
	char	*hex;
	int		i;

	i = 0;
	if (a == 1)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (nb >= 16)
		i += int_to_hexa(nb / 16, a);
	write(1, &hex[nb % 16], 1);
	return (i + 1);
}

int	ft_putnbr_u(unsigned int u)
{
	int	i;

	i = 0;
	if (u >= 10)
		i += ft_putnbr_u(u / 10);
	ft_putchar(u % 10 + '0');
	return (i + 1);
}

int	ft_putstrprintf(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (ft_putstrprintf("(null)"));
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}
