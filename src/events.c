/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:00:38 by spalmer           #+#    #+#             */
/*   Updated: 2021/01/03 18:31:56 by spalmer          ###   ########.fr       */
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
			
			if( event.type == SDL_MOUSEBUTTONDOWN )
			{
				all->mouse.x = event.motion.x;
				all->mouse.y = event.motion.y;
				check_viewport(all);
			}
			SDL_SetRenderDrawColor(all->win.render, 0x00, 0x00, 0x00, 0x00);
			SDL_RenderClear(all->win.render);
			
			SDL_SetRenderDrawColor(all->win.render, 0x63, 0x63, 0x63, 0);
			draw_vertex(all->grid, all, 2); // draw grid
			if (all->level->sectors)
			{
				SDL_SetRenderDrawColor(all->win.render, 0xff, 0x3b, 0xb4, 0);
				draw_vertex(all->level->sectors->vertex, all, 6);
			}
			SDL_SetRenderDrawColor(all->win.render, 0xff, 0xff, 0xff, 0);
			draw_sectors(all);

			draw_menu(all);
			
			SDL_RenderPresent(all->win.render);
		}
	}
	destroy(all);
}