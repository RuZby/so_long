/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:17:56 by tbeyel            #+#    #+#             */
/*   Updated: 2024/12/12 15:33:13 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*load_textures(mlx_t *mlx)
{
	t_image *image;
	t_texture textures;
	
	image = malloc(sizeof(t_image));
	if (!image)
		ft_error("Trop null bouhou\n");
	image = ft_memset(image, 0, sizeof(t_image));
	textures.wall = mlx_load_png("images/wall.png");
	textures.floor = mlx_load_png("images/floor.png");
	textures.collectible = mlx_load_png("images/collectible.png");
	textures.player = mlx_load_png("images/player.png");
	textures.exit = mlx_load_png("images/exit.png");
	if (!textures.wall || !textures.floor || !textures.collectible || !textures.player || !textures.exit)
        ft_error("Failed to load texture\n");
	image->wall = mlx_texture_to_image(mlx, textures.wall);
	image->floor = mlx_texture_to_image(mlx, textures.floor);
	image->collectible = mlx_texture_to_image(mlx, textures.collectible);
	image->player = mlx_texture_to_image(mlx, textures.player);
	image->exit = mlx_texture_to_image(mlx, textures.exit);
	mlx_delete_texture(textures.wall);
	mlx_delete_texture(textures.floor);
	mlx_delete_texture(textures.collectible);
	mlx_delete_texture(textures.player);
	mlx_delete_texture(textures.exit);
	return (image);
}

int	aff_texture(char **map, t_vars vars, t_image *image)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' || map[y][x] == 'E' || map[y][x] == 'C' || map[y][x] == 'P')
				mlx_image_to_window(vars.mlx, image->floor, x * 64, y * 64);
			if (map[y][x] == '1')
				mlx_image_to_window(vars.mlx, image->wall, x * 64, y * 64);
			if (map[y][x] == 'P') 
			{
				mlx_image_to_window(vars.mlx, image->floor, x * 64, y * 64);
				mlx_image_to_window(vars.mlx, image->player, x * 64, y * 64);
			}
			if (map[y][x] == 'C')
			{
				mlx_image_to_window(vars.mlx, image->floor, x * 64, y * 64);
				mlx_image_to_window(vars.mlx, image->collectible, x * 64, y * 64);
			}
			if (map[y][x] == 'E')
			{
				mlx_image_to_window(vars.mlx, image->floor, x * 64, y * 64);
				mlx_image_to_window(vars.mlx, image->exit, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
	return (0);
}
