/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:20:07 by esakgul           #+#    #+#             */
/*   Updated: 2025/11/12 04:57:02 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <mlx.h>
# include "get_next_line/get_next_line.h"



typedef struct s_images
{
    void *wall;
    void *coin;
    
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
    t_images *images;
    t_map   *map;
}t_game;


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