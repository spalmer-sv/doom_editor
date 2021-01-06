/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:00:38 by spalmer           #+#    #+#             */
/*   Updated: 2021/01/06 18:00:35 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

void	check_botton(SDL_Event *event, t_all *all, int *quit)
{
	if (event->key.keysym.sym == SDLK_ESCAPE)
		*quit = 1;
}

void	check_event(t_all *all)
{
	SDL_Event	event;
	int			quit;
	SDL_Rect pixel;
	quit = 0;
	get_grid(all);
	while (!quit)
	{
		SDL_SetRenderDrawColor(all->win.render, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(all->win.render);
			
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = 1;
				break ;
			}
			if (event.type == SDL_KEYDOWN)
				check_botton(&event, all, &quit);
			
			if( event.type == SDL_MOUSEBUTTONDOWN)
			{
				all->mouse.x = event.motion.x;
				all->mouse.y = event.motion.y;
				check_viewport(all);
			}
			if(all->mouse.flag_edit_vertex == 1 && all->button.edit_vectors.press == 1 && event.type == SDL_MOUSEBUTTONUP)
			{
				all->mouse.x = event.motion.x;
				all->mouse.y = event.motion.y;
				round_to_grid(all);
				if (all->mouse.x != all->mouse.x_vertex && all->mouse.y != all->mouse.y_vertex)
					change_vertex(all);
			}
			SDL_SetRenderDrawColor(all->win.render, 0x00, 0x00, 0x00, 0x00);
			SDL_RenderClear(all->win.render);    
			
			SDL_SetRenderDrawColor(all->win.render, 0x63, 0x63, 0x63, 0);
			draw_vertex(all->grid, all, 2); // draw grid
			if (all->level->sectors && all->button.edit_vectors.press == 0)
			{
				SDL_SetRenderDrawColor(all->win.render, 0xff, 0x3b, 0xb4, 0);
				draw_vertex(all->level->sectors->vertex, all, 6);
			}
			if (all->button.edit_vectors.press == 1)
				draw_all_vertex(all);
			SDL_SetRenderDrawColor(all->win.render, 0xff, 0xff, 0xff, 0);
			draw_sectors(all); 

			draw_menu(all);
			
			SDL_RenderPresent(all->win.render);
		}
	}
	////////////////printf number of sectors
	// while (all->level->sectors)
	// {
	// 	while(all->level->sectors->vertex)
	// 	{
	// 		printf ("vertex %i\n", all->level->sectors->vertex->number);
	// 		all->level->sectors->vertex = all->level->sectors->vertex->next;
	// 	}
	// 	printf ("sectors%i\n", all->level->sectors->number);
	// 	all->level->sectors = all->level->sectors->next;
	// }
	destroy(all);
}