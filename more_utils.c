/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:32:59 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/19 19:35:57 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_door(t_map *t_map)
{
	int	i;
	int	j;

	i = 0;
	while (t_map->map[i])
	{
		j = 0;
		while (t_map->map[i][j])
		{
			if (t_map->map[i][j] == 'E')
			{
				t_map->door_row = i;
				t_map->door_column = j;
			}
			j++;
		}
		i++;
	}
}

void	check_door(t_map *t_map)
{
	t_map->collects--;
	if (t_map->collects == 0)
	{
		print_steps(t_map->mlx, t_map->door_row, t_map->door_column);
	}
}

void	print_steps(mlx_t *mlx, int i, int j)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./assets/steps.png");
	if (!texture)
		error();
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	if (mlx_image_to_window(mlx, img, j * IMG_WIDTH, i * IMG_WIDTH) < 0)
		error();
}
