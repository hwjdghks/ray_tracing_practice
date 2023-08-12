#include "hook.h"

int	hook_close(t_mlx *mlx)
{
	printf("Window closed\n");
	exit_program(mlx);
	return (0);
}

int	hook_keyup(int keycode, t_mlx *mlx)
{
	printf("keycode: %d\n", keycode);
	if (keycode == KEY_ESC)
	{
		printf("press ESC\n");
		exit_program(mlx);
	}
	return (0);
}
