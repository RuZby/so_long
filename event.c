/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:15:38 by tbeyel            #+#    #+#             */
/*   Updated: 2024/12/12 14:58:18 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	ft_key(int keypress, t_vars *vars)
// {
// 	if (keypress == ESCAPE_KEY)
// 		close_win(vars);
// 	return (0);
// }

void	ft_key(mlx_key_data_t keydata, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		close_win(param);
}

int	close_win(t_vars *vars)
{
	mlx_delete_image(vars->mlx, vars->img->wall);
	mlx_delete_image(vars->mlx, vars->img->floor);
	mlx_delete_image(vars->mlx, vars->img->exit);
	mlx_delete_image(vars->mlx, vars->img->player);
	mlx_delete_image(vars->mlx, vars->img->collectible);
	
	if (vars->mlx)
		mlx_close_window(vars->mlx);
	mlx_terminate(vars->mlx);
	free(vars->img);
//	free(vars->mlx);
	exit(0);
	return (0);
}
