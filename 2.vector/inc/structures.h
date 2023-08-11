#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_vec3	t_vec3;
typedef struct s_vec3	t_point3;
typedef struct s_color3	t_color3;

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

struct s_color3
{
	int	r;
	int	g;
	int	b;
};
#endif