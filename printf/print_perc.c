/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_perc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:32:57 by kyhan             #+#    #+#             */
/*   Updated: 2022/06/06 14:49:05 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_space(t_info *info)
{
	int	return_value;

	return_value = 0;
	while (info->width > ++return_value)
		write(1, " ", 1);
	return (return_value);
}

int	print_zero(t_info *info)
{
	int	return_value;

	return_value = 0;
	while (info->width > ++return_value)
		write(1, "0", 1);
	return (return_value);
}

int	print_percent(t_info *info)
{
	int	return_value;

	return_value = 0;
	if (info->minus > -1)
	{
		write(1, "%", 1);
		return_value += print_space(info);
	}
	else
	{
		if (info->is_zero == -1)
			return_value += print_space(info);
		else
			return_value += print_zero(info);
		write(1, "%", 1);
	}
	return (return_value);
}

int	print_char(t_info *info, va_list ap)
{
	int				return_value;
	unsigned char	arg;

	arg = va_arg(ap, int);
	return_value = 0;
	if (info->minus > -1)
	{
		write(1, &arg, 1);
		return_value += print_space(info);
	}
	else
	{
		if (info->is_zero == -1)
			return_value += print_space(info);
		else
			return_value += print_zero(info);
		write(1, &arg, 1);
	}
	return (return_value);
}
