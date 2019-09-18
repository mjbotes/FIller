/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:34:40 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/18 16:09:21 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

int	main()
{
	char	*str;
	char	*split;
	int		h;
	t_env	*env;
	t_place	*place;

	h = 0;
	split = ft_strnew(0);
	while (get_next_line(0, &str) > 0)
	{
		h++;
		split= ft_strjoin(split, "\n");
		split= ft_strjoin(split, str);
	}
	env = malloc(sizeof(t_env));
	env->map = ft_strsplit(split, '\n');
	env->h = h - 1;
	env->w = ft_strlen(env->map[0]);
	env->player = 'X';
	env->enemy = 'O';
	ft_heatmap(env);
	h = 0;
	split = ft_strnew(0);
	/*while (get_next_line(0, &str) > 0)
	{
		h++;
		split= ft_strjoin(split, "\n");
		split= ft_strjoin(split, str);
	}*/
	//env->token->map = ft_strsplit(split, '\n');
	env->token->y = h - 1;
	//env->token->x = ft_strlen(env->map[0]);
	//place = ft_place_finder(env);
	//ft_putnbr(place->m_x);
	//ft_putnbr(place->m_y);
	//ft_putnbr(place->t_x);
	//ft_putnbr(place->t_y);
}
