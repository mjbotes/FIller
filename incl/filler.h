/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 08:34:07 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/18 16:01:40 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

typedef struct		s_token 
{
	char			**map;
	int				x;
	int				y;
}					t_token;


typedef struct		s_env
{
	char			**map;
	char			enemy;
	char			player;
	int				w;
	int				h;
	int				**ht_map;
	t_token			*token;
}					t_env;

typedef struct		s_place
{
	int				t_x;
	int				t_y;
	int				m_x;
	int				m_y;
	int				s_no;
}					t_place;


int		**ft_init_hm(t_env *env);
void	ft_set_player(t_env *env);
void	ft_set_enemy(t_env *env);
void	ft_set_ht(t_env *env);
void	ft_heatmap(t_env *env);
void	ft_make_hm(t_env *env);
void	ft_set_enemy(t_env *env);
void	ft_print_ht_map(t_env *env);
int		ft_set_ht_y(int h, int w, t_env *env);
int		ft_set_ht_x(int h, int w, t_env *env);
int		ft_set_ht_xy(int h, int w, t_env *env);
int		ft_set_ht_xy_o(int h, int w, t_env *env);
t_place *ft_token_mover(t_env *env, int x, int y, int t_x, int t_y);
t_place	*ft_is_possible(t_env *env, int x, int y);
t_place	*ft_place_finder(t_env *env);
