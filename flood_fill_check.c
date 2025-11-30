/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 23:00:00 by esakgul           #+#    #+#             */
/*   Updated: 2025/11/28 17:05:39 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_map_copy(t_game *game)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (game->map->y_size + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < game->map->y_size)
	{
		copy[i] = ft_strdup(game->map->map[i]);
		if (!copy[i])
			return (NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	check_map_reachable(t_game *game, int y, int x, int collected)
{
	(void)y;
	(void)x;
	(void)collected;
	check_collectibles(game);
	check_exit(game);
}

void	free_map_copy(char **copy)
{
	int	i;

	if (!copy)
		return ;
	i = 0;
	while (copy[i])
	{
		free(copy[i]);
		i++;
	}
	free(copy);
}
