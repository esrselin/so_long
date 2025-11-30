/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:29:43 by esakgul           #+#    #+#             */
/*   Updated: 2025/11/29 17:06:08 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc != 2)
		ft_error(game, "Usage: ./so_long maps/map.ber");
	if (!has_ber_extension(argv[1]))
		ft_error(game, "Map must have .ber extension");
	game_init(&game);
	get_map(argv[1], game);
	check_rectangle(game, game->map->map);
	check_walls(game);
	check_map_reachable(game, -1, 0, -1);
	map_check(game, -1, -1, "10CPE");
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map->x_size * 50,
			game->map->y_size * 50, "so_long");
	load_images(game, 0, 0);
	render_map(game, 0, 0);
	mlx_hook(game->win, 2, 1L << 0, key_esc, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
	return (0);
}
