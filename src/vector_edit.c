/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_edit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:25:05 by spalmer           #+#    #+#             */
/*   Updated: 2021/01/16 17:12:23 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

void	change_vertex(t_all *all)
{
	t_sector *temp;
	t_vertex *vtemp;
	
	temp = all->level->sectors;
	
	while (all->level->sectors->number != all->mouse.sector)
		all->level->sectors = all->level->sectors->next;
	vtemp = all->level->sectors->vertex;
	
	while (all->level->sectors->vertex->number != all->mouse.vertex)
		all->level->sectors->vertex = all->level->sectors->vertex->next;
	//printf("sector %i vertex %i\n",temp->sectors->number, temp->sectors->vertex->number);
	all->level->sectors->vertex->x = all->mouse.x;
	all->level->sectors->vertex->y = all->mouse.y;
	
	all->level->sectors->vertex = vtemp;
	all->level->sectors = temp;
	all->mouse.flag_edit_vertex = 0;
	
	return ;
}

void    draw_all_vertex(t_all *all)
{
    t_sector *temp;

    temp = all->level->sectors;
    if (!temp)
        return ;
    while (temp)
    {
        SDL_SetRenderDrawColor(all->win.render, 0xff, 0xff, 0x26, 0);
		draw_vertex(temp->vertex, all, 6);
        temp = temp->next;
    }      
}

void    round_to_grid(t_all *all)
{
    all->mouse.x = (int)(round((float)all->mouse.x / (float)all->setup.grid_step)
        * all->setup.grid_step);
    all->mouse.y = (int)(round((float)all->mouse.y / (float)all->setup.grid_step)
        * all->setup.grid_step);
}

int		itis_vertex(t_all *all)
{
	t_sector 	*temp;
	t_vertex	*vertex;

    temp = all->level->sectors;
    //if (! temp || all->button.edit_vertex.press == 0)
	if (! temp)
        return(0);
    while (temp)
    {
		vertex = temp->vertex;
        while (vertex)
		{
			if (vertex->x == all->mouse.x && vertex->y == all->mouse.y)
			{
				//printf("YES");
				if (all->button.edit_vertex.press == 1)
				{
					all->mouse.flag_edit_vertex = 1;
					all->mouse.sector = temp->number;
					all->mouse.vertex = vertex->number;
					all->mouse.x_vertex = all->mouse.x;
					all->mouse.y_vertex = all->mouse.y;
				}
				
				return (1);
			}
			vertex = vertex->next;
		}
		temp = temp->next;
    }
	return (0);   
}

void	mode_edit_vertex(t_all *all)
{
	round_to_grid(all);
	if (itis_vertex(all) == 1)
	{
		// printf("TRUE sector = %i, vertex = %i\n", all->mouse.sector, all->mouse.vertex);
		return ;
	}
    	// move and drag;
    return ;
}				