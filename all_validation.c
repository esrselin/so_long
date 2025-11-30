/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 23:18:13 by esakgul           #+#    #+#             */
/*   Updated: 2025/11/28 17:17:38 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	has_ber_extension(char *filename)
{
	char	*dot;

	dot = ft_strrchr(filename, '.');
	if (!dot)
		return (0);
	return (ft_strncmp(dot, ".ber", 4) == 0);
}

void	map_check(t_game *game, int i, int j, char *keys)
{
	game->map->c_count = 0;
	game->exit_count = 0;
	game->player_count = 0;
	while (game->map->map[++i])
	{
		j = -1;
		while (game->map->map[i][++j])
		{
			if (!ft_strchr(keys, game->map->map[i][j]))
				ft_error(game, "Unknown character in map");
			if (game->map->map[i][j] == 'E')
				game->exit_count++;
			if (game->map->map[i][j] == 'C')
				game->map->c_count++;
			if (game->map->map[i][j] == 'P')
				game->player_count++;
		}
	}
	if (game->exit_count != 1)
		ft_error(game, "Map must contain exactly one Exit");
	if (game->player_count != 1)
		ft_error(game, "Map must contain exactly one Player");
	if (game->map->c_count < 1)
		ft_error(game, "Map must contain at least one Collectible");
}

void	check_walls(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map->x_size)
	{
		if (game->map->map[0][i] != '1'
			|| game->map->map[game->map->y_size - 1][i] != '1')
			ft_error(game, "Map must be surrounded by walls");
	}
	i = -1;
	while (++i < game->map->y_size)
	{
		if (game->map->map[i][0] != '1'
			|| game->map->map[i][game->map->x_size - 1] != '1')
			ft_error(game, "Map must be surrounded by walls");
	}
}

void	check_rectangle(t_game *game, char **map)
{
    int		i;
    size_t	len;

    if (!map || !map[0])
        return ;
    i = 1;
    len = ft_strlen(map[0]);
    while (map[i] && map[i][0] != '\0')
    {
        if (ft_strlen(map[i]) != len)
            ft_error(game, "Map is not rectangular");
        i++;
    }
}

