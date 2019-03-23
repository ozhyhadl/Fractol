/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 05:32:14 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/03/21 10:16:27 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void		ft_choos(t_frac *f)
{
	if (f->num == 1)
		f->frcatal = ft_malder;
	else if (f->num == 2)
		f->frcatal = ft_julia;
	else if (f->num == 3)
		f->frcatal = ft_ship;
	else if (f->num == 4)
		f->frcatal = ft_buffalo;
	else if (f->num == 5)
		f->frcatal = ft_tricorn;
}

void		ft_init(t_frac *f, t_win *win)
{
	f->mi_re = -2;
	f->ma_re = 1;
	f->mi_in = -1.2;
	f->ma_in = f->mi_in + (f->ma_re - f->mi_re) * H_W / H_W;
	f->iteration = 20;
	f->ss_im = 0;
	f->ss_re = 0;
	f->color = 001400000;
	f->re_fa = (f->ma_re - f->mi_re) / (H_W - 1);
	f->in_fa = (f->ma_in - f->mi_in) / (H_W - 1);
	win->lock_key = 0;
	win->first = 0;
}

t_win		*init_help(void)
{
	t_win	*help;

	if ((help = malloc(sizeof(t_win))) == NULL)
		return (0);
	help->ptr = mlx_init();
	help->help_wi = 0;
	return (help);
}

t_win		*init_win(void)
{
	t_win	*tmp;

	if ((tmp = (t_win *)malloc(sizeof(t_win))) == NULL)
		return (NULL);
	tmp->ptr = mlx_init();
	tmp->win = mlx_new_window(tmp->ptr, H_W, H_W, "Chegevara");
	tmp->img = mlx_new_image(tmp->ptr, H_W, H_W);
	tmp->addr = mlx_get_data_addr(tmp->img, &tmp->bit, &tmp->line_s, \
									&tmp->endia);
	return (tmp);
}

t_all		*first_step(void)
{
	t_all	*alltmp;
	t_frac	*fractmp;

	srand(time(NULL));
	if ((alltmp = (t_all *)malloc(sizeof(t_all))) == NULL)
		return (NULL);
	if ((fractmp = (t_frac *)malloc(sizeof(t_frac))) == NULL)
		return (NULL);
	alltmp->help = init_help();
	alltmp->win = init_win();
	ft_init(fractmp, alltmp->win);
	alltmp->frac = *fractmp;
	alltmp->trd = 8;
	free(fractmp);
	return (alltmp);
}
