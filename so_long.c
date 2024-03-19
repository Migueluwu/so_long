/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:06:31 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/19 20:06:18 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*void ft_leaks (){
	system("leaks a.out");
}*/

int	main(int argc, char **argv)
{
	t_map	*t_map;

	if (argc != 2 || !check_ext(argv[1]))
		error();
	t_map = malloc(sizeof(t_map));
	t_map->map = read_and_check(argv[1], t_map);
	/*if (t_map->map)
	{
		start_game(t_map);
	}*/
	return (0);
}
