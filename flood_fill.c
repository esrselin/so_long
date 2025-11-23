/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 23:00:00 by esakgul           #+#    #+#             */
/*   Updated: 2025/11/19 23:59:59 by esakgul          ###   ########.fr       */
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

static char	**create_map_copy(t_game *game)
{
	char	**copy;
	int		i = 0;

	copy = malloc(sizeof(char *) * (game->map->y_size + 1));
	if (!copy)
		ft_error(game, "Malloc failed");
	while (i < game->map->y_size)
	{
		copy[i] = ft_strdup(game->map->map[i]);
		if (!copy[i])
			ft_error(game, "ft_strdup failed");
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	free_map_copy(char **copy)
{
	int	i = 0;
	while (copy[i])
		free(copy[i++]);
	free(copy);
}

void	check_map_reachable(t_game *game, int y, int x, int collected)
{
	char	**copy;

	copy = create_map_copy(game);
	ft_flood(copy, game->player_y, game->player_x, game);
	y = -1;
	while (++y < game->map->y_size)
	{
		x = -1;
		while (copy[y][++x])
		{
			if (copy[y][x] == 'C')
			{
				free_map_copy(copy);
				ft_error(game, "Collectible is not reachable!");
			}
			if (copy[y][x] == 'E')
			{
				free_map_copy(copy);
				ft_error(game, "Exit is not reachable!");
			}
			if (game->map->map[y][x] == 'C' && copy[y][x] == 'M')
				collected++;
		}
	}
	free_map_copy(copy);
}
