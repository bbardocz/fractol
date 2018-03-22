/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:27:00 by bbardocz          #+#    #+#             */
/*   Updated: 2017/11/10 17:43:45 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int i;
	int y;

	y = 0;
	i = ft_strlen(s1);
	while (s2[y] != '\0')
	{
		s1[i] = s2[y];
		i++;
		y++;
	}
	s1[i] = '\0';
	return (s1);
}