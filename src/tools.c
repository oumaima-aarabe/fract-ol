/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:24:56 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/05/01 22:25:12 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void    ft_init(t_mlx *m)
{
    m->max_x = 2;
    m->min_x = -2;
    m->max_y = 2;
    m->min_y = -2;
}


int mouse_press(int button, int x, int y, t_mlx *m)
{
    (void)x;
    (void)y;
    if (button == 4)
    {
        double center_x = (m->max_x + m->min_x) / 2.0;
        double center_y = (m->max_y + m->min_y) / 2.0;
        
        m->max_x = (m->max_x - center_x) * 0.9 + center_x;
        m->min_x = (m->min_x - center_x) * 0.9 + center_x;
        m->max_y = (m->max_y - center_y) * 0.9 + center_y;
        m->min_y = (m->min_y - center_y) * 0.9 + center_y;
    }
    else if (button == 5)
    {
        double center_x = (m->max_x + m->min_x) / 2.0;
        double center_y = (m->max_y + m->min_y) / 2.0;
        
        m->max_x = (m->max_x - center_x) * 1.1 + center_x;
        m->min_x = (m->min_x - center_x) * 1.1 + center_x;
        m->max_y = (m->max_y - center_y) * 1.1 + center_y;
        m->min_y = (m->min_y - center_y) * 1.1 + center_y;
    }

    start_draw(m);
    return(1);
}

int close_win(t_mlx *m)
{
    mlx_destroy_image(m->mlx, m->img);
	mlx_destroy_window(m->mlx, m->window);
    free(m);
    exit(0);
}

int key_press(int keycode, t_mlx *m)
{
    if (keycode == 53)
        close_win(m);
    return (0);
}
