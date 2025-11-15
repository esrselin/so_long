/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:29:43 by esakgul           #+#    #+#             */
/*   Updated: 2025/11/12 05:59:22 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_error(char *error)
{
    printf("Error\n%s\n", error);
    exit(1);
}


char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;
	int		len;

	len = ft_strlen(s);
	i = 0;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
void check_rectangle(char **map)
{
    int i;
    size_t ref;

    ref = ft_strlen(map[0]);
    i = -1;
    while (map[++i])
        if (ref != ft_strlen(map[i]))
            ft_error("Map is not rectangle");
    
}

int get_size_of_map(char *map_name)
{
    int i;
    int fd;
    char    *line;

    fd = open(map_name, O_RDONLY);
    i = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        ++i;
        free(line);
    }
    close(fd);
    return i;
}

void    get_map(char *map_name, t_game *game)
{
    int i;
    int fd;
    char    *line;
    int     map_size;

    i = 0;
    fd = open(map_name, O_RDONLY);
    map_size = get_size_of_map(map_name);
    game->map->map = malloc(sizeof(char *) * (map_size + 1));
    while ((line = get_next_line(fd)) != NULL)
    {
        game->map->map[i] = ft_strdup(line);
        free(line);
        i++;
    }
    game->map->map[i] = NULL;
    game->map->y_size = i;
    game->map->x_size = ft_strlen(game->map->map[0]);
    close(fd);
}
void    check_map(t_game *game, char *map_name)
{
    get_map(map_name, game);
    check_rectangle(game->map->map);
}

int	main(int argc, char *argv[])
{
    t_game  *game;

    //int x = 0;
    //int y = 0;

    if (argc != 2)
        exit(1);   
    game = malloc(sizeof(t_game));
    game->map = malloc(sizeof(t_map));
    game->images = NULL;
    check_map(game,argv[1]);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map->x_size * 50, game->map->y_size * 50, "so_long");
	load_images(game);
    render_map(game);
    mlx_hook(game->win, 2, 1L << 0, key_esc, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
	return (0);
}