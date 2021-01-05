/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_edit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:25:05 by spalmer           #+#    #+#             */
/*   Updated: 2021/01/05 21:02:07 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

void    draw_all_vertex(t_all *all)
{
    t_sector *temp;

    temp = all->level->sectors;
    if (! temp || all->button.edit_vectors.press == 0)
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
    // printf ("x before %i  ", all->mouse.x);
    // printf ("y before %i\n", all->mouse.y);
    all->mouse.x = (int)(round((float)all->mouse.x / (float)all->setup.grid_step)
        * all->setup.grid_step);
    all->mouse.y = (int)(round((float)all->mouse.y / (float)all->setup.grid_step)
        * all->setup.grid_step);
}

int		itis_vertex(t_all *all)
{
	t_sector *temp;
	t_vertex	*vertex;

    temp = all->level->sectors;
    if (! temp || all->button.edit_vectors.press == 0)
        return(0);
    while (temp)
    {
		vertex = temp->vertex;
        while (vertex)
		{
			if (vertex->x == all->mouse.x && vertex->y == all->mouse.y)
			{
				all->mouse.vertex_to_change = vertex;
				//printf("YES");
				return (1);
			}
			vertex = vertex->next;
		}
		temp = temp->next;
    }
	return (0);   
}

void	mode_edit_vector(t_all *all)
{
	//in_grid(all);
	round_to_grid(all);
	if (itis_vertex(all) == 1)
		return ;
	// 	printf("YES");
	// else
	// 	printf("NO");
	
    // check_all vectors of level
	
    // move and drag;
    return ;
}				