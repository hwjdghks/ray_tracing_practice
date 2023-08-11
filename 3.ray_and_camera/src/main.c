#include "initialize.h"
#include "image.h"

int	main(void)
{
	t_mlx	mlx;

	if (init_all(&mlx) == NULL)
		exit_program(&mlx);
	put_image(&mlx);
	mlx_loop(mlx.ptr.mlx_ptr);
}
