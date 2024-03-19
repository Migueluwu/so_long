/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:43:43 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/19 20:00:57 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_the_texture(mlx_t *mlx, char c, int i, int j)
{
	if (c == 'P')
	{
		print_floor(mlx, i, j);
		print_player(mlx, i, j);
	}
	if (c == 'C')
	{
		print_floor(mlx, i, j);
		print_coin(mlx, i, j);
	}
	if (c == '1')
		print_wall(mlx, i, j);
	if (c == '0')
		print_floor(mlx, i, j);
	if (c == 'E')
		print_door(mlx, i, j);
}

void	add_textures(mlx_t *mlx, t_map *t_map)
{
	int				i;
	int				j;

	i = 0;
	while (i < t_map->rows)
	{
		j = 0;
		while (j < t_map->columns)
		{
			add_the_texture(mlx, t_map->map[i][j], i, j);
			j++;
		}
		i++;
	}
}

int	start_game(t_map *t_map)
{
	//if (!t_map)
	//	error();
	/*t_map->mlx = mlx_init(t_map->columns * IMG_WIDTH,
			t_map->rows * IMG_HEIGHT, "SO_LONG", true);*/
	//if (!t_map->mlx)
	//	error();
	put_spawn(t_map);
	put_door(t_map);
	t_map->collects = 0;
	count_coins(t_map);
	//add_textures (t_map->mlx, t_map);
	//mlx_key_hook(t_map->mlx, &my_keyhook, t_map);
	//mlx_loop(t_map->mlx);
	return (EXIT_SUCCESS);
}
