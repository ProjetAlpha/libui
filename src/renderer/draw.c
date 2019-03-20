#include "SDL.h"
#include "ui_error.h"
#include "ui_frame.h"
#include "ui_draw.h"

void	ui_draw_point(SDL_Renderer *rend, int x, int y, t_frame *frame)
{
	if (!frame)
	{
		if (SDL_RenderDrawPoint(rend, x, y) < 0)
			ui_error(SDL_GetError());
	}
	else
	{
		if (x >= frame->r.x && x <= frame->r.x + (int)frame->r.w
			&& y >= frame->r.y && x <= frame->r.y + (int)frame->r.h)
		{
			if (SDL_RenderDrawPoint(rend, x + frame->r.x, y + frame->r.y) < 0)
				ui_error(SDL_GetError());
		}
	}
}

void	ui_draw_texture(SDL_Renderer *rend, SDL_Texture *texture, t_rect dst)
{
	if (SDL_RenderCopy(rend, texture, NULL, (SDL_Rect*)&dst) < 0)
		perror(SDL_GetError());
}
