#include "initialize.h"

void	exit_program(t_mlx *mlx)
{	
	if (mlx->ptr.img_ptr != NULL)
		mlx_destroy_image(mlx->ptr.mlx_ptr, mlx->ptr.img_ptr);
	if (mlx->ptr.win_ptr != NULL)
		mlx_destroy_window(mlx->ptr.mlx_ptr, mlx->ptr.win_ptr);
	exit(0);
}

static void	init_ftmlx(t_mlx *mlx)
{
	mlx->ptr.mlx_ptr = NULL;
	mlx->ptr.win_ptr = NULL;
	mlx->ptr.img_ptr = NULL;
	mlx->img.addr = NULL;
	mlx->img.bits_per_pixel = 0;
	mlx->img.size_line = 0;
	mlx->img.endian = 0;
}

static void	*set_ptr(t_mlx *mlx)
{
	mlx->ptr.mlx_ptr = mlx_init();
	if (mlx->ptr.mlx_ptr == NULL)
		return (NULL);
	mlx->ptr.win_ptr = mlx_new_window(mlx->ptr.mlx_ptr, \
									WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (mlx->ptr.win_ptr == NULL)
		return (NULL);
	mlx->ptr.img_ptr = mlx_new_image(mlx->ptr.mlx_ptr, \
									WIN_WIDTH, WIN_HEIGHT);
	if (mlx->ptr.img_ptr == NULL)
		return (NULL);
	mlx->img.addr = mlx_get_data_addr(mlx->ptr.img_ptr, \
									&mlx->img.bits_per_pixel, \
									&mlx->img.size_line, \
									&mlx->img.endian);
	return (mlx);
}

static void	set_hook(t_mlx *mlx)
{
	mlx_hook(mlx->ptr.win_ptr, ON_KEYUP, 0, hook_keyup, mlx);
	mlx_hook(mlx->ptr.win_ptr, ON_DESTROY, 0, hook_close, mlx);
}

void	*init_all(t_mlx *mlx)
{
	init_ftmlx(mlx);
	if (set_ptr(mlx) == NULL)
		return (NULL);
	set_hook(mlx);
	return (mlx);
}
