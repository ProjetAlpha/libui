#include "ui.h"
#include <stdio.h>

int		main()
{
	t_win			*win;
	int      		is_pushed;
	int      		prev_x;
	int      		prev_y;
	SDL_Event		event;
	SDL_Texture		*texture;
	SDL_Texture		*src;
	SDL_Texture		*dst;
	int				loop;
	t_btn 			*btn;
	t_rect			r;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
        return (1);
	win = ui_open_window("test", (t_dot){200, 200}, (t_len){1000, 1000}, UI_WIN_RESIZABLE);
	loop = 1;
	//btn = ui_create_btn(ARROW, 0);
	ui_set_draw_color(win->rend, 0x666666FF);
	//ui_add_btn_pos(btn, (t_rect){100, 410, 30, 20}, ui_create_text(ft_itoa(btn->value), "./ressource/police/arial.ttf", win->rend));
	//ui_add_btn_pos(btn, (t_rect){150, 400, 30, 10}, ui_load_img("./ressource/image/top-arrow.png", UI_PNG, win->rend));
	//ui_add_btn_pos(btn, (t_rect){150, 420, 30, 10}, ui_load_img("./ressource/image/down-arrow.png", UI_PNG, win->rend));
	src = ui_load_img("./ressource/image/teleteub.png", UI_PNG, win->rend);
	dst = ui_load_img("./ressource/image/top-arrow.png", UI_PNG, win->rend);

	ui_blit_texture(win->rend, src, dst, (t_frect){0.5, 0.4, 0.3, 0.5});
	btn = ui_create_btn(SLIDER, 0, "Test button", 0xffffffff);
	//ui_add_btn_pos(btn, (t_rect){150, 400, 40, 30}, ui_load_img("./ressource/image/slider.png", UI_JPG, win->rend), SLIDER);
	//ui_add_btn_pos(btn, (t_rect){150, 400, 100, 30}, NULL, H_LINE);
	//ui_add_btn_pos(btn, (t_rect){110, 410, 30, 20}, ui_create_text(ft_itoa(btn->value), "./ressource/police/arial.ttf", win->rend), TEXT);

	btn = ui_create_btn(CHECKBOX, 0, "Test checkbox button", 0xffffffff);
	ui_add_btn_pos(btn, (t_rect){150, 400, 40, 30}, ui_create_bloc_texture(win->rend, (t_len){40, 40}, 0xFFFFFFAA, 0xFFFFFFFF), CHECKBOX);
	ui_add_btn_pos(btn, (t_rect){110, 410, 30, 20}, ui_create_text("check", "./ressource/police/arial.ttf", win->rend), TEXT);

	texture = ui_create_bloc_texture(win->rend, (t_len){200, 200}, 0xFFFFFFAA, 0xFFFFFFFF);

	ui_load_slider_texture(btn, win->rend, 0, 0);
	//ui_draw_texture(win->rend, texture, (t_rect){100, 100, 50, 50});
	//ui_load_arrow_texture(btn, win->rend);
	// evt.key.keysym.sym == SDLK_ESCAPE
	ui_draw_rend(win->rend);
	is_pushed = 0;
	prev_x = 0;
	prev_y = 0;
	// checkbox, simple btn : create_bloc_rect..., create_bloc_curl...
	while (loop)
	{
		ui_update_event(UI_KEY_UPDATE);
		ui_set_draw_color(win->rend, 0x666666FF);
		SDL_WaitEvent(&event);
		set_click_event(event, btn, win->rend);
		if (ui_is_key_pressed(SDL_SCANCODE_Q, 0))
				loop = 0;
		r = (t_rect){0, 0, 100, 50};
		ui_draw_texture(win->rend, dst, (t_rect){100, 0, 800, 1200});
		ui_draw_texture(win->rend, texture, (t_rect){100, 100, 200, 200});
		ui_load_checkbox_btn(win->rend, btn);
		ui_draw_rend(win->rend);
	}
	if (win->rend)
		SDL_DestroyRenderer(win->rend);
	SDL_DestroyWindow(win->ptr);
	SDL_Quit();
	return (0);
}
