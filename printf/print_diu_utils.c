/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:32:41 by kyhan             #+#    #+#             */
/*   Updated: 2022/06/06 14:49:02 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_final(t_info *info, long n)
{
	int	len;

	len = nbrlen(n);
	if (n < 0)
		len--;
	while (info->precision > len)
	{
		write(1, "0", 1);
		len++;
	}
	if (n == 0 && info->period > -1)
	{
		if (info->precision == 0 && info->width)
			write(1, " ", 1);
		else if (info->precision)
			write(1, "0", 1);
		else
			len--;
	}
	else
		ft_putnbr(n);
	return (len);
}

int	put_zero(t_info *info, long n)
{
	int	return_value;
	int	len;

	len = nbrlen(n);
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

int	put_space(t_info *info, long n)
{
	int	return_value;
	int	len;

	len = nbrlen(n);
	return_value = 0;
	if (info->precision > len)
	{
		len = info->precision;
		if (len < 0)
			len++;
	}
	if ((n > 0) && (info->plus > -1 || info->space > -1))
		len++;
	if (info->is_zero > -1 && info->period > -1)
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

int	put_plus_space(t_info *info, long n)
{
	int	return_value;

	return_value = 0;
	if (info->plus > -1 && n > -1 && info->type != 'u')
	{
		write(1, "+", 1);
		return_value++;
	}
	else if (info->space > -1 && n > -1 && info->type != 'u')
	{
		write(1, " ", 1);
		return_value++;
	}
	return_value += put_final(info, n);
	return (return_value);
}

int	putminus(long n)
{
	int	return_value;

	return_value = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		return_value++;
	}
	return (return_value);
}
