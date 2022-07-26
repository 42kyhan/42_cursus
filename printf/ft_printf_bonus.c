/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:31:47 by kyhan             #+#    #+#             */
/*   Updated: 2022/06/06 14:49:26 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_parsed(t_info *info, va_list ap)
{
	int	return_value;

	return_value = 0;
	if (info->type == '%')
		return_value += print_percent(info);
	else if (info->type == 'c')
		return_value += print_char(info, ap);
	else if (info->type == 's')
		return_value += print_str(info, ap);
	else if (info->type == 'd' || info->type == 'i')
		return_value += print_int(info, ap);
	else if (info->type == 'u')
		return_value += print_unsigned(info, ap);
	else if (info->type == 'p' || info->type == 'x' || info->type == 'X')
		return_value += print_ptr(info, ap);
	return (return_value);
}

int	behind_percent(char *format, int *index, va_list ap)
{
	t_info	*info;
	int		return_value;

	return_value = 0;
	(*index)++;
	info = malloc(sizeof(t_info));
	init_info(info);
	while (ftt_strchr("-0.# +123456789", format[*index]))
	{
		setting_info(info, format, *index);
		(*index)++;
	}
	if (ftt_strchr("cspdiuxX%", format[*index]))
	{
		info->type = format[*index];
		return_value += print_parsed(info, ap);
	}
	free(info);
	return (return_value);
}

int	parse_format(va_list ap, char *format)
{
	int	return_value;
	int	index;
	int	*i_point;

	index = 0;
	i_point = &index;
	return_value = 0;
	while (format[index])
	{
		if (format[index] == '%')
		{
			return_value += behind_percent(format, i_point, ap);
		}
		else
		{
			write(1, &format[index], 1);
			return_value++;
		}
		index++;
	}
	return (return_value);
}

int	ft_printf(const char *format, ...)
{
	int		return_value;
	va_list	ap;

	va_start(ap, format);
	return_value = parse_format(ap, (char *)format);
	va_end(ap);
	return (return_value);
}
