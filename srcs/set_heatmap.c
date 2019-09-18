/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_heatmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:08:42 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/18 14:53:28 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	ft_set_ht(t_env *env)
{
	int	res;
	int	h;
	int w;
	int old_res;

	res = -1;
	while (res != old_res)
	{
		old_res = res;
		res = 0;
		h = -1;
		while (++h < env->h)
		{
			w = -1;
			while(++w < env->w)
			{
				if (env->ht_map[h][w] != -1)
				{
					res += ft_set_ht_y(h, w, env);
					res += ft_set_ht_x(h, w, env);
					res += ft_set_ht_xy(h, w, env);
					res += ft_set_ht_xy_o(h, w, env);
				}
			}
		}
	}
}

int	ft_set_ht_y(int h, int w, t_env *env)
{
	int i;
	int t_w;
	int	res;

	t_w = w;
	i = env->ht_map[h][w];
	while (++t_w < env->w)
		if (env->ht_map[h][t_w] == 0 || (env->ht_map[h][t_w] <= i && env->ht_map[h][t_w] != -1))
			break ;
		else
			env->ht_map[h][t_w] = ++i;
	t_w = w;
	res = i - env->ht_map[h][w];
	i = env->ht_map[h][w];
	while (--t_w >= 0)
		if (env->ht_map[h][t_w] == 0 || (env->ht_map[h][t_w] <= i && env->ht_map[h][t_w] != -1))
			break ;
		else
			env->ht_map[h][t_w] = ++i;
	res += i - env->ht_map[h][w];
	return (res);
}

int	ft_set_ht_x(int h, int w, t_env *env)
{
	int i;
	int t_h;
	int	res;

	t_h = h;
	i = env->ht_map[h][w];
	while (++t_h < env->h)
		if (env->ht_map[t_h][w] == 0 || (env->ht_map[t_h][w] <= i && env->ht_map[t_h][w] != -1))
			break ;
		else
			env->ht_map[t_h][w] = ++i;
	t_h = h;
	res = i - env->ht_map[h][w];
	i = env->ht_map[h][w];
	while (--t_h >= 0)
		if (env->ht_map[t_h][w] == 0 || (env->ht_map[t_h][w] <= i && env->ht_map[t_h][w] != -1))
			break ;
		else
			env->ht_map[t_h][w] = ++i;
	res += i - env->ht_map[h][w];
	return (res);
}

int	ft_set_ht_xy(int h, int w, t_env *env)
{
	int i;
	int t_w;
	int	t_h;
	int	res;

	t_w = w;
	t_h = h;
	i = env->ht_map[h][w];
	while (++t_w < env->w && ++t_h < env->h)
		if (env->ht_map[t_h][t_w] == 0 || (env->ht_map[t_h][t_w] <= i && env->ht_map[t_h][t_w] != -1))
			break ;
		else
			env->ht_map[t_h][t_w] = ++i;
	t_w = w;
	t_h = h;
	res = i - env->ht_map[h][w];
	i = env->ht_map[h][w];
	while (--t_w >= 0 && --t_h >= 0)
		if (env->ht_map[t_h][t_w] == 0 || (env->ht_map[t_h][t_w] <= i && env->ht_map[t_h][t_w] != -1))
			break ;
		else
			env->ht_map[t_h][t_w] = ++i;
	res += i - env->ht_map[h][w];
	return (res);
}

int	ft_set_ht_xy_o(int h, int w, t_env *env)
{
	int i;
	int t_w;
	int	t_h;
	int	res;

	t_w = w;
	t_h = h;
	i = env->ht_map[h][w];
	while (--t_w >= 0 && ++t_h < env->h)
		if (env->ht_map[t_h][t_w] == 0 || (env->ht_map[t_h][t_w] <= i && env->ht_map[t_h][t_w] != -1))
			break ;
		else
			env->ht_map[t_h][t_w] = ++i;
	t_w = w;
	t_h = h;
	res = i - env->ht_map[h][w];
	i = env->ht_map[h][w];
	while (++t_w < env->w && --t_h >= 0)
		if (env->ht_map[t_h][t_w] == 0 || (env->ht_map[t_h][t_w] <= i && env->ht_map[t_h][t_w] != -1))
			break ;
		else
			env->ht_map[t_h][t_w] = ++i;
	res += i - env->ht_map[h][w];
	return (res);
}

void	ft_set_enemy(t_env *env)
{
	int	h;
	int	w;

	h = -1;
	while (++h < env->h - 1)
	{
		w = -1;
		while (++w < env->w - 1)
			if (env->map[h][w] == env->enemy)
				env->ht_map[h][w] = 0;
	}
}

void	ft_set_player(t_env *env)
{
	int	h;
	int	w;

	h = -1;
	while (++h < env->h)
	{
		w = -1;
		while (++w < env->w)
			if (env->map[h][w] == env->player)
				env->ht_map[h][w] = -1;
	}
}
