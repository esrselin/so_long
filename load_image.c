/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:51:32 by esakgul           #+#    #+#             */
/*   Updated: 2025/11/12 05:10:55 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void load_images(t_game *game)
{
    int width, height;

    game->images = malloc(sizeof(t_images));
    if (!game->images)
        ft_error("Image malloc failed");

    game->images->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &width, &height);
    if (!game->images->wall)
        ft_error("Failed to load wall1.xpm");
    

}

void render_map(t_game *game)
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
            {
                mlx_put_image_to_window(game->mlx, game->win,
                    game->images->wall, x * tile_size, y * tile_size);
            }
            x++;
        }
        y++;
    }
}