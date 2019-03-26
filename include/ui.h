#ifndef UI_H
# define UI_H

# include "SDL.h"
# include "ui_error.h"
# include "ui_window.h"
# include "ui_renderer.h"
# include "ui_event.h"
# include "ui_struct_2d.h"
# include "ui_shape.h"
# include "ui_frame.h"
# include "ui_texture.h"
# include "ui_btn.h"
# include "ui_image.h"
# include "ui_draw.h"
# include "ui_modal.h"

int		ui_init(Uint32 sdl_flags, Uint32 image_flags);

#endif
