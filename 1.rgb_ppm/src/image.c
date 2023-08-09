#include "image.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if ((0 <= x && x < WIN_WIDTH) && (0 <= y && y < WIN_HEIGHT))
	{
		dst = mlx->img.addr + (y * mlx->img.size_line \
							+ x * (mlx->img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	put_image(t_mlx *mlx)
{
	int	canvas_width;
	int	canvas_height;

	canvas_width = 256;
	canvas_height = 256;
	for (int h = 255; h > 0; h--)
		for (int w = 0; w < canvas_width; w++)
			put_pixel(mlx, w, h, color_get_trgb(0, w, h, 63));
	mlx_put_image_to_window(mlx->ptr.mlx_ptr, \
							mlx->ptr.win_ptr, \
							mlx->ptr.img_ptr, \
							150, \
							150); // top left (x, y)
}
