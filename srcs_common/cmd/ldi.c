/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ldi.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:42:59 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:43:00 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>
#include "libft.h" //a supprimer une fois debug termine

int		cmd_ldi(t_vm *vm, int ipr)
{
	t_vm_proc		vm_proc;
	int				ri1;
	int				ri2;
	int				res;

	ft_printf("cmd_ldi\n");
	init_vm_proc(&vm_proc, vm, ipr, 0);
	ri1 = read_param(&vm_proc, 0);
	ri2 = read_param(&vm_proc, 1);
	res = vm_read_4(vm, cal_pc_add(vm->process[ipr].PC, (ri1 + ri2) % IDX_MOD));
	load_param(&vm_proc, 2, res);
	vm->process[ipr].PC = cal_pc_add(vm->process[ipr].PC,
									vm->process[ipr].cmd_save.cmd_len);
	if (vm_proc.er)
		return (0);
	vm->process[ipr].carry = 1;
	return (1);
}
