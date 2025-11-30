/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:18:13 by esakgul           #+#    #+#             */
/*   Updated: 2025/11/28 17:39:32 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_height(t_game *game, char *map_name)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		ft_error(game, "Cannot open map file");
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

static void	process_line(t_game *game, char *line, int i)
{
	int	j;

	j = 0;
	while (line[j] && line[j] != '\n')
	{
		if (line[j] == 'C')
			game->collectible_count++;
		if (line[j] == 'P')
		{
			game->player_x = j;
			game->player_y = i;
		}
		j++;
	}
}
void	read_map(t_game *game, int fd, int first_valid)
{
    char	*line;
    int		i;

    i = 0;
    line = get_next_line(fd);
    while (line)
    {
        if (first_valid && (line[0] == '\n' || line[0] == '\0'))
            ft_error(game, "Map contains an empty line inside");
        first_valid = 1;
        process_line(game, line, i);
        game->map->map[i] = ft_strdup(line);
        if (!game->map->map[i])
            ft_error(game, "Malloc failed");
        free(line);
        i++;
        line = get_next_line(fd);
    }
    game->map->map[i] = NULL;
    game->map->y_size = i;
}

void	get_map(char *map_name, t_game *game)
{
    int	fd;
    int	height;
    int	i;

    fd = open(map_name, O_RDONLY);
    if (fd == -1)
        ft_error(game, "Cannot open map file");
    game->collectible_count = 0;
    height = get_map_height(game, map_name);
    game->map->map = malloc(sizeof(char *) * (height + 1));
    if (!game->map->map)
        ft_error(game, "Malloc failed");
    i = 0;
    while (i <= height)
        game->map->map[i++] = NULL;
    read_map(game, fd, 0);
    if (game->map->y_size > 0)
        game->map->x_size = ft_strlen(game->map->map[0]);
    close(fd);
}
