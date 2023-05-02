/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:16:07 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/05/02 16:38:45 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	julia_check(t_mlx *m, char **argv)
{
	if (!num_check(argv[2]) || !num_check(argv[3]))
	{
		fractal_options();
		free(m);
		exit(1);
	}
	m->id = 3;
	m->r = ft_atof(argv[2]);
	m->i = ft_atof(argv[3]);
	if (fabs(m->r) > 2 || fabs(m->i) > 2)
	{
		fractal_options();
		free(m);
		exit(1);
	}	
}

void	check_args(t_mlx *m, int argc, char **argv)
{
	if (!ft_strncmp(argv[1], "Mandelbrot", 10) && argc == 2)
		m->id = 1;
	else if (!ft_strncmp(argv[1], "julia", 5) && (argc == 2 || argc == 4))
	{
		if (argc == 4)
			julia_check(m, argv);
		else
			m->id = 2;
	}
	else
	{
		fractal_options();
		free(m);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_mlx	*m;

	if (argc < 2)
	{
		fractal_options();
		return (1);
	}
	m = (t_mlx *)malloc(sizeof(t_mlx));
	if (!m)
		return (1);
	check_args (m, argc, argv);
	ft_init(m);
	help_msg();
	ft_draw(m);
	return (0);
}
