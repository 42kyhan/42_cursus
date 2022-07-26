/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:03:14 by kyhan             #+#    #+#             */
/*   Updated: 2022/07/26 21:03:14 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_head(t_stack *stack, t_node *node)
{
	node->next = stack->head;
	stack->head = node;
}

void	push_tail(t_stack *stack, t_node *node)
{
	t_node	*curr;

	curr = stack->head;
	if (curr == 0)
	{
		stack->head = node;
		return ;
	}
	while (curr->next != 0)
		curr = curr->next;
	curr->next = node;
	stack->tail = node;
}

t_node	*pop_head(t_stack *stack)
{
	t_node	*node;

	node = stack->head;
	if (node == 0)
		return (0);
	stack->head = node->next;
	node->next = 0;
	return (node);
}

t_node	*pop_tail(t_stack *stack)
{
	t_node	*curr;
	t_node	*res;

	curr = stack->head;
	if (curr == 0)
		return (0);
	while (curr->next != stack->tail)
		curr = curr->next;
	stack->tail = curr;
	res = curr->next;
	curr->next = 0;
	return (res);
}

int	ft_swap(t_stack *stack)
{
	int	tmp;

	if (stack->head == 0 || stack->head->next == 0)
		return (0);
	tmp = stack->head->val;
	stack->head->val = stack->head->next->val;
	stack->head->next->val = tmp;
	tmp = stack->head->idx;
	stack->head->idx = stack->head->next->idx;
	stack->head->next->idx = tmp;
	return (1);
}
