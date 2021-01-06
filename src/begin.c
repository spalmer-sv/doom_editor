/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:37:48 by spalmer           #+#    #+#             */
/*   Updated: 2021/01/06 17:05:32 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

void	setup(t_all *all)
{
	all->setup.scale = 100;
	all->setup.grid_step = 10;
	all->grid = NULL;
//	all->mouse.vertex_to_change = NULL;
	all->mouse.flag_edit_vertex = 0;
	//all->level = new_lvl(1);
	init_level(all);
	init_menu_button(all);
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
