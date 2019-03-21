/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 06:00:05 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/03/21 08:20:43 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int		ft_krest(void)
{
	exit(0);
}

int		k_rel(int key, t_all *all)
{
	if (key == 34 && all->help->help_wi == 1)
		ft_help_dest(all->help);
	return (0);
}
