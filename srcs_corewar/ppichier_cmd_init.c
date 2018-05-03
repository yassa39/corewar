/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ppichier_cmd_init.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 17:12:38 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 17:12:43 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"
#include "op.h"


/*static int 	ft_analyze_oct_params(t_vm *vm, t_proc *processor)
{
	int cpt;
	int left;
	short tmp;
	short tmp_dec;

	cpt = 0;
	left = 0;
	ft_bzero(vm->player->process->params_size, 3);
	while (cpt < gopt()[i].nb_arg)
	{
		tmp = vm->tab[*index];
		ft_printf("mon tmp = %x\n", vm->tab[*index]);
		tmp_dec = tmp << left;
		tmp_dec = tmp_dec >> 6;
		ft_printf("mon tmp_dec = %d\n", tmp_dec);
		if (tmp_dec == 2)
		{
			ft_printf("mon stock vaut 2\n");
			vm->player->process->params_size[cpt] = 4;
		}
		if (tmp_dec == 1)
		{
			ft_printf("mon stock vaut 2\n");
			vm->player->process->params_size[cpt] = 1;
		}
		if (tmp_dec == 3)
		{
			ft_printf("mon stock vaut 2\n");
			vm->player->process->params_size[cpt] = 2;
		}
		cpt++;
		left = left + 2;
	}
	ft_printf("cpt = %d\n", cpt);
	ft_printf("tab[0] = %d , tab[1] = %d, tab[2]= %d\n", vm->player->process->params_size[0], vm->player->process->params_size[1], vm->player->process->params_size[2]);

}*/

static int 	ft_analyze_oct_params(t_vm *vm, t_proc *processor, int op)
{
	//Cas d erreur oct params non valide : pas bon argument ou pas assez par ex)
	unsigned char 	tmp;
	unsigned char 	tmp_sec;
	int 			left;
	int				cpt;

	cpt = 0;
	left = 0;
	(void)vm;
	while (cpt < gopt()[op].nb_arg)
	{
		tmp = processor->cmd_save.codage_param;
		tmp_sec = tmp << left;
		tmp_sec = tmp_sec >> 6;
		processor->cmd_save.params[cpt] = tmp_sec;
		left += 2;
		cpt++;
	}
	int i;
	i = 0;
	while (i < 3)
	{
		ft_printf("Tab[%d] = %d", i, processor->cmd_save.params[i]);
		i++;
	}
	return (1);
}

static int ft_get_op_ppichier(t_vm *vm, t_proc *processor)
{
	int i;

	i = 0;
	while (i < OP_TAB_LENGTH)
	{
		if (gopt()[i].opcode == vm->tab[processor->PC])
			return (i);
		i++;
	}
	return (-1);
}

int 		stock_cmd(t_vm *vm, t_proc *processor)
{
	int op;

	//vm->process = malloc(sizeof(t_proc)); // test ppichier temporaire
	if ((op = ft_get_op_ppichier(vm, processor)) == -1)
	{
		ft_printf("op vaut %d\n", op);
		return (0);
	}
	if (gopt()[op].octet_param == 1)
	{
		ft_printf("op vaut %d\n", op);
		ft_printf("op correspond a %s\n", gopt()[op].name);
		processor->cmd_save.codage_param = (vm->tab[processor->PC + 1]);
		//ft_printf("oc params = %d\n", processor->cmd_save.codage_param);
		ft_analyze_oct_params(vm, processor, op);
	}
	else
		processor->cmd_save.codage_param = 0; //si pas d octet de params ou deja initialise ?
	processor->cmd_save.cmd = gopt()[op].op_fct;
	return (1);

}