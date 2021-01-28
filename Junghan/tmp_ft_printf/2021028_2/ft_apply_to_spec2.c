/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_to_spec2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:13:23 by junghan           #+#    #+#             */
/*   Updated: 2021/01/28 23:57:43 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_print_x_hyphen(int *str_len, int width, int prenum, t_info info)
{
	char *hy_zero;

	if (into.f_hyphen == 0)
	{
		if (info.f_zero == 1 && info.p_existence == 0)
			hy_zero = "0";
		else
			hy_zero = " ";
		if (width > 0)
			while(width--)
				write(1, hy_zero, sizeof(char));
		while (prenum--)
			write(1, "0", sizeof(char));
		write(1, str, (sizeof(char) * str_len));
	}
}

void ft_print_o_hyphen(const char *spec, char *str, t_info info)
{
	int str_len;
	int width;
	int prenum;

	prenum = 0;
	width = 0;
	str_len = ft_strlen(str);
	if (info.p_num > str_len)
		prenum = info.p_num - str_len;
	if (prenum > 0)
		width = info.w_num - info.p_num;
	else
		width = info.w_num - str_len;
	if (into.f_hyphen == 1)
	{
		while(prenum--)
			write(1, "0", sizeof(char));
		write(1, str, (sizeof(char) * str_len));
		if (width > 0)
			while (width--)
				write(1, " ", sizeof(char));
	}
	ft_print_x_hyphen(str_len, width, prenum, info);
}

int	ft_apply_to_int(va_list ap, const char *spec, t_info info)
{
	char *int_str;
	int	count;

	int_str = ft_itoa(va_list(ap, int));
	//count = (info.w_num > info.p_num ? info.w_num : info.p_num); misst
	if (info.p_num < 0)
		return (0);
	if (*spec == 0 && ((info.p_existence == 1 && info.p_num == 0)
				|| info.p_existence == 2))
	{
		while (info.w_num--)
			write(1, " ", sizeof(char));
		return (1);
	}
	ft_print_o_hyphen(spec, int_str, info);
	return (1);
}

void	ft_apply_to_unint(va_list ap, const char *spec, t_info info)
{
	char	*int_str;
	int		count;

	int_str = ft_itoa(va_list(ap, unsigned int));
	if (info.p_num < 0)
	return (0);
	if (*spec == 0 && ((info.p_existence == 1 && info.p_num == 0)
				|| info.p_existence == 2))
	{
		while (info.w_num--)
			write(1, " ", sizeof(char));
		return (1);
	}
	ft_print_o_hyphen(spec, int_str, info);
	return (1);
}

void	ft_apply_to_hex(va_list ap, const char *spec, t_info info)
{
	char			*int_str;
	int				count;
	unsigned int	to_hex;

	to_hex = va_list(ap, unsigned int);
	int_str = ft_chg_to_hex(int_str, spec);
	if (info.p_num < 0)
		return (0);
	if (*spec == 0 && ((info.p_existence == 1 && info.p_num == 0)
				|| info.p_existence == 2))
	{
		while (info.w_num--)
			write(1, " ", sizeof(char));
		return (1);
	}
	ft_print_o_hyphen(spec, int_str, info);
	return (1);
}