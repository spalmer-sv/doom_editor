/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:21:01 by spalmer           #+#    #+#             */
/*   Updated: 2021/01/03 20:42:24 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

void    go_low_lvl(t_all *all)
{
    t_level *temp = NULL;
    
    temp = all->zero_level;
    
    while (temp->num != all->level->num - 1)
        temp = temp->next;
    all->level = temp;
}

void		tools(t_all *all)
{
	if(in_button(all->button.up, all))
	{
		if (all->level->next)
			all->level = all->level->next;
	}
	
	if(in_button(all->button.down, all))
	{
		if (all->level->num != 0)
			go_low_lvl(all);
	}
}
