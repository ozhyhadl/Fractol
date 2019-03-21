/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:05:36 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/03/21 08:20:46 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void	k_key_2(int key, t_all *all)
{
	if (key == 46 && all->win->lock_key == 0)
		all->win->lock_key = 1;
	else if (key == 46)
		all->win->lock_key = 0;
	else if (key == 34 && all->help->help_wi == 0)
		ft_creat_h_w(all);
}

int		k_key(int key, t_all *all)
{
	if (key == 46 || key == 34)
		k_key_2(key, all);
	else
	{
		if (key == 53)
			exit(0);
		else if (key == 37)
			all->frac.color = rand() % 14200000;
		else if (key == 8)
			color_key(&all->frac);
		else if (key == 69 && all->frac.iteration < 500)
			all->frac.iteration++;
		else if (key == 78 && all->frac.iteration > 5)
			all->frac.iteration--;
		else if (key == 15)
			ft_init(&all->frac, all->win);
		ft_tread(*all);
	}
	return (0);
}

void	color_key(t_frac *f)
{
	static int i = 0;

	if (i == 0)
		f->color = 000000010;
	else if (i == 1)
		f->color = 00010000;
	else if (i == 2)
		f->color = 16777215;
	else if (i == 3)
		f->color = 001002004;
	else if (i == 4)
		f->color = 100000000;
	else if (i == 5)
		f->color = 001001202;
	else if (i == 6)
		f->color = 003000010;
	if (i++ > 5)
		i = 0;
}

int		key_mose_d(int key, int x, int y, t_all *a)
{
	double mouse_re;
	double mouse_im;
	double p_n;

	if ((key == 4 && a->frac.ma_re < 25) || key == 5)
	{
		p_n = (key == 5 ? 1.1 : 0.9);
		if (key == 4 && a->frac.iteration > 5)
			a->frac.iteration--;
		else if (key == 5 && a->frac.iteration < 500)
			a->frac.iteration++;
		y = H_W - y;
		mouse_re = (double)x / (H_W / (a->frac.ma_re - \
					a->frac.mi_re)) + a->frac.mi_re;
		mouse_im = (double)y / (H_W /
			(a->frac.ma_in - a->frac.mi_in)) + a->frac.mi_in;
		a->frac.mi_re = mouse_re + ((a->frac.mi_re - mouse_re) * (1 / p_n));
		a->frac.mi_in = mouse_im + ((a->frac.mi_in - mouse_im) * (1 / p_n));
		a->frac.ma_re = mouse_re + ((a->frac.ma_re - mouse_re) * (1 / p_n));
		a->frac.ma_in = mouse_im + ((a->frac.ma_in - mouse_im) * (1 / p_n));
		a->frac.re_fa = (a->frac.ma_re - a->frac.mi_re) / (H_W - 1);
		a->frac.in_fa = (a->frac.ma_in - a->frac.mi_in) / (H_W - 1);
		ft_tread(*a);
	}
	return (0);
}

int		key_mouse_move(int x, int y, t_all *a)
{
	if ((x > 0 && x < H_W && y > 0 && y < H_W) && a->win->lock_key == 0)
	{
		a->frac.ss_re = (x * 0.006) / 2;
		a->frac.ss_im = (x * 0.006) / 2;
		ft_tread(*a);
	}
	return (0);
}
