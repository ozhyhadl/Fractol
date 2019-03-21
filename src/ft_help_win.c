/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hepl_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 02:46:55 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/03/21 08:20:38 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void	ft_help_dest(t_win *help)
{
	mlx_destroy_window(help->ptr, help->win);
	help->help_wi = 0;
}

int		k_help_close_x(t_win *help)
{
	ft_help_dest(help);
	return (0);
}

int		k_help_close(int key, t_win *help)
{
	if (key == 53)
		ft_help_dest(help);
	return (0);
}

int		k_help_close_i(int key, t_win *help)
{
	if (key == 34)
		ft_help_dest(help);
	return (0);
}

int		ft_creat_h_w(t_all *a)
{
	if (a->help->help_wi == 0)
	{
		a->help->win = mlx_new_window(a->help->ptr, 200, 400, "Info");
		a->help->help_wi = 1;
	}
	else
		ft_help_dest(a->help);
	mlx_string_put(a->help->ptr, a->help->win, 60, 10, W_TE, "MANUAL");
	mlx_string_put(a->help->ptr, a->help->win, 30, 40, W_TE, "Quit = ESC");
	mlx_string_put(a->help->ptr, a->help->win, 30, 60, W_TE, "Color = C");
	mlx_string_put(a->help->ptr, a->help->win, 30, 80, W_TE, "Iteration = +/-");
	mlx_string_put(a->help->ptr, a->help->win, 30, 100, W_TE, "Reset = R");
	mlx_string_put(a->help->ptr, a->help->win, 30, 120, W_TE, "Lock mouse = M");
	mlx_string_put(a->help->ptr, a->help->win, 60, 150, W_TE, "DANGER");
	mlx_string_put(a->help->ptr, a->help->win, 30, 180, W_TE, \
					"LSD(random) = L");
	mlx_hook(a->help->win, 2, 5, k_help_close, a->help);
	mlx_hook(a->help->win, 3, 5, k_help_close_i, a->help);
	mlx_hook(a->help->win, 17, 5, k_help_close_x, a->help);
	mlx_loop(a->help->ptr);
	return (0);
}
