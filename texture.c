/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:17:56 by tbeyel            #+#    #+#             */
/*   Updated: 2024/12/10 10:57:50 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x <= 1920 && y >= 0 && y <= 1080)
	{
		dst = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

// void	ft_square(t_data img, int x, int y, int len, int color)
// {
// 	int	i;
// 	int	j;
//	
// 	i = 0;
// 	while (i != len)
// 	{
// 		j = 0;
// 		while (j != len)
// 		{
// 			my_mlx_pixel_put(&img, x + j, y + i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	ft_triangle(t_data img, int length)
{
	int	x;
	int	x_copy;
	int	y;
	int	len;

	x = 10;
	y = 10;
	len = 1;
	while (y++ - 10 < length)
	{
		x_copy = x;
		while (x_copy++ - x < len)
		{
			my_mlx_pixel_put(&img, x_copy, y, 0x00FF0000);
		}
		x = x - 1;
		len = len + 2;
	}
}

int	get_opposite(int color)
{
	int	opposite_r;
	int	opposite_g;
	int	opposite_b;

	opposite_r = 255 - (color >> 16) & 0xFF;
	opposite_g = 255 - (color >> 8) & 0xFF;
	opposite_b = 255 - color & 0xFF;
	return ((opposite_r << 16) | (opposite_g << 8) | opposite_b);
}

int	add_shade(double distance, int color)
{
	int	shaded_r;
	int	shaded_g;
	int	shaded_b;

	shaded_r = (int)(((color >> 16) & 0xFF) * (1 - distance));
	shaded_g = (int)(((color >> 8) & 0xFF) * (1 - distance));
	shaded_b = (int)((color & 0xFF) * (1 - distance));
	return ((shaded_r << 16) | (shaded_g << 8) | shaded_b);
}

void	ft_checkerboard(t_data img, int width, int height, int square_size)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	y = 0;
	while (y < height)
	{
		while (x < width)
		{
			if (((x / square_size) % 2 == 0 && (y / square_size) % 2 == 0)
				|| ((x / square_size) % 2 == 1 && (y / square_size) % 2 == 1))
				color = 0x00F9429E;
			else
				color = 0x00000000;
			my_mlx_pixel_put(&img, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
}

void	load_textures(t_vars *vars)
{
    vars->textures.wall = mlx_xpm_file_to_image(vars->mlx, "wall.xpm", , );
    vars->textures.floor = mlx_xpm_file_to_image(vars->mlx, "floor.xpm", , );
    vars->textures.player = mlx_xpm_file_to_image(vars->mlx, "player.xpm", , );
	vars->textures.collectible = mlx_xpm_file_to_image(vars->mlx, "collectible.xpm", , );
    vars->textures.exit = mlx_xpm_file_to_image(vars->mlx, "exit.xpm", , );
}
int	ft_load_texture(char **map, t_vars vars)
{
	int x;
	int y;
	
	y = 0;
	while (map[y][x])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.textures.wall, x * 60, y * 60);
			x++;
		}
		y++;
	}
	return (0);
}