/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 20:56:28 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/03/21 10:46:57 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void	error_check(void)
{
	ft_putstr("usage: ./fractol (Int) 1 to 5\n");
	ft_putstr("1 - Mandelbrot\n2 - Julia\n3 - Ship\n");
	ft_putstr("4 - Buffalo\n5 - Tricorn\n");
}

int		check(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc < 2)
	{
		error_check();
		return (0);
	}
	while (++i < argc)
		if (ft_atoi(argv[i]) < 1 || ft_atoi(argv[i]) > 5)
		{
			error_check();
			return (0);
		}
	return (1);
}

void	ft_space(int argc, char **argv)
{
	int i;

	i = 1;
	while (++i < argc)
	{
		if (ft_atoi(argv[i]) == 1)
			system("./fractol 1&");
		if (ft_atoi(argv[i]) == 2)
			system("./fractol 2&");
		if (ft_atoi(argv[i]) == 3)
			system("./fractol 3&");
		if (ft_atoi(argv[i]) == 4)
			system("./fractol 4&");
		if (ft_atoi(argv[i]) == 5)
			system("./fractol 5&");
	}
}

int		main(int argc, char **argv)
{
	t_all	*all;

	if (check(argc, argv) == 0)
		return (0);
	all = first_step();
	all->frac.num = (ft_atoi(argv[1]));
	ft_choos(&all->frac);
	if (argc > 2)
		ft_space(argc, argv);
	ft_tread(*all);
	mlx_hook(all->win->win, 2, 5, k_key, all);
	mlx_hook(all->win->win, 3, 5, k_rel, all);
	mlx_hook(all->win->win, 4, 5, key_mose_d, all);
	mlx_hook(all->win->win, 17, 5, ft_krest, (void *)0);
	if (all->frac.num == 2)
		mlx_hook(all->win->win, 6, 5, key_mouse_move, all);
	mlx_loop(all->win->ptr);
	return (0);
}
