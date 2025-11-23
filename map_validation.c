/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 23:18:13 by esakgul           #+#    #+#             */
/*   Updated: 2025/11/21 01:47:20 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void map_check(t_game *game)
{
	int i;
	int j;
	char *keys = "10CPE";
	int E;

	game->map->c_count = 0;
	E = 0;
	i = -1;
	while(game->map->map[++i])
	{
		j = -1;
		while (game->map->map[i][++j])
		{
			if (!ft_strchr(keys, game->map->map[i][j]))
				ft_error(game, "There are unknown characters in the map");
			if (game->map->map[i][j] == 'E')
				E++;
			if (game->map->map[i][j] == 'C')
				game->map->c_count++;
		}
	}
	if (E != 1)
		ft_error(game, "There is no Exit in the map");
	if (game->map->c_count < 1)
		ft_error(game, "There is not enough collectibles in the map");
}

void check_walls(t_game *game)
{
	int i;

	i = -1;
	while(++i < game->map->x_size)
	{
		if (game->map->map[0][i] != '1' || game->map->map[game->map->y_size - 1][i] != '1')
			ft_error(game, "no wlls");
	}
	i = -1;
	while(++i < game->map->y_size)
	{
		if (game->map->map[i][0] != '1' || game->map->map[i][game->map->x_size - 1] != '1')
			ft_error(game, "no wlls");
	}
}