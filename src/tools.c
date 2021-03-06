/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:21:01 by spalmer           #+#    #+#             */
/*   Updated: 2021/01/16 17:11:47 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

void    go_low_lvl(t_all *all)
{
    t_level *temp = NULL;
    
    temp = all->zero_level;
    
	if (all->level->num - 1 == 0)
		all->lower_level = NULL;
    while (temp->num != all->level->num - 1)
    {
		if (temp->num == all->level->num - 2)
			all->lower_level = temp;
		temp = temp->next;
		
	}
    all->level = temp;
}

void		tools(t_all *all)
{
	if(in_button(all->button.up, all))
	{
		if (all->level->next)
		{
			all->lower_level = all->level;
			all->level = all->level->next;
		}
	}
	
	else if(in_button(all->button.down, all))
	{
		if (all->level->num != 0)
			go_low_lvl(all);
	}
	
	else if(in_button(all->button.edit_vertex, all))
		all->button.edit_vertex.press = all->button.edit_vertex.press == 0 ? 1: 0;

}
