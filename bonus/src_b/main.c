/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:16:07 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/05/02 00:50:59 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_b/fractol.h"


int main(int argc, char **argv)
{
    t_mlx *m;

    // atexit(ok);
    if(argc < 2)
        return (1);
    m = (t_mlx *)malloc(sizeof(t_mlx));
    if (!m)
        return (1);
    if (!strncmp(argv[1], "Mandelbrot", 10))
        m->id = 1;
    else if (!strncmp(argv[1], "julia", 5))
    {
        if (argc == 4)
        {
            m->id = 3;
            m->r = ft_atof(argv[2]);
            m->i =  ft_atof(argv[3]);
        }
        else
            m->id = 2;
    }
    else if (!strncmp(argv[1], "Burning_ship", 5))
        m->id = 4;
    else
    {
        free(m);
        exit(1);
    }
    ft_init(m);
    ft_draw (m);
    return (0);
}
