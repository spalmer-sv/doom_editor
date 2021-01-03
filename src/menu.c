/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:41:40 by spalmer           #+#    #+#             */
/*   Updated: 2020/12/12 23:12:20 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

// void	draw_text(t_all *all)
// {
// 	TTF_Font* sans;
// 	SDL_Rect Message_rect;
// 	SDL_Color White = {255, 255, 255};
// 	SDL_Surface* surfacemessage;
// 	SDL_Texture* message;
	
// 	sans = TTF_OpenFont("19888.ttf", 24);
// 	Message_rect = init_rect(100, 100, 500, 100);
// 	surfacemessage = TTF_RenderText_Solid(sans, "LEVEL", White);
// 	message = SDL_CreateTextureFromSurface(all->win.render, surfacemessage);

// 	SDL_RenderCopy(all->win.render, message, NULL, &Message_rect);
// }

void	draw_menu(t_all *all)
{
	SDL_Rect menu;
	SDL_Rect up;
	SDL_Rect down;

	up = init_rect(all->win.w / 8, 200, 50, 50);
	down = init_rect(all->win.w / 8, 400, 50, 50);
	menu = init_rect(0, 0, all->win.w / 4, all->win.h);
	SDL_SetRenderDrawColor(all->win.render, 0x63, 0x63, 0x63, 0);
	SDL_RenderFillRect(all->win.render, &menu);
	SDL_SetRenderDrawColor(all->win.render, 0xff, 0x00, 0x00, 0);
	SDL_RenderFillRect(all->win.render, &up);
	SDL_RenderFillRect(all->win.render, &down);
//	draw_text(all);
	
}
