#ifndef UI_MODAL_H
# define UI_MODAL_H

# define MAX_BTN_MODAL 30

enum s_modal_type
{
  MODAL = 1,
  MODAL_OK = 2,
  MODAL_CANCEL = 3,
  MODAL_TEXT = 4
};


typedef struct  s_modal_btn
{
  t_btn *btn;
  t_win *win;
  Uint32  id;
}               t_modal_btn;

t_modal_btn *create_modal(t_win *win);

#endif
