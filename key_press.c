/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:01:54 by esakgul           #+#    #+#             */
/*   Updated: 2025/11/12 06:17:21 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void    


void steps(t_game *game, int i, int j)
{
	if (game->map->map[game->player_y + i][game->player_x + j] == '0' 
		|| game->map->map[game->player_y + i][game->player_x + j] == 'C')
	{
		game->map->map[game->player_y + i][game->player_x + j] = 'P';
		game->map->map[game->player_y][game->player_x] = '0';
		refresh_screen(game);
	}
}


int key_esc(int keycode, void *param)
{
    t_game *game = (t_game *)param;
    if (keycode == 65307)
    {
        write(1, "Exit with ESC\n", 14);
        free(game);
        exit(0);
    }
    else if (keycode == KEY_UP)
        steps(game,-1,0);
    else if (keycode == KEY_LEFT)
        steps(game,0,-1);
    else if (keycode == KEY_DOWN)
        steps(game,1,0);
    else if (keycode == KEY_RIGHT)
        steps(game,0,1);
    return (0);
}

int close_window(void *param)
{
    t_game *game = (t_game *)param;
    write(1, "Window Closed\n", 15);
    free(game);
    exit(0);
    return (0);
}