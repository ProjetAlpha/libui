#include "SDL.h"

int is_in_win(SDL_Window *win, SDL_Event event)
{
    Uint32 win_event;

    win_event = event.window.event;
    if (event.type == SDL_WINDOWEVENT && SDL_GetWindowID(win) == event.window.windowID &&
    (win_event == SDL_WINDOWEVENT_FOCUS_GAINED || win_event == SDL_WINDOWEVENT_ENTER))
      return (1);
    return (0);
}

void handle_win_event(SDL_Window *win, Uint32 id, SDL_Event event)
{
  Uint32 win_id;
  Uint32 win_event;

  id = 0;
  win_id = SDL_GetWindowID(win);
    if ((event.type == SDL_QUIT || event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) && win_id == event.window.windowID)
    {
      SDL_HideWindow(win);
      return ;
    }
    if (event.type == SDL_WINDOWEVENT)
    {
      win_id = SDL_GetWindowID(win);
      printf("id %d | my id : %d\n", event.window.windowID, win_id);
      if (event.window.windowID == win_id)
      {
        win_event = event.window.event;
        if (win_event == SDL_WINDOWEVENT_CLOSE)
          SDL_HideWindow(win);
        //if (win_event == SDL_WINDOW_MINIMIZED)
          //SDL_MinimizeWindow(win);
        //if (win_event == SDL_WINDOW_MAXIMIZED)
          //SDL_MaximizeWindow(win);
      }
    }

}
