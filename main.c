/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:29:43 by esakgul           #+#    #+#             */
/*   Updated: 2025/11/19 23:59:59 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_game *game, char *msg)
{
	printf("Error\n%s\n", msg);
	if (game)
		ft_free_game(game);
	exit(1);
}

int	get_map_height(t_game *game, char *map_name)
{
	int		fd;
	int		height = 0;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		ft_error(game, "Cannot open map file");
	while ((line = get_next_line(fd)))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

void	get_map(char *map_name, t_game *game)
{
	int		fd;
	char	*line;
	int		i = 0;
	int		j;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		ft_error(game, "Cannot open map file");
	game->collectible_count = 0;
	game->map->map = malloc(sizeof(char *) * (get_map_height(game, map_name) + 1));
	if (!game->map->map)
		ft_error(game, "Malloc failed");
	while ((line = get_next_line(fd)))
	{
		j = 0;
		while (line[j])
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
		game->map->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	game->map->map[i] = NULL;
	game->map->y_size = i;
	game->map->x_size = ft_strlen(game->map->map[0]);
	close(fd);
}

void	check_rectangle(t_game *game, char **map)
{
	int		i = 1;
	size_t	len = ft_strlen(map[0]);

	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			ft_error(game, "Map is not rectangular");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc != 2)
		ft_error(game, "Usage: ./so_long maps/map.ber");
	if (!has_ber_extension(argv[1]))
		ft_error(game, "Map must have .ber extension");

	game = malloc(sizeof(t_game));
	if (!game)
	{	
		ft_error(game, "Malloc failed");
		free(game);
	}	
	game->map = malloc(sizeof(t_map));
	if (!game->map)
	{
		ft_error(game, "Malloc failed");
		
	}
	game->images = NULL;
	game->collectible_count = 0;

	get_map(argv[1], game);
    
	check_rectangle(game, game->map->map);
	check_walls(game);
	check_map_reachable(game);
	map_check(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
		game->map->x_size * 50,
		game->map->y_size * 50,
		"so_long");

	load_images(game);
	render_map(game);

	mlx_hook(game->win, 2, 1L << 0, key_esc, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
	return (0);
}
