#include "ui.h"
#include <stdio.h>


SDL_Texture *create_background(SDL_Renderer *rend,
	t_rect f_rect, t_rect d_rect, int border_width, int back_color, int border_color)
{
	SDL_Texture		*texture;

	texture = ui_create_empty_texture(rend, (t_len){50, 40});
	ui_set_render_target(rend, texture);
	ui_fill_rect(rend, f_rect, back_color);
	ui_draw_rect(rend, d_rect, border_width, border_color);
	ui_set_render_target(rend, NULL);
	return (texture);
}

SDL_Texture *create_curved_texture(SDL_Renderer *rend, t_rect rect,
	t_curved_rect curved_rect, int border_width, int back_color, int b_color)
{
	SDL_Texture		*texture;

	texture = ui_create_empty_texture(rend, (t_len){150, 100});
	ui_set_render_target(rend, texture);
	ui_fill_curved_rect(rend, rect, border_width, back_color);
	ui_draw_curved_rect(rend, curved_rect, (int)(border_width / 10), b_color);
	ui_set_render_target(rend, NULL);
	return (texture);
}

int		main()
{
	t_win			*win;
	int      		is_pushed;
	int      		prev_x;
	int      		prev_y;
	SDL_Event		event;
	SDL_Texture		*texture;
	SDL_Texture   *btn_texture;
	SDL_Texture		*test;
	t_modal_btn *modal;
	int is_show;
	int				loop;
	t_btn 			*btn;
	t_rect			r;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
        return (1);
	win = ui_open_window("test", (t_dot){200, 200}, (t_len){1000, 1000}, UI_WIN_RESIZABLE | SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_MOUSE_FOCUS | SDL_WINDOW_MOUSE_CAPTURE);
	loop = 1;
	is_show = 0;
	//btn = ui_create_btn(ARROW, 0);
	ui_set_draw_color(win->rend, 0x666666FF);
	ui_clear_rend(win->rend);
	//btn = ui_create_btn(SLIDER, 0, "Test button", 0xffffffff);
	//ui_add_btn_pos(btn, (t_rect){150, 400, 40, 30}, ui_load_img("./ressource/image/slider.png", UI_JPG, win->rend), SLIDER);
	//ui_add_btn_pos(btn, (t_rect){150, 400, 100, 30}, NULL, H_LINE);
	//ui_add_btn_pos(btn, (t_rect){110, 410, 30, 20}, ui_create_text(ft_itoa(btn->value), "./ressource/police/arial.ttf", win->rend), TEXT);

	btn = ui_create_btn(SIMPLE, 0, "Test checkbox button", 0xffffffff);
	texture = create_curved_texture(win->rend, (t_rect){0, 0, 150, 100},
	(t_curved_rect){0, 0, 149, 99, 30}, 30, 0xff000055, 0xffffffff);
	ui_add_btn_pos(btn, (t_rect){150, 400, 130, 70}, texture, SIMPLE);
	ui_add_btn_pos(btn, (t_rect){205, 425, 30, 20}, ui_create_text("Oh !", "./ressource/police/arial.ttf", win->rend), TEXT);

	/*
	**	Copie du meme rect
	*/
	test = ui_create_empty_texture(win->rend, (t_len){50, 40});
	ui_set_render_target(win->rend, test);
	ui_fill_rect(win->rend, (t_rect){0, 0, 50, 40}, 0xffffff55);
	ui_draw_rect(win->rend, (t_rect){0, 0, 50, 40}, 10, 0xffffffff);
	ui_set_render_target(win->rend, NULL);
	//texture = ui_create_bloc_texture(win->rend, (t_len){200, 200}, 0xFFFFFFAA, 0xFFFFFFFF);

	//ui_load_slider_texture(btn, win->rend, 0, 0);
	//ui_draw_texture(win->rend, texture, (t_rect){100, 100, 50, 50});
	//ui_load_arrow_texture(btn, win->rend);
	// evt.key.keysym.sym == SDLK_ESCAPE
	modal = create_modal(ui_open_window("test-modal", (t_dot){550, 550}, (t_len){300, 400},
	UI_WIN_RESIZABLE | SDL_WINDOW_HIDDEN));
	btn_texture = create_curved_texture(modal->win->rend, (t_rect){0, 0, 40, 30},
	(t_curved_rect){0, 0, 40, 40, 30}, 30, 0xff000055, 0xffffffff);
	ui_add_btn_pos(modal->btn, (t_rect){150, 150, 80, 50}, btn_texture, SIMPLE);
	ui_add_btn_pos(modal->btn, (t_rect){150, 170, 50, 20}, ui_create_text("Oh !", "./ressource/police/arial.ttf", modal->win->rend), TEXT);

	is_pushed = 0;
	prev_x = 0;
	prev_y = 0;
	// checkbox, simple btn : create_bloc_rect..., create_bloc_curl...
	while (loop)
	{
		ui_update_event(UI_KEY_UPDATE);
		ui_set_draw_color(win->rend, 0x666666FF);
		ui_clear_rend(win->rend);
		SDL_WaitEvent(&event);
		set_click_event(event, btn, win->rend);
		if (ui_is_key_pressed(SDL_SCANCODE_Q, 0))
				loop = 0;
		r = (t_rect){0, 0, 100, 50};
		//ui_draw_texture(win->rend, dst, (t_rect){100, 0, 800, 1200});
		//ui_draw_texture(win->rend, texture, (t_rect){100, 100, 200, 200});
		ui_draw_texture(win->rend, texture, (t_rect){400, 400, 100, 70});
		ui_draw_texture(win->rend, test, (t_rect){600, 400, 100, 70});
		ui_load_simple_btn(win->rend, btn);
		//ui_load_checkbox_btn(win->rend, btn);
		if (is_btn_clicked(btn, event))
				is_show = 1;
		if (is_btn_clicked(modal->btn, event))
		{
			SDL_HideWindow(modal->win->ptr);
			SDL_RaiseWindow(win->ptr);
			is_show = 0;
		}
		if (is_show)
		{
			ui_set_draw_color(modal->win->rend, 0x666666FF);
			ui_clear_rend(modal->win->rend);
			//handle_win_event(modal->win->ptr, modal->id, event);
			ui_load_simple_btn(modal->win->rend, modal->btn);
			ui_draw_rend(modal->win->rend);
			SDL_ShowWindow(modal->win->ptr);
		}
		// si le boutton simple est clique, display la modal.
		ui_draw_rend(win->rend);
		// ui_load_simple_btn(modal->rend, modal->btn);
		// ui_draw_rend(modal->win->rend);
	}
	if (win->rend)
		SDL_DestroyRenderer(win->rend);
	SDL_DestroyWindow(win->ptr);
	SDL_Quit();
	return (0);
}
