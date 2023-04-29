/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:24:56 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/04/28 23:37:50 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_b/fractol.h"

void    ft_init(t_mlx *m)
{
    m->max_x = 2;
    m->min_x = -2;
    m->max_y = 2;
    m->min_y = -2;
    m->lr = 0;
    m->ud = 0;
    m->c = 1;
    m->color = 0x0f00d0;
}

double interpolate(double start, double end, double zoom)
{
    return start + ((end - start) * zoom);
}

void applyZoom(t_mlx *m, double mouseRe, double mouseIm, double zoom)
{
     m->min_x = interpolate(mouseRe, m->min_x, zoom);
     m->min_y = interpolate(mouseIm, m->min_y, zoom);
     m->max_x = interpolate(mouseRe, m->max_x, zoom);
     m->max_y = interpolate(mouseIm, m->max_y, zoom);
}

int mouse_press(int button, int x, int y, t_mlx *m)
{
    double mouseRe;
    double mouseIm;
    double zoom;

    zoom = 1.0;
    mouseRe = (double)x/ (WIDTH / (m->max_x - m->min_x)) + m->min_x;
    mouseIm = (double)y / (HEIGHT / (m->max_y - m->min_y)) + m->min_y;
        if (button == 4)
           zoom = 0.9;
        else if (button == 5)
           zoom = 1.1;
    if (button == 4 || button == 5)
        applyZoom(m, mouseRe, mouseIm, zoom);
    start_draw(m);
    return(1);
}

int close_win(void *param)
{
    (void)param;
    exit(0);
}

int key_press(int keycode, t_mlx *m)
{
    if (keycode == 53)
        exit(0);
    else if (keycode == 123)
        m->lr -= 10;
    else if (keycode == 124)
        m->lr += 10;
    else if (keycode == 125)
        m->ud += 10;
    else if (keycode == 126)
        m->ud -= 10;
    else if (keycode == 2)
    {
        m->c = 2;
        m->color = 0xf2f0d5;
    }
    else if (keycode == 37)
    {
        m->c = 1;
        m->color = 0x0f00d0;
    }
    start_draw(m);
    return (0);
}
