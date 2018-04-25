/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   op.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <cepalle@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/09 16:56:27 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 11:49:08 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#ifndef COREWAR_H
# define COREWAR_H

#include <stdlib.h>
#include <unistd.h>

typedef	struct 		s_player
{
	char			*name;
	unsigned int	last_live;
	unsigned int	live;
	char			comment[COMMENT_LENGTH + 1];
	unsigned int	prog_size;

}					t_player;

typedef	struct 		s_vm
{
	unsigned char 	tab[MEM_SIZE];
	t_player 		*player;
	unsigned int 	nb_process;
	unsigned int 	cycle;
}					t_vm;

#endif