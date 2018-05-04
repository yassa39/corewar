/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sub.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:43:48 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:43:51 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include <corewar.h>

// TODO carry
int		cmd_sub(t_vm *vm, int ipr)
{
	int		er;
	int		ri1;
	int		ri2;
	int		ri3;

	er = 0;
	(void)vm;
	vm->process[ipr].PC = cal_PC_add(vm->process[ipr].PC,
									 vm->process[ipr].cmd_save.cmd_len);
	ri1 = get_i_reg(vm->process + ipr, 0, &er);
	ri2 = get_i_reg(vm->process + ipr, 1, &er);
	ri3 = get_i_reg(vm->process + ipr, 2, &er);
	if (er)
		return (0);
	vm->process[ipr].reg[ri3] = vm->process[ipr].reg[ri1] - vm->process[ipr].reg[ri2]; // order ?
	return (1);
}
