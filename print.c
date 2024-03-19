/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:05:56 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/19 19:35:38 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_floor(mlx_t *mlx, int i, int j)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./assets/floor.png");
	if (!texture)
		error();
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	if (mlx_image_to_window(mlx, img, j * IMG_WIDTH, i * IMG_WIDTH) < 0)
		error();
}

void	print_wall(mlx_t *mlx, int i, int j)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./assets/wall.png");
	if (!texture)
		error();
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	if (mlx_image_to_window(mlx, img, j * IMG_WIDTH, i * IMG_WIDTH) < 0)
		error();
}

void	print_coin(mlx_t *mlx, int i, int j)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./assets/coin.png");
	if (!texture)
		error();
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	if (mlx_image_to_window(mlx, img, j * IMG_WIDTH, i * IMG_WIDTH) < 0)
		error();
}

void	print_player(mlx_t *mlx, int i, int j)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./assets/player.png");
	if (!texture)
		error();
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	if (mlx_image_to_window(mlx, img, j * IMG_WIDTH, i * IMG_WIDTH) < 0)
		error();
}

void	print_door(mlx_t *mlx, int i, int j)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./assets/door.png");
	if (!texture)
		error();
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	if (mlx_image_to_window(mlx, img, j * IMG_WIDTH, i * IMG_WIDTH) < 0)
		error();
}
