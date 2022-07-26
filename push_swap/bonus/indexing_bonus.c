/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:03:11 by kyhan             #+#    #+#             */
/*   Updated: 2022/07/26 21:03:11 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_idx_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	q_sort(int *arr, int l, int r)
{
	int	left;
	int	right;
	int	pivot;

	pivot = arr[(l + r) / 2];
	left = l;
	right = r;
	while (left <= right)
	{
		while (arr[left] < pivot)
			left++;
		while (arr[right] > pivot)
			right--;
		if (left <= right)
			ft_idx_swap(&arr[left++], &arr[right--]);
	}
	if (l < right)
		q_sort(arr, l, right);
	if (r > left)
		q_sort(arr, left, r);
}

void	indexing(int *arr, t_stack *stack, int ac)
{
	t_node	*curr;
	int		i;

	curr = stack->head;
	q_sort(arr, 0, ac - 1);
	while (curr)
	{
		i = 0;
		while (i < ac)
		{
			if (arr[i] == curr->val)
			{
				curr->idx = i;
				break ;
			}
			i++;
		}
		curr = curr->next;
	}
}
