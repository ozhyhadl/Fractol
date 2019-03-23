/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:42:19 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/03/21 11:16:39 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void	ft_call_calc(t_all *a, t_frac *f, int x, int y)
{
	int		n;
	double	q_im;
	int		ad;

	ad = (y * H_W + x) * 4;
	f->s_re = f->mi_re + x * f->re_fa;
	f->q_re = f->s_re;
	q_im = f->s_im;
	f->isi = 1;
	n = -1;
	while (++n < f->iteration)
	{
		f->q_re2 = f->q_re * f->q_re;
		f->q_im2 = q_im * q_im;
		if (f->q_re2 + f->q_im2 > 4)
		{
			*(int *)(a->win->addr + ad) = f->color * n;
			f->isi = 0;
			break ;
		}
		q_im = f->frcatal(f, q_im);
	}
}

void	*ft_call_xy(t_all *a)
{
	int		x;
	int		y;
	int		y1;

	y = (H_W / a->trd) * a->i - 1;
	y1 = (H_W / a->trd) * (a->i + 1);
	while (++y < y1)
	{
		a->frac.s_im = a->frac.ma_in - y * a->frac.in_fa;
		x = -1;
		while (++x < H_W)
			ft_call_calc(a, &a->frac, x, y);
	}
	return (NULL);
}

void	ft_tread(t_all a)
{
	pthread_t		tids[a.trd];
	int				i;
	t_all			a1[a.trd];

	i = -1;
	while (++i < a.trd)
	{
		a1[i] = a;
		a1[i].i = i;
		pthread_create(&tids[i], NULL, (void *)ft_call_xy, &a1[i]);
	}
	i = -1;
	while (++i < a.trd)
		pthread_join(tids[i], NULL);
	mlx_clear_window(a.win->ptr, a.win->win);
	mlx_put_image_to_window(a.win->ptr, a.win->win, a.win->img, 0, 0);
	if (a.win->first++ == 0)
		mlx_string_put(a.win->ptr, a.win->win, 30, 30, W_TE, \
			"Manual - Press 'I'");
	mlx_destroy_image(a.win->ptr, a.win->img);
	a.win->img = mlx_new_image(a.win->ptr, H_W, H_W);
}
