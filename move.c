/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:35:21 by tbeyel            #+#    #+#             */
/*   Updated: 2024/12/13 14:35:45 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_move(char **map, t_pos pos, t_vars *vars)
{
	if (map[pos.y][pos.x] == 'E' && ft_amount_collectible(map) == 0)
	{
		ft_printf("\033[1;32m--------------------\n");
        ft_printf("|     You win      |\n");
        ft_printf("|      GG WP       |\n");
        ft_printf("--------------------\033[0m\n");
		close_win(vars);
	}
	if (map[pos.y][pos.x] == 'C' || map[pos.y][pos.x] == '0')
	{
		if (map[pos.y][pos.x] == 'C')
			ft_printf("\033[1;33mYou collected a coin\033[0m\n");
		map[pos.y][pos.x] = 'P';
		map[pos.old_y][pos.old_x] = '0';
	}
	return (map);
}
