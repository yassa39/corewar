/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ld.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:42:53 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:42:54 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>
#include "libft.h" // a supprimer une fois debug termine

int		cmd_ld(t_vm *vm, int ipr)
{
	t_vm_proc		vm_proc;
	int				ri1;

	ft_printf("cmd_ld\n");
	ft_printf("joueur %s\n", vm->player[ipr].head.prog_name);
	ft_printf("\nipr = %d\n\n", ipr);
	ft_printf("pc = %d\n", vm->process[ipr].PC);


	init_vm_proc(&vm_proc, vm, ipr, 1);


	ft_printf("num reg: %d\n", vm->process[ipr].cmd_save.params[0]);

	ri1 = read_param(&vm_proc, 0);

	ft_printf("ri1 = %d\n", ri1);

	load_param(&vm_proc, 1, ri1);

	vm->process[ipr].PC = cal_pc_add(vm->process[ipr].PC,
									vm->process[ipr].cmd_save.cmd_len);
	if (vm_proc.er)
		return (0);
	vm->process[ipr].carry = 1;
	return (1);
}
