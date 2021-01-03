/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:37:48 by spalmer           #+#    #+#             */
/*   Updated: 2021/01/03 01:32:45 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

t_level *new_lvl(int i)
{
	t_level *temp;

	temp = (t_level *)malloc(sizeof(t_level));
	temp->num = i;
	temp->next = NULL;
	temp->sectors = NULL;
	return (temp);
}

void		add_lvl(t_all *all, t_level *new)
{
	t_level	*temp;

	temp = all->level;
	if (!new)
		return ;
	if (!temp)
		all->level = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

void	init_level(t_all	*all)
{
	int lvl;
	t_level	*temp = NULL;
	
	lvl = 0;
	all->level = temp;
	all->zero_level = all->level;
	while(lvl <= 9)  
	{
		add_lvl(all, new_lvl(lvl));
		lvl++;
	}
}

void	print_lvl(t_all *all)
{
	t_level *temp;
	
	temp = all->zero_level;
	while (temp)
	{
		printf("%i\n", temp->num);
		temp = temp->next;
	}
}

void	setup(t_all *all)
{
	all->setup.scale = 100;
	all->setup.grid_step = 15;
	all->grid = NULL;
	//all->level = new_lvl(1);
	init_level(all);
	print_lvl(all);
	// all->sectors->vertex = NULL;
	// all->sectors->close = 0;
}

void	print_list(t_all *all)
{
	t_vertex *temp;
	int i;

	i = 0;
	temp = all->grid;
	while(temp->next)
	{
		printf("x = %i  y = %i;", temp->x, temp->y);
		temp = temp->next;
		i++;
	}
}

int	main()
{
	t_all all;
	
	init_win(&all.win);
	setup(&all);
	//get_grid(&all);
	//print_list(&all);
	check_event(&all);
	
	return (0);
}
