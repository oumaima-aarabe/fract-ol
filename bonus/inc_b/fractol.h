/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:20:25 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/05/01 21:51:21 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include <math.h>
#include "mlx.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct s_mlx
{
    void *mlx;
    void *window;
    void *img;
    int id;
    int c;
    int *addr;
    int bpp;
    int ll;
    int endian;
    int iteration;
    int lr;
    int ud;
    int color;
    double max_y;
    double min_y;
    double min_x;
    double max_x;
    double  i;
    double r;
    
}   t_mlx;

typedef struct s_complx
{
    double r;
    double i;
    
}t_complx;

void	my_mlx_pixel_put(t_mlx *m, int x, int y, int color);
void    ft_draw(t_mlx *m);
void    ft_mandel(t_mlx *m);
void    ft_julia(t_mlx *mlx);
void start_draw(t_mlx *m);
void    ft_burning(t_mlx *m);
void    ft_init(t_mlx *m);

int close_win(t_mlx *m);
int key_press(int keycode, t_mlx *m);
int mouse_press(int button, int x, int y, t_mlx *m);

double ft_atof(char *s);
void    choose_color(t_mlx *m);

#define WIDTH 600
#define HEIGHT 600
#define MAXITER 100

#define PR -0.8

#define PI -0.156

#endif