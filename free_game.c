/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 23:36:16 by esakgul           #+#    #+#             */
/*   Updated: 2025/11/20 23:56:36 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_free_map(t_game *game)
{
	int i;

	i = -1;
	while (game->map->map[++i])
		free(game->map->map[i]);
	free(game->map->map);
	free(game->map);	
}

void ft_free_images(t_game *game)
{	
    if (game->images->character)
        mlx_destroy_image(game->mlx, game->images->character);
    if (game->images->coin)
        mlx_destroy_image(game->mlx, game->images->coin);
    if (game->images->empty)
        mlx_destroy_image(game->mlx, game->images->empty);
    if (game->images->exit)
        mlx_destroy_image(game->mlx, game->images->exit);
    if (game->images->wall)
        mlx_destroy_image(game->mlx, game->images->wall);
    free(game->images);
}

void ft_free_game(t_game *game)
{
    if (game->win)
    {
        mlx_destroy_window(game->mlx, game->win);
        // mlx_clear_window(game->mlx, game->win);
    }
    if (game->map && game->map->map)
        ft_free_map(game);
    if (game->images)
        ft_free_images(game);
    if (game->mlx)
        mlx_destroy_display(game->mlx);
    free(game->mlx);
    free(game);
}