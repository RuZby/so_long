/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:22:44 by tbeyel            #+#    #+#             */
/*   Updated: 2024/12/09 16:28:42 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_printf2(char c, int g_count, va_list ptr)
{
	if (c == 'd' || c == 'i')
		g_count += ft_putnbr(va_arg(ptr, int));
	else if (c == 's')
		g_count += ft_putstrprintf(va_arg(ptr, char *));
	else if (c == 'c')
		g_count += ft_putchar((unsigned char)va_arg(ptr, int));
	else if (c == '%')
		g_count += ft_putchar('%');
	else if (c == 'p')
		g_count += ft_putpointer((unsigned long int)va_arg(ptr, void *));
	else if (c == 'x')
		g_count += int_to_hexa((unsigned int)va_arg(ptr, unsigned int), 1);
	else if (c == 'X')
		g_count += int_to_hexa((unsigned int)va_arg(ptr, unsigned int), 0);
	else if (c == 'u')
		g_count += ft_putnbr_u((unsigned int)va_arg(ptr, unsigned int));
	else if (c == '\0')
		return (-1);
	else
	{
		g_count += ft_putchar('%');
		g_count += ft_putchar(c);
	}
	return (g_count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		g_count;
	int		i;

	i = 0;
	g_count = 0;
	va_start(ptr, format);
	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			g_count = ft_printf2(format[i + 1], g_count, ptr);
			if (format[i + 1] != '\0')
				i++;
		}
		else
			g_count += ft_putchar(format[i]);
		i++;
	}
	va_end(ptr);
	return (g_count);
}
