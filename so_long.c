/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 08:54:45 by tbeyel            #+#    #+#             */
/*   Updated: 2024/12/09 17:22:33 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup_free(char *s)
{
	char	*dst;
	int		i;

	i = ft_strlen(s);
	dst = (char *)malloc(i * sizeof(char) + 1);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	free(s);
	return (dst);
}

char **ft_strbigjoin(char **map, char *str)
{
	char	**new_map;
	int		len;

	len = 0;
    if (!map || !str)
		return (NULL);
	while (map[len])
		len++;
	new_map = malloc(sizeof(char *) * (len + 2));
	if (!new_map)
		return (NULL);
	len = 0;
	while (map[len])
	{
		new_map[len] = ft_strdup_free(map[len]);
		if (!new_map[len])
		{
			while (len >= 0)
			{
				free(new_map[len]);
				len--;
			}
			free(new_map);
			free(map);
			return (NULL);
		}
		len++;
	}
	new_map[len] = ft_strdup_free(str);
	if (!new_map[len])
	{
		while (len >= 0)
		{
			free(new_map[len]);
			len--;
		}
		free(new_map);
		free(map);
		return (NULL);
	}
	new_map[len + 1] = NULL;
	free(map);
	return (new_map);
}

char **parsing(char *file)
{
	int		fd;
	char	*tab;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = malloc(sizeof(char *));
	if (!map)
		return (NULL);
	map[0] = NULL;
	tab = get_next_line(fd);
	while (tab)
	{
		map = ft_strbigjoin(map, tab);
		if (!map)
			return (free(tab), NULL);
		tab = get_next_line(fd);
	}
	close(fd);
	return (map);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	char	**map;

	// img1 = "images/cave.xpm";
	if (argc != 2)
		return (ft_error("Wrong number of arguments\n"));
	map = parsing(argv[1]);
	if (!map)
		return (1);
	ft_printf("%d\n", ft_check_map(map));
	int i = 0;
	while (map[i])
		i++;
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "so_long");
	if (!vars.win)
		return (1);

	// vars.img.img = mlx_xpm_file_to_image(vars.mlx, img1, &vars.img.line_length, &vars.img.endian);
	// if (!vars.img.img)
	// 	return (1);
	// vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	// if (!vars.img.addr)
	// 	return (1);
	// mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);

	mlx_key_hook(vars.win, ft_key, &vars); 
	mlx_hook(vars.win, ON_DESTROY, 0, close_win, &vars);
	mlx_loop(vars.mlx);
	return (0);
}