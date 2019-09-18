/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 08:46:02 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/18 16:07:37 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

int	**ft_init_hm(t_env *env)
{
	int **ht_map;
	int	t_w;
	int	t_h;

	t_h = 0;
	ht_map = (int **)malloc(sizeof(int *) * env->h);
	while (t_h < env->h)
	{
		ht_map[t_h] = (int *)malloc(sizeof(int) * env->w);
		t_w = -1;
		while (++t_w < env->w)
		{
			ht_map[t_h][t_w] = -1;
		}
		t_h++;
	}
	env->ht_map = ht_map;
	return (ht_map);
}

void	ft_make_hm(t_env *env)
{
				ft_set_ht(env);
}

void	ft_heatmap(t_env *env)
{
	int **ht_map;

	ht_map = ft_init_hm(env);
	ft_set_enemy(env);
	ft_print_ht_map(env);
	ft_make_hm(env);
	ft_set_player(env);
	ft_print_ht_map(env);
}
