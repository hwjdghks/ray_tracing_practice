#include "trace.h"

//ray 생성자(정규화 된 ray)
t_ray	ray(t_point3 orig, t_vec3 dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = vunit(dir);
	return (ray);
}

//ray origin point 부터 방향벡터 ray dir * t 만큼 떨어진 점.
t_point3	ray_at(t_ray *ray, double t)
{
	t_point3	at;

	at = vplus(ray->orig, vmult(ray->dir, t));
	return (at);
}

//primary_ray 생성자
t_ray	ray_primary(t_camera *cam, double u, double v)
{
	t_ray	ray;

	ray.orig = cam->orig;
	// left_bottom + u * horizontal + v * vertical - origin 의 단위 벡터.
	ray.dir = vunit(vminus( \
							vplus( \
								vplus(cam->left_bottom, \
										vmult(cam->horizontal, u)), \
								vmult(cam->vertical, v)), \
					cam->orig));
	return (ray);
}

//광선이 최종적으로 얻게된 픽셀의 색상 값을 리턴.
t_color3	ray_color(t_ray *r)
{
	double	t;
	t_color3 color1, color2;

	t = 0.5 * (r->dir.y + 1.0);
	color1.r = 255;
	color1.g = 255;
	color1.b = 255;

	color2.r = 127;
	color2.g = 179;
	color2.b = 255;
	// (1-t) * 흰색 + t * 하늘색
	/* 
	*  EDIT: t * 흰색 + (1-t) * 하늘색 -> 예제와 출력 동일하게 변경
	*  또는 primary ray, left bottom 계산, right hand 좌표계 등 반대로 적용될 가능성 존대
	*  만약 색 조합 비율 수식이 맞다면 다른 파트의 예제 수식의 검토 필요
	*/	
	return (cplus(cmult(color1, t), \
					cmult(color2, 1.0 - t)));
}
