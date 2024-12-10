/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:46:03 by tbeyel            #+#    #+#             */
/*   Updated: 2024/12/10 09:31:44 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_error(char *tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		write(2, &tab[i], 1);
		i++;
	}
	return (1);
}

char	**ft_duplicate_map(char **map)
{
	int i;
	char **new_map;
	
	i = 0;
	while (map[i])
		i++;
	new_map = malloc(sizeof(char *) * (i + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			while (i >= 0)
			{
				free(new_map[i]);
				i--;
			}
			free(new_map);
			return (NULL);
		}
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

void free_map(char **map)
{
    int i = 0;

    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

int	ft_check_map(char **map)
{
	char **new_map;

	if (ft_check_character(map) == 1)
		return (ft_error("Error character map\n"));
	if (ft_check_rectangle_map(map) == 1)
		return (ft_error("Error shape map\n"));
	if (ft_check_close_map(map) == 1)
		return (ft_error("Error close map\n"));
	if (ft_check_item_amount(map) == 1)
		return (ft_error("Error item amount\n"));
	new_map = ft_duplicate_map(map);
	if (!new_map)
		return (ft_error("Error duplicate map\n"));
	if (ft_check_valid_road(new_map, ft_find_player(new_map).x, ft_find_player(new_map).y) == 0)
		return (ft_error("Error no valid road\n"));
	if (ft_check_valid_road_coll(map, ft_find_player(map).x, ft_find_player(map).y) != ft_amount_collectible(map))
		return (ft_error("Error no valid road collectible\n"));
	free_map(new_map);
	return (0);
}

int	ft_check_character(char **map)
{
	int y;
	int x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\n' && map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'P'
				&& map[y][x] != 'E' && map[y][x] != 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_check_rectangle_map(char **map)
{
	int x_init;
	int i;
	int	j;

	i = 0;
	while (map[0][i] != '\n' && map[0][i])
		i++;
	x_init = i;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i] != '\n' && map[j][i])
			i++;
		if (x_init != i)
		{
			// ft_printf("x_init = %d, i = %d, j = %d\n", x_init, i, j);
			return (1);
		}
		j++;
	}
	return (0);
}

int ft_check_close_map(char **map)
{
	size_t x_end;
	int	x;
	int	y;

	x_end = 0;
	y = 1;
	while (map[0][x_end] == '1' || map[0][x_end] == '0' || map[0][x_end] == 'P'
		|| map[0][x_end] == 'E' || map[0][x_end] == 'C')
	{
		if (map[0][x_end] != '1')
			return (1);
		x_end++;
	}
	while (map[y + 1])
	{
		if (ft_strlen(map[y]) != x_end + 1 || map[y][0] != '1' || map[y][x_end - 1] != '1')
			return (1);
		y++;
	}
	x = 0;
	while (map[y][x] == '1' || map[y][x] == '0' || map[y][x] == 'P'
		|| map[y][x] == 'E' || map[y][x] == 'C')
	{
		if (ft_strlen(map[y]) != x_end || map[y][x] != '1')
			return (1);
		x++;
	}
	return (0);
}

int	ft_check_item_amount(char **map)
{
	int	e_count;
	int	p_count;
	int	c_count;
	int	y;
	int	x;
	
	y = 0;
	e_count = 0;
	p_count = 0;
	c_count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				e_count++;
			else if (map[y][x] == 'C')
				c_count++;
			else if (map[y][x] == 'P')
				p_count++;
			x++;
		}
		y++;
	}
	if (e_count != 1 || c_count < 1 || p_count != 1)
		return (1);
	return (0);
}

t_pos	ft_find_player(char **map)
{
	t_pos	pos;
	pos.y = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] == 'P')
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	return (pos);
}

int ft_check_valid_road(char **map, int x, int y)
{
	int is_exit;
	
	is_exit = 0;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (0);
	else
	{
		if (map[y][x] == 'E')
			return (1);
		map[y][x] = 'V';
		is_exit = ft_check_valid_road(map, x + 1, y);
		is_exit += ft_check_valid_road(map, x - 1, y);
		is_exit += ft_check_valid_road(map, x, y + 1);
		is_exit += ft_check_valid_road(map, x, y - 1);
	}
	return (is_exit);
}

int ft_check_valid_road_coll(char **map, int x, int y)
{
	int is_exit;
	
	is_exit = 0;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (0);
	else
	{
		if (map[y][x] == 'C')
		{
			map[y][x] = 'V';
			return (1);
		}
		map[y][x] = 'V';
		is_exit = ft_check_valid_road_coll(map, x + 1, y);
		is_exit += ft_check_valid_road_coll(map, x - 1, y);
		is_exit += ft_check_valid_road_coll(map, x, y + 1);
		is_exit += ft_check_valid_road_coll(map, x, y - 1);
	}
	return (is_exit);
}

int	ft_amount_collectible(char **map)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}