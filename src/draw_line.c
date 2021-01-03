/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:00:11 by spalmer           #+#    #+#             */
/*   Updated: 2020/12/12 23:25:53 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

void	bresenham(int x0, int y0, int x1, int y1, t_all *all)
{
	int dx;
	int dy;
	int error;
	int error2;
	int sign_y;
	int sign_x;
	SDL_Rect pixel;
	
	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	error = dx - dy;
	sign_x = x0 < x1 ? 1: -1;
	sign_y = y0 < y1 ? 1: -1;
	

	while (x0 != x1 || y0 != y1)
	{
		pixel = init_rect(x0, y0, 2, 2);
		SDL_RenderDrawRect(all->win.render, &pixel);
		error2 = error *2;
		if (error2 > -dy)
		{
			error -= dy;
			x0 += sign_x;
		}
		if (error2 < dx)
		{
			error += dx;
			y0 += sign_y;
		}
	}	
}

// void	draw_one_sector(t_all *all)
// {
// 	t_vertex *temp;
// 	t_vertex first;
// 	t_vertex second;
	
// 	temp = all->sectors->vertex;
// 	if (all->sectors == NULL || all->sectors->vertex == NULL || all->sectors->vertex->next == NULL)
// 		return ;
// 	SDL_SetRenderDrawColor(all->win.render, 0xff, 0xff, 0xff, 0);
// 	while(temp->next)
// 	{
// 		first.x = temp->x;
// 		first.y = temp->y;
// 		second.x = temp->next->x;
// 		second.y = temp->next->y;
// 		bresenham(first.x * 2, first.y * 2, second.x * 2, second.y * 2, all);
// 		temp = temp->next;
// 	}
// }

void	draw_one_sector(t_sector *sector, t_all *all)
{
	t_vertex *temp;
	t_vertex first;
	t_vertex second;
	
	temp = sector->vertex; //SEGA!!!!!!!!
	if (sector->vertex == NULL)
		return ;
	if (!sector->vertex->next)
		return ;
	SDL_SetRenderDrawColor(all->win.render, 0xff, 0xff, 0xff, 0);
	while(temp->next)
	{
		first.x = temp->x;
		first.y = temp->y;
		second.x = temp->next->x;
		second.y = temp->next->y;
		bresenham(first.x * 2, first.y * 2, second.x * 2, second.y * 2, all);
		temp = temp->next;
	}
}

void	draw_sectors(t_all *all)
{
	t_sector *temp;
	
	temp = all->level->sectors;
	if (!temp || !temp->vertex)
		return ;
	while (temp)
	{
		draw_one_sector(temp, all);
		temp = temp->next;
	}
}