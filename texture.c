/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:17:56 by tbeyel            #+#    #+#             */
/*   Updated: 2024/12/06 15:19:21 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x <= 1920 && y >= 0 && y <= 1080)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void	ft_square(t_data img, int x, int y, int len, int color)
{
	int	i;
	int	j;
	
	i = 0;
	while (i != len)
	{
		j = 0;
		while (j != len)
		{
			my_mlx_pixel_put(&img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	ft_triangle(t_data img, int length)
{
	int x;
	int	x_copy;
	int y;
	int len;

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

int get_opposite(int color)
{
    int r, g, b;
    int opposite_r, opposite_g, opposite_b;

    r = (color >> 16) & 0xFF;
    g = (color >> 8) & 0xFF;
    b = color & 0xFF;

    opposite_r = 255 - r;
    opposite_g = 255 - g;
    opposite_b = 255 - b;

    return (opposite_r << 16) | (opposite_g << 8) | opposite_b;
}

int add_shade(double distance, int color)
{
    int r, g, b;
    int shaded_r, shaded_g, shaded_b;

    r = (color >> 16) & 0xFF;
    g = (color >> 8) & 0xFF;
    b = color & 0xFF;
    shaded_r = (int)(r * (1 - distance));
    shaded_g = (int)(g * (1 - distance));
    shaded_b = (int)(b * (1 - distance));

    return (shaded_r << 16) | (shaded_g << 8) | shaded_b;
}

void	ft_checkerboard(t_data img, int width, int height, int square_size)
{
    int x, y;
    int color;

	x = 0;
	y = 0;
    while (y < height)
    {
        while (x < width)
        {
            if (((x / square_size) % 2 == 0 && (y / square_size) % 2 == 0) ||
                ((x / square_size) % 2 == 1 && (y / square_size) % 2 == 1))
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
