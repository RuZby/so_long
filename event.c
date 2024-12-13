/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:15:38 by tbeyel            #+#    #+#             */
/*   Updated: 2024/12/13 13:24:58 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_key(mlx_key_data_t keydata, void *param)
{
	t_vars	*vars;
	t_pos	pos;

	vars = (t_vars *)param;
	pos = ft_find_p(vars->map);
	if (keydata.key == MLX_KEY_ESCAPE)
		close_win(param);
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_A
		|| keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_D) && keydata.action == MLX_PRESS)
	{
		vars->count_move++;
		if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		{
			pos.y--;
			vars->map = ft_move(vars->map, pos, vars);
		}
		if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		{
			pos.x--;
			vars->map = ft_move(vars->map, pos, vars);
		}
		if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		{
			pos.y++;
			vars->map = ft_move(vars->map, pos, vars);
		}
		if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		{
			pos.x++;
			vars->map =ft_move(vars->map, pos, vars);
		}
		ft_printf("You made %d moves\n", vars->count_move);
		if (aff_texture(vars->map, *vars, vars->img))
	  		return ;
	}
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
	if (vars->map)
		free_map(vars->map);
	mlx_terminate(vars->mlx);
	free(vars->img);
	exit(0);
	return (0);
}
