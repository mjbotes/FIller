/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 09:40:11 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/18 14:16:29 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	size_t			loop;
	unsigned char	*pr;

	loop = 0;
	pr = (int *)ptr;
	while (loop < len)
		pr[loop++] = value;
	return (pr);
}
