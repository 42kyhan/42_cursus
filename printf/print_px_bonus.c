/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_px_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:33:02 by kyhan             #+#    #+#             */
/*   Updated: 2022/06/06 14:49:45 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ptr_print(t_info *info, unsigned long long ptr)
{
	int	len;

	len = ptr_len(info, ptr);
	while (info->precision > len)
	{
		write(1, "0", 1);
		len++;
	}
	if (ptr == 0 && info->period > -1)
	{
		if (info->precision)
			write(1, "0", 1);
	}
	else
		ft_puthex(ptr, info->type);
	return (len);
}

int	ptr_zero(t_info *info, unsigned long long ptr)
{
	int	return_value;
	int	len;

	len = ptr_len(info, ptr);
	return_value = 0;
	if (info->precision > len)
		len = info->precision;
	if (info->is_zero > -1 && info->period == -1 && info->minus == -1)
	{
		while (info->width > len++)
		{
			write(1, "0", 1);
			return_value++;
		}
	}
	return (return_value);
}

int	ptr_space(t_info *info, unsigned long long ptr)
{
	int	return_value;
	int	len;

	len = ptr_len(info, ptr);
	return_value = 0;
	if (info->precision > len)
		len = info->precision;
	if (info->hash > -1 || info->type == 'p')
		len += 2;
	if (info->is_zero > -1 && (info->minus > -1 || info->period > -1))
	{
		while (info->width > len++ && ++return_value)
			write(1, " ", 1);
	}
	else if (info->is_zero == -1)
	{
		while (info->width > len++ && ++return_value)
			write(1, " ", 1);
	}
	return (return_value);
}

int	ptr_hash(t_info *info, unsigned long long ptr)
{
	int	return_value;

	return_value = 0;
	if ((info->hash > -1 && ptr != 0) || info->type == 'p')
	{
		if (info->type == 'x' || info->type == 'p')
		{
			write(1, "0x", 2);
			return_value = 2;
		}
		else if (info->type == 'X')
		{
			write(1, "0X", 2);
			return_value = 2;
		}
	}
	return (return_value);
}

int	print_ptr(t_info *info, va_list ap)
{
	int					return_value;
	unsigned long long	ptr;

	return_value = 0;
	if (info->type == 'p')
		ptr = (unsigned long long)va_arg(ap, void *);
	else
		ptr = va_arg(ap, unsigned int);
	if (info->minus > -1)
	{
		return_value += ptr_hash(info, ptr);
		return_value += ptr_print(info, ptr);
		return_value += ptr_space(info, ptr);
	}
	else
	{
		return_value += ptr_space(info, ptr);
		return_value += ptr_hash(info, ptr);
		return_value += ptr_zero(info, ptr);
		return_value += ptr_print(info, ptr);
	}
	return (return_value);
}
