/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_px_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:33:13 by kyhan             #+#    #+#             */
/*   Updated: 2022/06/06 14:50:40 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_len(t_info *info, unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0 && info->period > -1 && info->precision == 0)
		return (0);
	else if (ptr == 0)
		return (1);
	while (ptr)
	{
		ptr /= 16;
		len ++;
	}
	return (len);
}

void	ft_puthex(unsigned long long ptr, char type)
{
	char	c;

	if (ptr >= 16)
	{
		ft_puthex((ptr / 16), type);
		if ((ptr % 16) >= 10 && (type == 'x' || type == 'p'))
			c = 'a' + (ptr % 16) - 10;
		else if ((ptr % 16) >= 10 && type == 'X')
			c = 'A' + (ptr % 16) - 10;
		else
			c = '0' + (ptr % 16);
		write(1, &c, 1);
	}
	else
	{
		if ((ptr % 16) >= 10 && (type == 'x' || type == 'p'))
			c = 'a' + (ptr % 16) - 10;
		else if ((ptr % 16) >= 10 && type == 'X')
			c = 'A' + (ptr % 16) - 10;
		else
			c = '0' + (ptr % 16);
		write(1, &c, 1);
	}
}
