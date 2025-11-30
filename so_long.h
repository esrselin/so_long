/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:20:07 by esakgul           #+#    #+#             */
/*   Updated: 2025/11/29 17:06:18 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define KEY_UP 119
# define KEY_LEFT 97
# define KEY_DOWN 115
# define KEY_RIGHT 100

typedef struct s_images
{
	void		*wall;
	void		*coin;
	void		*empty;
	void		*character;
	void		*exit;
}				t_images;

typedef struct s_map
{
	char		**map;
	int			x_size;
	int			y_size;
	int			c_count;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			player_x;
	int			player_y;
	int			collectible_count;
	int			exit_count;
	int			move_count;
	int			player_count;
	t_images	*images;
	t_map		*map;
}				t_game;

void			game_init(t_game **game);

void			render_map(t_game *game, int x, int y);
void			refresh_screen(t_game *game);
void			rendering_x_size(t_game *game, int x, int y, int tile_size);

int				key_esc(int keycode, void *param);
int				close_window(void *param);
void			load_images(t_game *game, int width, int height);

void			free_map(t_map *map);
void			free_images(t_game *game);
void			destroy_mlx(t_game *game);
void			free_game(t_game *game);
void			free_map_copy(char **copy);
void			ft_free_game(t_game *game);

void			map_check(t_game *game, int i, int j, char *keys);
void			check_walls(t_game *game);
void			check_map_reachable(t_game *game, int y, int x, int collected);
char			**create_map_copy(t_game *game);

void			ft_error(t_game *game, char *msg);
int				has_ber_extension(char *filename);

void	check_exit(t_game *game);
void	check_collectibles(t_game *game);
char			*ft_strdup(const char *s);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strdup(const char *s);
void			get_map(char *map_name, t_game *game);
void			check_rectangle(t_game *game, char **map);

#endif
