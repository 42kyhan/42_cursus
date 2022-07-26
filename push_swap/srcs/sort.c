/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:03:49 by kyhan             #+#    #+#             */
/*   Updated: 2022/07/26 21:03:49 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack)
{
	t_node	*curr;
	int		top;
	int		mid;
	int		bottom;

	curr = stack->head;
	top = curr->idx;
	mid = curr->next->idx;
	bottom = curr->next->next->idx;
	if (mid == max_num(stack) && top == min_num(stack))
	{
		rra(stack);
		sa(stack);
	}
	else if (mid == min_num(stack) && bottom == max_num(stack))
		sa(stack);
	else if (mid == max_num(stack) && bottom == min_num(stack))
		rra(stack);
	else if (top == max_num(stack) && mid == min_num(stack))
		ra(stack);
	else if (top == max_num(stack) && bottom == min_num(stack))
	{
		ra(stack);
		sa(stack);
	}
}

void	sort_5(t_info info)
{
	int	idx;

	idx = find_first(info.stack_a, 0);
	while (idx <= 3 && --idx)
		ra(info.stack_a);
	while (idx > 3 && idx < 6 && idx++)
		rra(info.stack_a);
	if (is_sorted(info.stack_a))
		return ;
	pb(info);
	idx = find_first(info.stack_a, 1);
	if (idx == 2)
		sa(info.stack_a);
	while (idx > 2 && idx < 5 && idx++)
		rra(info.stack_a);
	pb(info);
	sort_3(info.stack_a);
	pa(info);
	pa(info);
}

void	sort_4(t_info info)
{
	int	idx;

	idx = find_first(info.stack_a, 0);
	while (idx <= 2 && --idx)
		ra(info.stack_a);
	while (idx > 2 && idx < 5 && idx++)
		rra(info.stack_a);
	if (is_sorted(info.stack_a))
		return ;
	pb(info);
	sort_3(info.stack_a);
	pa(info);
}

void	hour_glass(t_info info)
{
	int	chunk;
	int	x;

	x = info.stack_a->size;
	chunk = 0.000000053 * (x * x) + 0.03 * x + 14.5;
	a_to_b(info, chunk);
	b_to_a(info);
}

void	sort(t_info info)
{
	if (info.stack_a->size == 2)
		sa(info.stack_a);
	else if (info.stack_a->size == 3)
		sort_3(info.stack_a);
	else if (info.stack_a->size == 4)
		sort_4(info);
	else if (info.stack_a->size == 5)
		sort_5(info);
	else
		hour_glass(info);
}
