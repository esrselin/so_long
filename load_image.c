/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:51:32 by esakgul           #+#    #+#             */
/*   Updated: 2025/11/21 00:51:08 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void load_images(t_game *game)
{
    int width, height;

    game->images = malloc(sizeof(t_images));
    if (!game->images)
        ft_error(game, "Image malloc failed");
    game->images->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &width, &height);
    if (!game->images->wall)
        ft_error(game, "Failed to load wall.xpm");
    game->images->empty = mlx_xpm_file_to_image(game->mlx, "textures/empty.xpm", &width, &height);
    if (!game->images->empty)
        ft_error(game, "Failed to load empty.xpm");
    game->images->coin = mlx_xpm_file_to_image(game->mlx, "textures/collectible.xpm", &width, &height);
    if (!game->images->coin)
        ft_error(game, "Failed to load coin.xpm");
    game->images->character = mlx_xpm_file_to_image(game->mlx, "textures/character.xpm", &width, &height);
    if (!game->images->character)
        ft_error(game, "Failed to load character.xpm");
    game->images->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &width, &height);
    if (!game->images->exit)
        ft_error(game, "Failed to load exit.xpm");
}

void  render_map(t_game *game)
{
    int y = 0;
    int x = 0;
    int tile_size = 50;

    while (y < game->map->y_size)
    {
        x = 0;
        while (x < game->map->x_size)
        {
             if (game->map->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win,
                    game->images->wall, x * tile_size, y * tile_size);
            if (game->map->map[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->win,
                    game->images->empty, x * tile_size, y * tile_size);
            if (game->map->map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win,
                    game->images->coin, x * tile_size, y * tile_size);
             if (game->map->map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win,
                    game->images->exit, x * tile_size, y * tile_size);
            if (game->map->map[y][x] == 'P')
            {
                mlx_put_image_to_window(game->mlx, game->win,
                    game->images->character, x * tile_size, y * tile_size);
                game->player_x = x;
                game->player_y = y;
            }
            x++;
        }
        y++;
    }
}

void    refresh_screen(t_game *game)
{
    mlx_do_sync(game->mlx);
    mlx_clear_window(game->mlx,game->win);
    render_map(game);
}