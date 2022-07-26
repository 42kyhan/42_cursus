/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:03:16 by kyhan             #+#    #+#             */
/*   Updated: 2022/07/27 08:01:14 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	put_value(int *arr, t_stack *stack_a, int ac)
{
	int		i;
	t_node	*node;

	i = 0;
	stack_a->size = ac;
	while (i < ac)
	{
		node = calloc(1, sizeof(t_node));
		node->val = arr[i];
		push_tail(stack_a, node);
		++i;
	}
}

void	struct_free(t_info info)
{
	t_node	*curr;
	t_node	*tmp;

	curr = info.stack_a->head;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		tmp->val = 0;
		tmp->idx = 0;
		free(tmp);
	}
}

void	is_sorted_checker(t_info info)
{
	t_node	*curr;

	curr = info.stack_a->head;
	while (curr->next)
	{
		if (curr->val > curr->next->val)
		{
			ft_putendl_fd("KO", 1);
			return ;
		}
		curr = curr->next;
	}
	if (info.stack_b->size != 0)
	{
		ft_putendl_fd("KO", 1);
		return ;
	}
	ft_putendl_fd("OK", 1);
}

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
