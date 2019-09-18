/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_placer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:55:11 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/18 16:02:21 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

t_place	*ft_init_place(int x, int y, int t_x, int t_y, int s)
{
	t_place	*new;

	new = malloc(sizeof(t_place));
	new->m_x = x;
	new->m_y = y;
	new->t_x = t_x;
	new->t_y = t_y;
	new->s_no = s;
	return(new);
}

t_place	*ft_place_finder(t_env *env)
{
	int		x;
	int 	y;
	t_place	*place;
	t_place	*res;

	y= -1;
	while (++y < env->h)
	{
		x = -1;
		while (++x < env->w)
			if (env->ht_map[y][x] == -1)
			{
				place = ft_is_possible(env, y, x);
				if (res == NULL)
					res = place;
				else if (res->s_no > place->s_no)
				{
					//ft_del_place(&res);
					res = place;
				}
				//else
					//ft_del_place(&place);
			}
	}
	return (res);
}

t_place	*ft_is_possible(t_env *env, int x, int y)
{
	int	t_x;
	int	t_y;
	t_place	*place;
	t_place	*res;

	t_y = -1;
	while (++t_y)
	{
		t_x = -1;
		while (++t_x)
			if (env->token->map[t_y][t_x] == '*')
			{
				place = ft_token_mover(env, x, y, t_x, t_y);
				if (res == NULL)
					res = place;
				else if (res->s_no > place->s_no)
				{
					//ft_del_place(&res);
					res = place;
				}
				//else
					//ft_del_place(&place);
			}
	}
	return(res);
}

t_place *ft_token_mover(t_env *env, int x, int y, int t_x, int t_y)
{
	int		d_x;
	int 	d_y;
	int		s;
	t_place	*place;

	d_y = t_y * -1;
	s = -1;
	if (y + d_y < 0 || y + d_y + env->token->y > env->h)
		return(NULL);
	while (d_y + y < env->token->y)
	{
		d_x = t_x * -1;
		if (x + d_x < 0 || x + d_x + env->token->x > env->w)
			return(NULL);
		while (d_x + x < env->token->x)
		{
			if (env->ht_map[y + d_y][x + d_x] == '0' &&
				env->token->map[t_y + d_y][t_x + d_x] == '*')
				return(NULL);
			if (env->token->map[t_y + d_y][t_x + d_x] == '*' && (s == -1 ||
			env->ht_map[y + d_y][x + d_x] < s))
				s = env->ht_map[y + d_y][x + d_x];
		}
	}
	place = ft_init_place(x, y, t_x, t_y, s);
	return(place);
}
