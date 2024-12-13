/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 08:54:42 by tbeyel            #+#    #+#             */
/*   Updated: 2024/12/13 14:26:50 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
 #define SO_LONG_H

// # include <mlx.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

/*var*/
# define ON_DESTROY 17
# define ESCAPE_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

typedef struct	s_texture {
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*player;
	mlx_texture_t 	*collectible;
	mlx_texture_t	*exit;
}				t_texture;

typedef struct	s_image {
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
}				t_image;

typedef struct	s_vars {
	mlx_t		*mlx;
	void		*win;
	t_image		*img;
	char 		**map;
	int			count_move;
}				t_vars;

typedef struct	s_pos {
	int	x;
	int	y;
	int old_x;
	int old_y;
}				t_pos;

/*event*/
void	ft_key(mlx_key_data_t keydata, void *vars);
int		close_win(t_vars *vars);

/*texture*/
t_image	*load_textures(mlx_t *mlx);
int		aff_texture(char **map, t_vars vars, t_image *image);

/*move*/
char	**ft_move(char **map, t_pos pos, t_vars *vars);

/*check_map*/
int		ft_check_map(char **map);
int		ft_check_character(char **map);
int		ft_check_rectangle_map(char **map);
int 	ft_check_close_map(char **map);
int		ft_check_item_amount(char **map);
int 	check_valid_road(char **map, int x, int y);
int 	ft_check_valid_road_coll(char **map, int x, int y);
int		ft_amount_collectible(char **map);
t_pos	ft_find_p(char **map);

/*utils*/
int 	ft_error(char *tab);
char	**ft_duplicate_map(char **map);
void	free_map(char **map);

#endif