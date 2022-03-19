/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 03:57:17 by anremiki          #+#    #+#             */
/*   Updated: 2021/12/15 16:26:48 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "/usr/include/X11/X.h"
# include "../minilibx/mlx.h"

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESC 65307

typedef struct s_player
{
	int		x;
	int		y;
	int		pos;
	int		enemy;
	int		epos;
	int		*emove;
	int		input;
	int		c;
	int		moves;
	char	*s;
}				t_player;

typedef struct s_map
{
	int	x;
	int	y;
	int	px;
	int	py;
	int	cmax;
	int	pmax;
	int	emax;
	int	end;
	int	len;
	int	size;
	int	*tab;
}				t_map;

typedef struct s_entities
{
	int	*ctab;
	int	*ptab;
	int	*etab;
	int	*otab;
	int	*ztab;
}				t_entities;

typedef struct s_img
{
	void	*mlx;
	void	*win;
	void	*floor;
	void	*wall;
	void	*roof;
	void	*light;
	void	*light1;
	void	*light2;
	void	*light3;
	void	*afk;
	void	*pleft;
	void	*pright;
	void	*pback;
	void	*pfront;
	void	*eafk;
	void	*eleft;
	void	*eright;
	void	*eback;
	void	*efront;
	void	*exit;
	void	*shiny;
	void	*shiny2;
	void	*shiny3;
	void	*shiny4;
	int		dir;
}				t_img;

typedef struct s_core
{
	t_img		*img;
	t_map		*map;
	t_player	*user;
	char		*move;
	int			anim;
	int			status;
	int			game;
	int			win;
}				t_core;

/*	used to print our move count	*/
char		*ft_itoa(int n);
void		printmove(t_img *img, int move, t_player *user, int mx);

/*	free if any problem is encountered during parsing	*/
t_core		*freecore(t_core *core);
t_core		*firstfree(t_core *core);
t_core		*secondfree(t_core *core);
t_core		*thirdfree(t_core *core);
void		*ft_error(char *str);
int			ft_err(void);

/*	IA comportement	*/
int			check_previous(t_map *m, int pos);
int			spawn(t_map *map, t_player *user, t_img *img, t_core *core);

/*	Free and destroy everything	*/
void		destroy_player(t_core *core);
void		destroy_map(t_core *core);
void		destroy_core(t_core *core);

/*	Lights animation	*/
void		anim_lights(t_img *img, int a, int b, int game);
void		game(t_core *core);

/*	Initialize our core struct and parse the files	*/
int			*check(int ac, char **av, t_map *map);
t_core		*create_core(int ac, char **av);

/*	Initialize our structs	*/
t_map		*init_map(void);
t_player	*init_player(t_map *map, int *tab, int c);
void		init_img(t_map *map, t_img *img);

/*	Mlx_put_image_to_window	*/
void		get_eimgs(t_img *img, int a, int b);
void		get_items(t_img *img, int a, int b);
int			get_imgs(t_img *img, t_map *map);
t_img		*put_game(t_map *map, t_player *user);
void		put_entities(t_img *img, t_map *map, int i, int b);

/*	My parsing funcs	*/
int			parse_ber(t_map *map, int i, int linecount, int fd);
int			get_len(int fd, char *str, t_map *map);
int			get_size(int fd, char *str);
int			*oned_map(int fd, int len, char *str);
int			ft_checkfile(char *filename);

/*	Player input funcs	*/
int			voidloop(t_core *core);
int			check_valid(int decalage, t_map *map, t_player *user, int max);
int			move_player(int decalage, t_map *map, t_player *user, t_img *img);
int			mouse_handle(int keycode, int x, int y, t_core *core);
int			key_handle(int keycode, t_core *core);
int			check_object(t_map *map);

#endif
