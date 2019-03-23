/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:00:29 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/03/21 11:25:12 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <time.h>
# include <pthread.h>
# define H_W 680
# define W_TE 0xFFFFFF

typedef struct	s_win
{
	void		*ptr;
	void		*win;
	void		*img;
	char		*addr;
	int			bit;
	int			line_s;
	int			endia;
	int			lock_key;
	int			help_wi;
	int			first;
	char		*iter;
}				t_win;

typedef struct	s_frac
{
	int			color;
	double		ss_re;
	double		ss_im;
	double		s_re;
	double		s_im;
	double		q_re;
	double		q_re2;
	double		q_im2;
	double		ma_re;
	double		mi_re;
	double		ma_in;
	double		mi_in;
	double		re_fa;
	double		in_fa;
	double		iteration;
	int			num;
	int			isi;
	double		(*frcatal) (struct s_frac *f, double q_im);

}				t_frac;

typedef struct	s_all
{
	t_frac		frac;
	t_win		*win;
	t_win		*help;
	int			trd;
	int			i;
}				t_all;

void			*ft_call_xy(t_all *a);
int				k_key(int key, t_all *all);
void			key_move(int key, t_all *a);
int				key_mose_d(int button, int x, int y, t_all *a);
void			ft_tread(t_all a);
int				key_mouse_move(int x, int y, t_all *a);
void			ft_init(t_frac *f, t_win *win);
void			color_key(t_frac *f);
int				ft_creat_h_w();
void			ft_help_dest(t_win *help);
t_all			*first_step();
int				ft_krest(void);
int				k_rel(int key, t_all *all);
double			ft_malder(t_frac *f, double q_im);
double			ft_julia(t_frac *f, double q_im);
double			ft_ship(t_frac *f, double q_im);
double			ft_buffalo(t_frac *f, double q_im);
double			ft_tricorn(t_frac *f, double q_im);
void			ft_choos(t_frac *f);

#endif
