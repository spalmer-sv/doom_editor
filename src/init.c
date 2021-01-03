/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:08:50 by spalmer           #+#    #+#             */
/*   Updated: 2020/12/12 23:00:57 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

void	list_clean(t_vertex *list)
{
	t_vertex *temp;
	
	if (list == NULL)
		return ;
	while(list)
	{
		temp = list->next;
		free(list);
	}
	list = NULL;
}

void	destroy(t_all *all)
{
	SDL_DestroyRenderer(all->win.render);
	SDL_DestroyWindow(all->win.win);
	all->win.win = NULL;
	all->win.render = NULL;
	//list_clean(all->grid);
	//list_clean(all->vertex);
	SDL_Quit();
	exit(1);
}

SDL_Rect	init_rect(float x, float y, int w, int h)
{
	SDL_Rect	rect;

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	return (rect);
}

SDL_Window	*init_window(t_win *win)
{
	SDL_Window		*window;
	SDL_Renderer	*render;

	window = NULL;
	render = NULL;
	win->render = render;
	//if (SDL_CreateWindowAndRenderer(0, 0, (SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_BORDERLESS), &window, &win->render) != 0)
	if (SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP, &window, &win->render) != 0)
		error(SDL_GetError(), 0);
	return (window);
}

// SDL_Window	*init_window(t_win *win)
// {
// 	SDL_Window		*window;

// 	window = NULL;
// 	if (!(window = SDL_CreateWindow("map editor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WID, HEI, SDL_WINDOW_SHOWN)))
// 		error(SDL_GetError(), 0);
// 	return (window);
// }

SDL_Surface	*init_srf(t_win *win)
{
	if(!(win->win_surface = SDL_GetWindowSurface(win->win)))
		error(SDL_GetError(), 0);
	return (win->win_surface);
}

void		init_win(t_win *win)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		error(SDL_GetError(), 0);
	win->win = init_window(win);

	//TTF_Init();
	
	//SDL_GetWindowSize(win->win, &win->w, &win->h);
	// SDL_GetRendererOutputSize(win->render, &win->w, &win->h);
	// printf("%i    %i\n", win->w, win->h);
	//win->win_surface = init_srf(win);
}
