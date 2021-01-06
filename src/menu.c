/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:41:40 by spalmer           #+#    #+#             */
/*   Updated: 2021/01/06 18:54:09 by spalmer          ###   ########.fr       */
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

int			in_button(t_button_setup	button, t_all *all)
{
	if (all->mouse.x >= button.x && all->mouse.x <= (button.x + button.size)
	&& all->mouse.y >= button.y && all->mouse.y <= (button.y + button.size))
		return (1);
	return (0);
}



void		check_viewport(t_all *all)
{
	if (all->mouse.x <= all->win.w / 6)
		tools(all);
	else if (all->button.edit_vertex.press == 0 && all->button.remove_vertex.press == 0)
		check_grid(all);
	else if (all->button.edit_vertex.press == 1)
		mode_edit_vertex(all);
	else if (all->button.remove_vertex.press == 1)
		mode_remove_vertex(all);
}

void	init_menu_button(t_all *all)
{
	all->button.up.x = 100; //UP lvl
	all->button.up.y = 100;
	all->button.up.size = 20;
	
	all->button.down.x = 100; // down lvl
	all->button.down.y = 150;
	all->button.down.size = 20;
	
	all->button.edit_vertex.x = 100; 
	all->button.edit_vertex.y = 250;
	all->button.edit_vertex.size = 20;
	all->button.edit_vertex.press = 0;

	all->button.remove_vertex.x = 100; 
	all->button.remove_vertex.y = 300;
	all->button.remove_vertex.size = 20;
	all->button.remove_vertex.press = 0;
}

void	draw_menu(t_all *all)
{
	SDL_Rect menu;
	SDL_Rect up;
	SDL_Rect down;
	SDL_Rect edit_vertex;
	SDL_Rect remove_vertex;
	
	//printf("win_w = %i, up_x =%i, up_y =%i, up_size =%i\n", all->win.w, all->button.up.x, all->button.up.y, all->button.up.size);
	up = init_rect(all->button.up.x, all->button.up.y, all->button.up.size, all->button.up.size);
	down = init_rect(all->button.down.x, all->button.down.y, all->button.down.size, all->button.down.size);
	menu = init_rect(0, 0, all->win.w / 6, all->win.h);
	edit_vertex = init_rect(all->button.edit_vertex.x, all->button.edit_vertex.y, all->button.edit_vertex.size, all->button.edit_vertex.size);
	remove_vertex = init_rect(all->button.remove_vertex.x, all->button.remove_vertex.y, all->button.remove_vertex.size, all->button.remove_vertex.size);
	SDL_SetRenderDrawColor(all->win.render, 0x63, 0x63, 0x63, 0);
	SDL_RenderFillRect(all->win.render, &menu);
	SDL_SetRenderDrawColor(all->win.render, 0xff, 0x00, 0x00, 0);
	SDL_RenderFillRect(all->win.render, &up);
	SDL_RenderFillRect(all->win.render, &down);
	SDL_RenderFillRect(all->win.render, &edit_vertex);
	SDL_RenderFillRect(all->win.render, &remove_vertex);
//	draw_text(all);
	
}
