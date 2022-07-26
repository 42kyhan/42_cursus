/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:32:44 by kyhan             #+#    #+#             */
/*   Updated: 2022/06/06 14:48:50 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbrlen(long n)
{
	long	len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr(long n)
{
	char	nbr;

	if (n < 0)
		n *= -1;
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		nbr = '0' + n % 10;
		write(1, &nbr, 1);
	}
	else
	{
		nbr = '0' + n;
		write(1, &nbr, 1);
	}
}

int	print_int(t_info *info, va_list ap)
{
	int		return_value;
	long	arg;

	arg = va_arg(ap, int);
	return_value = 0;
	if (info->minus > -1)
	{
		return_value += putminus(arg);
		return_value += put_plus_space(info, arg);
		return_value += put_space(info, arg);
	}
	else
	{
		return_value += put_space(info, arg);
		return_value += putminus(arg);
		return_value += put_zero(info, arg);
		return_value += put_plus_space(info, arg);
	}
	return (return_value);
}

int	print_unsigned(t_info *info, va_list ap)
{
	int		return_value;
	long	arg;

	arg = va_arg(ap, unsigned int);
	return_value = 0;
	if (info->minus > -1)
	{
		return_value += putminus(arg);
		return_value += put_plus_space(info, arg);
		return_value += put_space(info, arg);
	}
	else
	{
		return_value += put_space(info, arg);
		return_value += putminus(arg);
		return_value += put_zero(info, arg);
		return_value += put_plus_space(info, arg);
	}
	return (return_value);
}
