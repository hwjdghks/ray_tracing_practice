#ifndef FTMLX_H
# define FTMLX_H

typedef struct s_ptr
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}t_ptr;

typedef struct s_image
{
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}t_img;

typedef struct s_mlx
{
	t_ptr	ptr;
	t_img	img;
}t_mlx;
#endif