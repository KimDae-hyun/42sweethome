/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_digit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 09:13:52 by daekim            #+#    #+#             */
/*   Updated: 2021/03/01 06:27:00 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_only_digit(char *dig)
{
	int	i;

	i = 0;
	while (dig[i])
		if (dig[i] < '0' && dig[i] > '9')
			return (0);
	return (1);
}
