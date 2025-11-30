/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 23:00:00 by esakgul           #+#    #+#             */
/*   Updated: 2025/11/28 17:05:39 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_flood(char **map, int y, int x, t_game *game)
{
	if (y < 0 || x < 0 || y >= game->map->y_size || x >= game->map->x_size)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'M')
		return ;
	map[y][x] = 'M';
	ft_flood(map, y + 1, x, game);
	ft_flood(map, y - 1, x, game);
	ft_flood(map, y, x + 1, game);
	ft_flood(map, y, x - 1, game);
}

static void	set_exit_as_wall(char **copy, t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map->y_size)
	{
		x = -1;
		while (++x < game->map->x_size)
		{
			if (copy[y][x] == 'E')
				copy[y][x] = '1';
		}
	}
}

static int	check_char_reachable(char **copy, t_game *game, char c)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map->y_size)
	{
		x = -1;
		while (++x < game->map->x_size)
		{
			if (copy[y][x] == c)
				return (0);
		}
	}
	return (1);
}

void	check_collectibles(t_game *game)
{
	char	**copy;

	copy = create_map_copy(game);
	if (!copy)
		ft_error(game, "Malloc failed");
	set_exit_as_wall(copy, game);
	ft_flood(copy, game->player_y, game->player_x, game);
	if (!check_char_reachable(copy, game, 'C'))
	{
		free_map_copy(copy);
		ft_error(game, "Collectible is not reachable!");
	}
	free_map_copy(copy);
}

void	check_exit(t_game *game)
{
	char	**copy;

	copy = create_map_copy(game);
	if (!copy)
		ft_error(game, "Malloc failed");
	ft_flood(copy, game->player_y, game->player_x, game);
	if (!check_char_reachable(copy, game, 'E'))
	{
		free_map_copy(copy);
		ft_error(game, "Exit is not reachable!");
	}
	free_map_copy(copy);
}
