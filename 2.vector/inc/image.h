#ifndef IMAGE_H
# define IMAGE_H

# include "mlx.h"
# include "ftmlx.h"
# include "utils.h"
# include "color.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color);
void	put_image(t_mlx *mlx);
#endif