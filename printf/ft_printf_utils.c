/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:32:10 by kyhan             #+#    #+#             */
/*   Updated: 2022/06/06 14:48:47 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(t_info *info)
{
	info->is_zero = -1;
	info->minus = -1;
	info->period = -1;
	info->plus = -1;
	info->space = -1;
	info->type = -1;
	info->hash = -1;
	info->precision = 0;
	info->width = 0;
}

size_t	ft_strlen(char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ftt_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

int	setting_info_zero(t_info *info, int index)
{
	if (info->period > -1)
		info->precision = info->precision * 10;
	else if (info->width)
		info->width = info->width * 10;
	else
		info->is_zero = index;
	return (1);
}

int	setting_info(t_info *info, char *format, int index)
{
	if (ftt_strchr("0", format[index]))
		return (setting_info_zero(info, index));
	if (ftt_strchr("-.# +", format[index]))
	{
		if (format[index] == '-')
			info->minus = index;
		else if (format[index] == '.')
			info->period = index;
		else if (format[index] == '#')
			info->hash = index;
		else if (format[index] == ' ')
			info->space = index;
		else if (format[index] == '+')
			info->plus = index;
	}
	if (ftt_strchr("123456789", format[index]))
	{
		if (info->period > -1)
			info->precision = info->precision * 10 + (format[index] - '0');
		else
			info->width = info->width * 10 + (format[index] - '0');
		return (1);
	}
	return (0);
}
