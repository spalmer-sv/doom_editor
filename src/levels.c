/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:24:44 by spalmer           #+#    #+#             */
/*   Updated: 2021/01/04 15:47:05 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

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
	while(lvl <= 9)  
	{
		add_lvl(all, new_lvl(lvl));
		lvl++;
	}
    all->zero_level = all->level;
	all->lower_level = NULL;
   //print_lvl(all);
}


