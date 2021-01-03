/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:43:22 by spalmer           #+#    #+#             */
/*   Updated: 2020/12/13 01:28:33 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

int	in_grid(t_all *all)
{
	int x_current;
	int x_first;
	int y_first;
	int x_last;
	int y_last;

	x_first = all->mouse.x - (all->setup.grid_step / 2);
	y_first = all->mouse.y - (all->setup.grid_step / 2);
	x_last = all->mouse.x + (all->setup.grid_step / 2);
	y_last = all->mouse.y + (all->setup.grid_step / 2);
	x_current = x_first;
	
	while(y_first <= y_last)
	{
		while(x_current <= x_last)
		{
			if (x_current % all->setup.grid_step == 0 && y_first % all->setup.grid_step == 0)
			{
				all->mouse.x = x_current;
				all->mouse.y = y_first;
				return (1);
			}
			x_current++;
		}
		x_current = x_first;
		y_first++;
	}
	return (0);
}

void	check_grid(t_all *all)
{
	t_vertex	*temp;
	
	if(in_grid(all) == 1)
	{
		temp = new_vertex(all->mouse.x, all->mouse.y);
		if (all->level->sectors == NULL || all->level->sectors->close == 1)
		{
			add_sector(all, new_sector(all));
			all->level->sectors->x0 = all->mouse.x;
			all->level->sectors->y0 = all->mouse.y;
		}
		if (all->level->sectors && all->level->sectors->close == 0)
			ft_lstaddend(&all->level->sectors->vertex, temp);
		if (all->level->sectors->vertex->next && all->level->sectors->x0 == temp->x && all->level->sectors->y0 == temp->y)
				all->level->sectors->close = 1;
	}
}

void		get_grid(t_all *all)
{
	int i;

	i = 0;
	SDL_GetRendererOutputSize(all->win.render, &all->win.w, &all->win.h);
	while (i < (all->win.h * all->win.w))
	{
		if (i % all->setup.grid_step == 0 && (i / all->win.w) % all->setup.grid_step == 0)
			ft_lstaddend(&all->grid, new_vertex(i % all->win.w, i / all->win.w));
		i++;
	}
}
