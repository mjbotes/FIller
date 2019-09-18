/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:30:46 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/18 14:19:36 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	ft_print_ht_map(t_env *env)
{
	int w;
	int h;

	h = -1;
	while (++h < env->h)
	{
		w = -1;
		while (++w < env->w)
		{
			ft_putnbr(env->ht_map[h][w]);
			ft_putchar('\t');
		}
		ft_putendl("");
	}
}
