/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:20:07 by esakgul           #+#    #+#             */
/*   Updated: 2025/11/12 06:16:20 by esakgul          ###   ########.fr       */
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
    
}t_images;


typedef struct s_map
{
    char    **map;
    int     x_size;
    int     y_size;
    
}t_map;


typedef struct s_game
{
    void *mlx;
    void *win;
    int     player_x;
    int     player_y;
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
void    ft_error(char *error);
#endif