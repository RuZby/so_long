/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:34:26 by tbeyel            #+#    #+#             */
/*   Updated: 2024/11/18 15:46:39 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*Erases the data in the n bytes of the memory starting at the location pointed
 by s, by written zeros*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
