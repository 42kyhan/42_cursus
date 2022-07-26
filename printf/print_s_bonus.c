/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:33:22 by kyhan             #+#    #+#             */
/*   Updated: 2022/06/06 14:50:20 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	pr_strlen(t_info *info, char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	if (info->period > -1 && info->precision == 0)
		len = 0;
	else if (info->precision && len > info->precision)
		len = info->precision;
	return (len);
}

int	str_zero(t_info *info, char *str)
{
	int	return_value;
	int	len;

	len = pr_strlen(info, str);
	return_value = 0;
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

int	str_space(t_info *info, char *str)
{
	int	return_value;
	int	len;

	len = pr_strlen(info, str);
	return_value = 0;
	if (info->is_zero > -1 && info->minus > -1)
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

int	ft_putstr(char *str, int len)
{
	int	return_value;

	return_value = 0;
	if (str == NULL)
		return (0);
	while (len > return_value++)
	{
		write(1, str, 1);
		str++;
	}
	return (return_value);
}

int	print_str(t_info *info, va_list ap)
{
	int		return_value;
	char	*str;

	return_value = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	if (info->minus > -1)
	{
		return_value += ft_putstr(str, pr_strlen(info, str));
		return_value += str_space(info, str);
	}
	else
	{
		return_value += str_space(info, str);
		return_value += str_zero(info, str);
		return_value += ft_putstr(str, pr_strlen(info, str));
	}
	return (return_value);
}
