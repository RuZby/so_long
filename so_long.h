/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 08:54:42 by tbeyel            #+#    #+#             */
/*   Updated: 2024/12/10 10:53:41 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
 #define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include "libft/libft.h"

/*var*/
# define ON_DESTROY 17
# define ESCAPE_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100


/*structure*/
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_texture {
	void	*wall;
	void	*floor;
	void	*player;
	void 	*collectible;
	void	*exit;
}				t_texture;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_data		img;
	t_texture	textures;
}				t_vars;

typedef struct	s_pos {
	int	x;
	int	y;
}				t_pos;

/*event*/
int		ft_key(int keypress, t_vars *vars);
int		close_win(t_vars *vars);

/*texture*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_checkerboard(t_data img, int width, int height, int square_size);
void	ft_square(t_data img, int x, int y, int len, int color);
void	ft_triangle(t_data img, int length);
int 	get_opposite(int color);
int 	add_shade(double distance, int color);

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