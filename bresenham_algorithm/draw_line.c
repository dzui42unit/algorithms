#include "mlx.h"
#include <stdlib.h>
#include <math.h>
#define WIDTH 600
#define HEIGHT 600

typedef 	struct	s_world
{
	void		*mlx;
	void		*win;
	void		*image;
}					t_world;

void	put_pixel_img(t_world *world, int x, int y, int color)
{
	char	*px;
	int		p;

	if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT))
	{
		px = mlx_get_data_addr(world->image, &p, &p, &p);
		p = WIDTH * y * 4 + x * 4;
		px[p + 0] = get_red(color);
		px[p + 1] = get_green(color);
		px[p + 2] = get_blue(color);
	}
}

void	draw_line(t_world *world, int x1, int y1, int x2, int y2)
{
	float dx = fabs(x2 - x1);
	float dy = fabs(y2 - y1);
	int sign_x = x1 < x2 ? 1 : -1;
	int sign_y = y1 < y2 ? 1 : -1;
	float error1 = dx - dy;
	while (x1 != x2 || y1 != y2)
	{
		put_pixel_img(world, x1, y1, 0x00FFFFFF);
		float error2 = error1 * 2;
		if (error2 > -(dy))
		{
			error1 -= dy;
			x1 += sign_x;
		}
		if (error2 < dx)
		{
			error1 += dx;
			y1 += sign_y;
		}
	}
}

void	img_clear(t_world *world)
{
	char	*px;
	int		p;

	px = mlx_get_data_addr(world->image, &p, &p, &p);
	ft_bzero(px, 4 * WIDTH * HEIGHT);
}

int		get_red(int color)
{
	return ((int)(((color >> 16) & 0xFF)));
}

int		get_green(int color)
{
	return ((int)(((color >> 8) & 0xFF)));
}

int		get_blue(int color)
{
	return ((int)((color) & 0xFF));
}

int		my_key_func(int key_code, void *world)
{
	if (key_code == 65307)
	{
		exit(0);
	}
	return (0);
}

int		main_activity(t_world *world)
{
	img_clear(world);
	draw_line(world, WIDTH / 2, HEIGHT / 2, WIDTH / 5, HEIGHT / 5);
	mlx_put_image_to_window(world->mlx, world->win, world->image, 0, 0);
	return (0);
}

int		main(void)
{
	t_world	world;

	world.mlx = mlx_init();
	world.win = mlx_new_window(world.mlx, WIDTH, HEIGHT, "circle");
	world.image = mlx_new_image(world.mlx, WIDTH, HEIGHT);
	mlx_hook(world.win, 2, 3, my_key_func, &world);
	mlx_loop_hook(world.mlx, &main_activity, &world);
	mlx_loop(world.mlx);
	return (0);
}
