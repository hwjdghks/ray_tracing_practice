#include "image.h"
#include "scene.h"
#include "trace.h"

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
	double		u;
	double		v;
	t_color3	pcolor;
	t_canvas	canv;
	t_camera	cam;
	t_ray		ray;
	t_sphere	sp;

	//Scene setting;
	canv = canvas(400, 300);
	cam = camera(&canv, point3(0, 0, 0));
	sp = sphere(point3(0, 0, -5), 2);
	for (int h = canv.height - 1; h >= 0; h--) {
		for (int w = 0; w < canv.width; w++) {
			u = (double)w / (canv.width - 1);
            v = (double)h / (canv.height - 1);
			//ray from camera origin to pixel
            ray = ray_primary(&cam, u, v);
            pcolor = ray_color(&ray, &sp);
			put_pixel(mlx, w, h, color_get_trgb(0, pcolor.r, pcolor.g, pcolor.b));
		}
	}
	mlx_put_image_to_window(mlx->ptr.mlx_ptr, \
							mlx->ptr.win_ptr, \
							mlx->ptr.img_ptr, \
							150, \
							150); // top left (x, y)
}
