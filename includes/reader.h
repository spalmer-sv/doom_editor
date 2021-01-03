/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:58:37 by spalmer           #+#    #+#             */
/*   Updated: 2021/01/03 19:25:18 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
#define READER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include "SDL2/SDL.h"
//#include "SDL2/SDL_ttf.h"

typedef struct			s_data
{
	char				*data;
	struct s_map		*next;
}						t_data;

typedef struct			s_win
{
	SDL_Window			*win;
	SDL_Surface			*win_surface;
	SDL_Event			event;
	SDL_Renderer		*render;
	int 				w;
	int					h;
}						t_win;

typedef struct			s_mouse
{
	int 				x;
	int					y;
}						t_mouse;

typedef struct			s_setup
{
	int 				scale;
	int					grid_step; // distanse between grids vertex
}						t_setup;

typedef struct			s_vertex
{
	int 				x;
	int 				y;
	struct s_vertex		*next;
}						t_vertex;

typedef struct			s_sector
{
	t_vertex			*vertex;
	int 				x0;
	int 				y0;
	struct s_sector		*next;
	int					close; //1 if close
	int					cnt; // cnt of vertexes
}						t_sector;

typedef struct			s_level
{
	t_sector			*sectors;
	int					num;
	struct s_level		*next;
}						t_level;

typedef struct 			s_button_setup
{
	int x;
	int y;
	int size;	
}						t_button_setup;

typedef struct 			s_button
{
	struct s_button_setup	up;
	struct s_button_setup	down;
	
}						t_button;


typedef struct			s_all
{
	t_win				win;
	t_mouse				mouse;
	t_setup				setup;
	t_vertex			*grid;
	t_level				*level; // current lvl
	t_level				*zero_level;
	t_button			button;
	}						t_all;

void		init_win(t_win *win);
SDL_Window	*init_window(t_win *win);
void		error(const char *str, int fd);
void	check_event(t_all *all);
SDL_Rect	init_rect(float x, float y, int w, int h);
void	get_grid(t_all *all);
void	draw_vertex(t_vertex *vertex, t_all *all, int i);
void	check_grid(t_all *all);
int			ft_lstaddend(t_vertex **tetrs, t_vertex *new);
t_vertex	*new_vertex(int x, int y);
void	bresenham(int x0, int y0, int x1, int y1, t_all *all);
void	destroy(t_all *all);
void	draw_sectors(t_all *all);
t_sector	*new_sector(t_all *all);
void		add_sector(t_all *all, t_sector *new);
void	draw_menu(t_all *all);
void		check_viewport(t_all *all);
void	init_menu_button(t_all *all);
void		tools(t_all *all);
int			in_button(t_button_setup	button, t_all *all);
void	init_level(t_all	*all);

#endif