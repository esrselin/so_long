/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:29:43 by esakgul           #+#    #+#             */
/*   Updated: 2025/11/11 17:02:54 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int   key_esc(int keycode, void *param)
{
   (void)param;
   if(keycode == 65307)
   {
      printf("Exit");
      exit(0);
   }
   return (1);
}
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
   if (x < 0 || y < 0 || x >= 1920 || y >= 1080)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
   void   *mlx;
   void  *mlx_win;
   t_data   img;
   
   mlx = mlx_init();
      if(!mlx)
      {
	   	write(1, "Window creation failed!\n", 25);
		   return (1);
	   }
   mlx_win = mlx_new_window(mlx, 1920, 1080, "Window");
   img.img = mlx_new_image(mlx, 1920, 1080);
   mlx_key_hook(mlx_win, key_esc, NULL);

   img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

   mlx_loop(mlx);
}