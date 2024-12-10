/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:15:38 by tbeyel            #+#    #+#             */
/*   Updated: 2024/12/10 10:19:33 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key(int keypress, t_vars *vars)
{
	if (keypress == ESCAPE_KEY)
		close_win(vars);
	return (0);
}

int	close_win(t_vars *vars)
{
	// if (vars->img.img)
	// 	mlx_destroy_image(vars->win, vars->img.img);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}
