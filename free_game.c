/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 23:36:16 by esakgul           #+#    #+#             */
/*   Updated: 2025/11/28 17:38:47 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_game *game, char *msg)
{
	printf("Error\n%s\n", msg);
	if (game)
		ft_free_game(game);
	get_next_line(-1);
	exit(1);
}

void	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map)
		return ;
	if (!game->map->map)
	{
		free(game->map);
		return ;
	}
	while (game->map->map[i] != NULL)
	{
		free(game->map->map[i]);
		i++;
	}
	free(game->map->map);
	free(game->map);
}

void	ft_free_images(t_game *game)
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

void	ft_free_game(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->map)
		ft_free_map(game);
	if (game->images)
		ft_free_images(game);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
	free(game);
}

void	game_init(t_game **game)
{
	*game = malloc(sizeof(t_game));
	if (!*game)
		ft_error(NULL, "Malloc failed");
	(*game)->mlx = NULL;
	(*game)->win = NULL;
	(*game)->images = NULL;
	(*game)->map = NULL;
	(*game)->collectible_count = 0;
	(*game)->player_x = 0;
	(*game)->player_y = 0;
	(*game)->move_count = 0;
	(*game)->map = malloc(sizeof(t_map));
	if (!(*game)->map)
		ft_error(*game, "Malloc failed");
	(*game)->map->map = NULL;
	(*game)->map->x_size = 0;
	(*game)->map->y_size = 0;
	(*game)->map->c_count = 0;
}
