/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mani.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:03:42 by kyhan             #+#    #+#             */
/*   Updated: 2022/07/26 21:03:42 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	this_is_for_you(t_stack *stack, int i, int chunk)
{
	t_node	*curr;
	int		cnt;

	curr = stack->head;
	cnt = 0;
	while (curr && curr->idx > chunk + i)
	{
	cnt++;
	curr = curr->next;
	}
	if (cnt > stack->size / 2)
		return (1);
	return (0);
}

void	a_to_b(t_info info, int chunk)
{
	t_node	*curr;

	while (info.stack_a->size)
	{
		curr = info.stack_a->head;
		if (curr->idx <= info.stack_b->size)
			pb(info);
		else if (curr->idx > info.stack_b->size \
			&& curr->idx <= info.stack_b->size + chunk)
		{
			pb(info);
			rb(info.stack_b);
		}
		else if (curr->idx > info.stack_b->size + chunk)
		{
			if (this_is_for_you(info.stack_a, info.stack_b->size, chunk) == 1)
				rra(info.stack_a);
			else
				ra(info.stack_a);
		}
	}
}

void	sort_b(t_stack *stack)
{
	t_node	*curr;
	int		i;

	i = 0;
	curr = stack->head;
	while ((stack->size - 1) != curr->idx)
	{
		i++;
		curr = curr->next;
	}
	while (i <= stack->size / 2 && i--)
		rb(stack);
	while (i > stack->size / 2 && i < stack->size && i++)
		rrb(stack);
}

void	b_to_a(t_info info)
{
	while (info.stack_b->size)
	{
		sort_b(info.stack_b);
		pa(info);
	}
}
