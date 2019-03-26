/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_modal.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 15:28:53 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 15:29:22 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "SDL.h"
#include "ui_window.h"
#include "ui_error.h"
#include "ui_btn.h"
#include "ui_modal.h"


t_modal_btn *create_modal(t_win *win)
{
  t_modal_btn *modal;
  int i;

  i = 0;
  if (!win)
    return (ui_null_error("Invalid window."));
  modal = malloc(sizeof(t_modal_btn));
  modal->btn = ui_create_btn(SIMPLE, 0, "Modal test", 0xffffffff); // (int type, int action, char *name, int color)
  modal->win = win;
  modal->id = SDL_GetWindowID(win->ptr);
  return (modal);
}
