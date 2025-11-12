/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:01:54 by esakgul           #+#    #+#             */
/*   Updated: 2025/11/12 04:55:43 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_esc(int keycode, void *param)
{
    t_game *game = (t_game *)param;
    if (keycode == 65307)
    {
        write(1, "Exit with ESC\n", 14);
        free(game);
        exit(0);
    }
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