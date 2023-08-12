#ifndef HOOK_H
# define HOOK_H

# include <stdio.h>
# include <stdlib.h>
# include "ftmlx.h"
# include "initialize.h"

# define ON_KEYDOWN		2
# define ON_KEYUP		3
# define ON_MOUSEDOWN	4
# define ON_MOUSEUP		5
# define ON_MOUSEMOVE	6
# define ON_DESTROY		17

# define KEY_ESC 		53

int	hook_keyup(int keycode, t_mlx *mlx);
int	hook_close(t_mlx *mlx);
#endif