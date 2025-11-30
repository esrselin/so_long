/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:51:32 by esakgul           #+#    #+#             */
/*   Updated: 2025/11/29 13:50:31 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game, int width, int height)
{
	game->images = malloc(sizeof(t_images));
	if (!game->images)
		ft_error(game, "Image malloc failed");
	game->images->wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &width, &height);
	if (!game->images->wall)
		ft_error(game, "Failed to load wall.xpm");
	game->images->empty = mlx_xpm_file_to_image(game->mlx,
			"textures/empty.xpm", &width, &height);
	if (!game->images->empty)
		ft_error(game, "Failed to load empty.xpm");
	game->images->coin = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &width, &height);
	if (!game->images->coin)
		ft_error(game, "Failed to load coin.xpm");
	game->images->character = mlx_xpm_file_to_image(game->mlx,
			"textures/character.xpm", &width, &height);
	if (!game->images->character)
		ft_error(game, "Failed to load character.xpm");
	game->images->exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &width, &height);
	if (!game->images->exit)
		ft_error(game, "Failed to load exit.xpm");
}

void	rendering_x_size(t_game *game, int x, int y, int ts)
{
	char	tile;

	tile = game->map->map[y][x];
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->images->wall, x * ts, y * ts);
	if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->images->empty, x * ts, y * ts);
	if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->images->coin, x * ts, y * ts);
	if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->images->exit, x * ts, y * ts);
	if (tile == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->images->character, x * ts, y * ts);
		game->player_x = x;
		game->player_y = y;
	}
}

void	render_map(t_game *game, int x, int y)
{
	while (y < game->map->y_size)
	{
		x = 0;
		while (x < game->map->x_size)
		{
			rendering_x_size(game, x, y, 50);
			x++;
		}
		y++;
	}
	ft_printf("Moves: %d\n", game->move_count);
}

void	refresh_screen(t_game *game)
{
	mlx_do_sync(game->mlx);
	mlx_clear_window(game->mlx, game->win);
	render_map(game, 0, 0);
}
