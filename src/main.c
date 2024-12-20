#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../lib/MLX42/include/MLX42/MLX42.h"
#define WIDTH 256
#define HEIGHT 256

/* typedef struct mlx
{
	void*		window;
	void*		context;
	int32_t		width;
	int32_t		height;
	double		delta_time;
}	mlx_t; */


// Print the window width and height.
/* static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
} */

/* void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (mlx_is_key_down(param, MLX_KEY_UP))
		printf("UP");
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
		printf("DOWN");
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
		printf("LEFT");
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
		printf("RIGHT");
}

int32_t	main(void)
{

	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();

	// Create and display the image.
	mlx_image_t* img = mlx_new_image(mlx, 5, 5);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	mlx_put_pixel(img, 0, 0, 0x00FF00);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
} */

/* #define BPP sizeof(int32_t)
#include <stdlib.h>
#include <string.h>

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

int32_t	main(void)
{
    // Init mlx with a canvas size of 256x256 and the ability to resize the window.
    mlx_t* mlx = mlx_init(256, 256, "MLX42", true);
    
    if (!mlx) exit(EXIT_FAILURE);

    // Create a 128x128 image.
    mlx_image_t* img = mlx_new_image(mlx, 128, 128);

    // Set the channels of each pixel in our image to the maximum byte value of 255. 
    memset(img->pixels, 200, img->width * img->height * BPP);

    // Draw the image at coordinate (0, 0).
    mlx_image_to_window(mlx, img, 10, 0);

    // Run the main loop and terminate on quit.  
    mlx_loop(mlx);
    mlx_terminate(mlx);

    return (EXIT_SUCCESS);
} */

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(void)
{
	// Start mlx
	mlx_t* mlx = mlx_init(400, 400, "Vaquita feliz", true);
	if (!mlx)
        error();

	// Try to load the file
	mlx_texture_t* texture = mlx_load_png("imgs/vaca_l.png");
	if (!texture)
        error();

	mlx_texture_t* texture2 = mlx_load_png("imgs/arbusto_b.png");
	if (!texture)
        error();

	mlx_texture_t* texture3 = mlx_load_png("imgs/puerta_a.png");
	if (!texture)
        error();

	mlx_texture_t* texture4 = mlx_load_png("imgs/adn_b.png");
	if (!texture)
        error();

	mlx_texture_t* texture5 = mlx_load_png("imgs/fondo_b.png");
	if (!texture)
        error();

	
	// Convert texture to a displayable image
	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
	if (!img)
        error();

	// Convert texture to a displayable image arbusto
	mlx_image_t* ar = mlx_texture_to_image(mlx, texture2);
	if (!img)
        error();

	mlx_image_t* pu = mlx_texture_to_image(mlx, texture3);
	if (!img)
        error();

	mlx_image_t* adn = mlx_texture_to_image(mlx, texture4);
	if (!img)
        error();

	mlx_image_t* ff = mlx_texture_to_image(mlx, texture5);
	if (!img)
        error();

	// Display the image
	if (mlx_image_to_window(mlx, ar, 0, 0) < 0)
        error();

	if (mlx_image_to_window(mlx, ar, 100, 0) < 0)
        error();

	if (mlx_image_to_window(mlx, ar, 200, 0) < 0)
        error();

	if (mlx_image_to_window(mlx, ar, 300, 0) < 0)
        error();

	if (mlx_image_to_window(mlx, ar, 0, 100) < 0)
        error();

	if (mlx_image_to_window(mlx, ar, 0, 200) < 0)
        error();

	if (mlx_image_to_window(mlx, ar, 0, 300) < 0)
        error();

	if (mlx_image_to_window(mlx, ar, 300, 0) < 0)
        error();

	if (mlx_image_to_window(mlx, ar, 300, 100) < 0)
        error();

	if (mlx_image_to_window(mlx, ar, 300, 200) < 0)
        error();

	if (mlx_image_to_window(mlx, ar, 300, 300) < 0)
        error();

	if (mlx_image_to_window(mlx, ar, 100, 300) < 0)
        error();

	if (mlx_image_to_window(mlx, ar, 200, 300) < 0)
        error();

	if (mlx_image_to_window(mlx, pu, 100, 200) < 0)
        error();

	if (mlx_image_to_window(mlx, adn, 200, 100) < 0)
        error();

	if (mlx_image_to_window(mlx, ff, 200, 200) < 0)
        error();

	if (mlx_image_to_window(mlx, img, 100, 100) < 0)
        error();

	mlx_loop(mlx);

	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}