#ifndef EVENT_H
# define EVENT_H

# include "ui_event_flag.h"
# include "ui_btn.h"

void	ui_update_event(Uint32 event_flags);
void  ui_set_event(SDL_Event event);
int		ui_is_key_pressed(Uint32 key_flags, int update);
int		ui_is_mouse_pressed(Uint32 mouse_flags, int *x, int *y);
int      is_btn_clicked(t_btn *btn, SDL_Event event);
void  set_click_event(SDL_Event event, t_btn *btn, SDL_Renderer	*rend);
void handle_win_event(SDL_Window *win, Uint32 id, SDL_Event event);
int is_in_win(SDL_Window *win, SDL_Event event);

#endif
