/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:02:49 by kyhan             #+#    #+#             */
/*   Updated: 2022/07/26 21:10:57 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	command_error(void)
{
	ft_putendl_fd("Error", 2);
	return (0);
}

static int	command_compare(char *line, t_info info)
{
	if (!ft_strncmp(line, "ra\n", 3))
		ra(info.stack_a);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(info.stack_b);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(info);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(info.stack_a);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(info.stack_b);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(info);
	else if (!ft_strncmp(line, "sa\n", 3))
		sa(info.stack_a);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(info.stack_b);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(info);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(info);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(info);
	else
		return (command_error());
	return (1);
}

void	push_swap_read(t_info info)
{
	char	*line;
	t_node	*curr;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
		{
			is_sorted_checker(info);
			return ;
		}	
		if (command_compare(line, info) == 0)
			return ;
		curr = info.stack_a->head;
		while (curr)
			curr = curr->next;
		free(line);
	}
}

int	main(int argc, char **argv)
{
	char	**strs;
	int		ac;
	int		*arr;
	t_info	info;

	if (argc < 2)
		return (0);
	ac = parsing(&strs, argv + 1);
	info.stack_a = calloc(1, sizeof(t_stack));
	info.stack_b = calloc(1, sizeof(t_stack));
	arr = ft_adtoi(0, strs, ac);
	put_value(arr, info.stack_a, ac);
	indexing(arr, info.stack_a, ac);
	push_swap_read(info);
	free(arr);
	ft_free(strs);
}
