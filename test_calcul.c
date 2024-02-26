/* #include <stdio.h>
#include "fractol.h"
#include <stdlib.h>

void test_mandelbrot()
{
    t_fract fract = {
		.x = 0,
		.y = 0,
		.color = 0,
		.max_iter = 50,
		.zoom = 1,
		.c = (t_complex *)malloc(sizeof(t_complex)),
		.z = (t_complex *)malloc(sizeof(t_complex)),
		.mlx = (t_mlx *)malloc(sizeof(t_mlx)),
		.colors = (t_color *)malloc(sizeof(t_color) * 256)
	};

    // Test case 1: x = 0, y = 0
    int result1 = mandelbrot(&fract, 5, 2);
    printf("Result 1: %d\n", result1);

    // Test case 2: x = 1, y = 1
    int result2 = mandelbrot(&fract, 1, 1);
    printf("Result 2: %d\n", result2);

    // Test case 3: x = -1, y = -1
    int result3 = mandelbrot(&fract, -1, -1);
    printf("Result 3: %d\n", result3);
}

int main()
{
    test_mandelbrot();
    return 0;
} */