/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:03:32 by kyhan             #+#    #+#             */
/*   Updated: 2022/07/26 21:03:32 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*init_arr(char **strs, int ac)
{
	int	*arr;

	arr = ft_calloc(1, sizeof(int) * ac);
	if (arr == 0)
		ft_error(strs);
	return (arr);
}

int	*ft_adtoi(int i, char **strs, int ac)
{
	int	num;
	int	j;
	int	sign;
	int	*arr;

	arr = init_arr(strs, ac);
	while (strs[i])
	{
		num = 0;
		sign = 1;
		j = check_sign(strs[i][0], strs[i][1], &sign);
		while (strs[i][j])
		{
			num *= 10;
			num += sign * (strs[i][j] - '0');
			if (!ft_isdigit(strs[i][j++]) || (sign == 1 && num < 0) || \
				(sign == -1 && num > 0))
				ft_error(strs);
		}
		arr[i] = sign * num;
		if (is_dup(arr, i++))
			ft_error(strs);
	}
	return (arr);
}
