/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:20:07 by esakgul           #+#    #+#             */
/*   Updated: 2025/11/21 00:12:41 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <mlx.h>
# include "get_next_line/get_next_line.h"

# define KEY_UP 119
# define KEY_LEFT 97
# define KEY_DOWN 115
# define KEY_RIGHT 100

typedef struct s_images
{
    void *wall;
    void *coin;
    void *empty;
    void *character;
    void *exit;
    
}t_images;


typedef struct s_map
{
    char    **map;
    int     x_size;
    int     y_size;
    int     c_count;

}t_map;


typedef struct s_game
{
    void     *mlx;
    void    *win;
    int     player_x;
    int     player_y;
    int     collectible_count;
    t_images *images;
    t_map   *map;
}t_game;

void    refresh_screen(t_game *game);
int key_esc(int keycode, void *param);
int close_window(void *param);
void	free_map(t_map *map);
void	free_images(t_game *game);
void	destroy_mlx(t_game *game);
void	free_game(t_game *game);
void render_map(t_game *game);
void load_images(t_game *game);
void	ft_error(t_game *game, char *msg);
int     has_ber_extension(char *filename);
char	*ft_strdup(const char *s);
//int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	check_map_reachable(t_game *game);
void map_check(t_game *game);
void ft_free_game(t_game *game);
void check_walls(t_game *game);

#endif