#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_vec3 t_vec3;
typedef struct s_vec3 t_point3;

struct s_vec3
{
    double x;
    double y;
    double z;
};

typedef struct s_color3 t_color3;

struct s_color3
{
	int	r;
	int	g;
	int	b;
};

t_vec3      vec3(double x, double y, double z);
t_point3    point3(double x, double y, double z);
t_color3    color3(double r, double g, double b);
void        vset(t_vec3 *vec, double x, double y, double z);
double      vlength2(t_vec3 vec);
double      vlength(t_vec3 vec);
t_vec3      vplus(t_vec3 vec, t_vec3 vec2);
t_vec3      vplus_(t_vec3 vec, double x, double y, double z);
t_vec3      vminus(t_vec3 vec, t_vec3 vec2);
t_vec3      vminus_(t_vec3 vec, double x, double y, double z);
t_vec3      vmult(t_vec3 vec, double t);
t_vec3      vmult_(t_vec3 vec, t_vec3 vec2);
t_vec3      vdivide(t_vec3 vec, double t);
double      vdot(t_vec3 vec, t_vec3 vec2);
t_vec3      vcross(t_vec3 vec, t_vec3 vec2);
t_vec3      vunit(t_vec3 vec);
t_vec3      vmin(t_vec3 vec1, t_vec3 vec2);
#endif