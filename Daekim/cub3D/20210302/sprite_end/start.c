/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:23:44 by daekim            #+#    #+#             */
/*   Updated: 2021/03/02 00:04:09 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			main_loop(t_info *p)
{

	calc_fl(p);
	calc_wa(p);
	calc_sp(p);
	draw(p);
	k_press(p);

	return (0);
}

void		info(t_info *p)
{
	p->posX = 22;
	p->posY = 11.5;
	p->dirX = -1;
	p->dirY = 0.0;
	p->planeX = 0.0;
	p->planeY = 0.66;
	p->move = 0.05;
	p->rot = 0.025;

//	color_wall(p);
	tex_wall(p);
//	in_sprite(p);
}

int			main(void)
{
	t_info p;

	p.mlx_p = mlx_init();
	info(&p);
	p.win_p = mlx_new_window(p.mlx_p, win_w, win_h, "second cub3d");
	p.img.img_p = mlx_new_image(p.mlx_p, win_w, win_h);
	p.img.data = (int *)mlx_get_data_addr(p.img.img_p, &p.img.bpp,
			&p.img.size_l, &p.img.endian);
	mlx_hook(p.win_p, X_KEY_PRESS, KeyPressMask, &ft_keypress, &p);
//	mlx_hook(p.win_p, X_KEY_RELEASE, KeyReleaseMask, &k_release, &p);
//	k_release(&p);
	mlx_loop_hook(p.mlx_p, &main_loop, &p);
//	mlx_key_hook(p.win_p, &k_press, &p);
//	mlx_hook(p.win_p, X_KEY_PRESS, KeyPressMask, &k_press, &p);
//	mlx_hook(p.win_p, X_KEY_RELEASE, KeyReleaseMask, &k_release, &p);
//	mlx_hook(p.win_p, X_KEY_EXIT, 1, &close, &p);
	mlx_loop(p.mlx_p);
}
