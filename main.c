/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 01:13:22 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/03/17 05:50:47 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>

typedef struct s_data {
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}   t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y *data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int main()
{
    void *mlx;
    void *window;
    t_data img;
    int  x = 200; 
    int y = 200;

    int cz = 200;
    int cw = 200;
    int r = 50;
    int z = cz - r;
    int w = cw - r;
        
    mlx = mlx_init();
    window = mlx_new_window(mlx, 1920, 1080, "test");
    img.img =   mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    while (y < 300)
    {
        while(x < 300)
        {
            my_mlx_pixel_put(&img, x, y, 0x00ff0000);
            x++;
        }
        x = 200;
        y++;
    }
    while (z <= cz + r)
    {
        while( w <= cw + r)
        {
            if ((pow(z - cz, 2) + pow(w - cw, 2 )) <= r*r)
                my_mlx_pixel_put(&img, z, w, 0x00ff00);
            w++;
        }
        w = cw - r;
        z++;
    }
    mlx_put_image_to_window(mlx, window, img.img, 0, 0);
    mlx_loop(mlx);
}
