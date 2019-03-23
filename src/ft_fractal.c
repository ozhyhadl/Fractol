/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 06:35:44 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/03/21 10:59:45 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

double	ft_malder(t_frac *f, double q_im)
{
	q_im = 2 * f->q_re * q_im + f->s_im;
	f->q_re = f->q_re2 - f->q_im2 + f->s_re;
	return (q_im);
}

double	ft_julia(t_frac *f, double q_im)
{
	q_im = 2 * f->q_re * q_im + f->ss_im / H_W;
	f->q_re = f->q_re2 - f->q_im2 + f->ss_re / H_W;
	return (q_im);
}

double	ft_ship(t_frac *f, double q_im)
{
	q_im = fabs(2 * f->q_re * q_im) - f->s_im;
	f->q_re = fabs(f->q_re2 - f->q_im2 + f->s_re);
	return (q_im);
}

double	ft_buffalo(t_frac *f, double q_im)
{
	q_im = 2 * fabs(f->q_re * q_im) - f->s_im;
	f->q_re = fabs(f->q_re2 - f->q_im2) + f->s_re;
	return (q_im);
}

double	ft_tricorn(t_frac *f, double q_im)
{
	q_im = -1 * (2 * f->q_re * q_im) + f->s_im;
	f->q_re = f->q_re2 - f->q_im2 + f->s_re;
	return (q_im);
}
