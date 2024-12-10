/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:03:21 by tbeyel            #+#    #+#             */
/*   Updated: 2024/12/09 14:22:45 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putpointer(unsigned long int addr)
{
	int	i;

	i = 0;
	if (addr == 0)
	{
		ft_putstrprintf("(nil)");
		return (5);
	}
	write(1, "0x", 2);
	i += 2;
	i += int_to_hexa(addr, 1);
	return (i);
}
