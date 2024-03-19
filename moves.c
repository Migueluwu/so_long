/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 22:01:31 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/19 19:25:48 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_to_up(t_map *t_map)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	if (t_map->map[t_map->actual_row - 1][t_map->actual_column] != '1')
	{
		if (t_map->map[t_map->actual_row - 1][t_map->actual_column] == 'C')
		{
			check_door(t_map);
			t_map->map[t_map->actual_row - 1][t_map->actual_column] = '0';
		}
		if (t_map->map[t_map->actual_row][t_map->actual_column] == 'E')
			print_door(t_map->mlx, t_map->actual_row, t_map->actual_column);
		else
			print_floor(t_map->mlx, t_map->actual_row, t_map->actual_column);
		print_player(t_map->mlx, t_map->actual_row - 1, t_map->actual_column);
		t_map->actual_row--;
		if (t_map->map[t_map->actual_row][t_map->actual_column] == 'E'
			&& t_map->collects == 0)
			mlx_close_window(t_map->mlx);
	}
}

void	move_to_down(t_map *t_map)
{
	if (t_map->map[t_map->actual_row + 1][t_map->actual_column] != '1')
	{
		if (t_map->map[t_map->actual_row + 1][t_map->actual_column] == 'C')
		{
			check_door(t_map);
			t_map->map[t_map->actual_row + 1][t_map->actual_column] = '0';
		}
		if (t_map->map[t_map->actual_row][t_map->actual_column] == 'E')
			print_door(t_map->mlx, t_map->actual_row, t_map->actual_column);
		else
			print_floor(t_map->mlx, t_map->actual_row, t_map->actual_column);
		print_player(t_map->mlx, t_map->actual_row + 1, t_map->actual_column);
		t_map->actual_row++;
		if (t_map->map[t_map->actual_row][t_map->actual_column] == 'E'
			&& t_map->collects == 0)
			mlx_close_window(t_map->mlx);
	}
}

void	move_to_right(t_map *t_map)
{
	if (t_map->map[t_map->actual_row][t_map->actual_column + 1] != '1')
	{
		if (t_map->map[t_map->actual_row][t_map->actual_column + 1] == 'C')
		{
			check_door(t_map);
			t_map->map[t_map->actual_row][t_map->actual_column + 1] = '0';
		}
		if (t_map->map[t_map->actual_row][t_map->actual_column] == 'E')
			print_door(t_map->mlx, t_map->actual_row, t_map->actual_column);
		else
			print_floor(t_map->mlx, t_map->actual_row, t_map->actual_column);
		print_player(t_map->mlx, t_map->actual_row, t_map->actual_column + 1);
		t_map->actual_column++;
		if (t_map->map[t_map->actual_row][t_map->actual_column] == 'E'
			&& t_map->collects == 0)
			mlx_close_window(t_map->mlx);
	}
}

void	move_to_left(t_map *t_map)
{
	if (t_map->map[t_map->actual_row][t_map->actual_column - 1] != '1')
	{
		if (t_map->map[t_map->actual_row][t_map->actual_column - 1] == 'C')
		{
			check_door(t_map);
			t_map->map[t_map->actual_row][t_map->actual_column - 1] = '0';
		}
		if (t_map->map[t_map->actual_row][t_map->actual_column] == 'E')
			print_door(t_map->mlx, t_map->actual_row, t_map->actual_column);
		else
			print_floor(t_map->mlx, t_map->actual_row, t_map->actual_column);
		print_player(t_map->mlx, t_map->actual_row, t_map->actual_column - 1);
		t_map->actual_column--;
		if (t_map->map[t_map->actual_row][t_map->actual_column] == 'E'
			&& t_map->collects == 0)
			mlx_close_window(t_map->mlx);
	}
}
