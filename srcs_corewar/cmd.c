

#include "../includes/corewar.h"
//#include "../includes/op.h"
#include "../libft/includes/libft.h"


void 	ft_live(t_vm *vm, int num_player, int num_process)
{
//	penser a ajouter le numero du process?
//	process mis en place pour gerer une liste de fonction
	vm->player[num_player].live = vm->player[num_player].live + 1;
	vm->player[num_player].last_live = vm->player[num_player].last_live + 1;
}

void 	ft_ld(t_vm *vm, int num_player, int num_process)
{
	int *tab;

	tab = vm->player[num_player].process[num_process].params_size;
//	ld prend 2 parametre
//	tab[0] correspond a un registre code sur 1 octet = on recupere direcement la ref du registre
//	tab[2] correspond a la taille du prochain argument code sur 1 ou 2 octet
	ft_memcpy(&vm->player[num_player].process[num_process].reg[tab[0]],
			  &vm->tab[vm->player[num_player].process[num_process].PC], (size_t)tab[1]);
//			  tab[2] % IDX_MOD;
//	est ce qu'il faut faire un swap[2] ou swap[4]?
//	changement de carry? passage de 1 a 0 ou  1 a 1
//	vm->player[num_player].process[num_process].carry = 1;
}




void 	ft_st(t_vm *vm, int num_player, int num_process)
{
	int addr;
	int *tab;

	tab = vm->player[num_player].process[num_process].params_size;

	addr = vm->tab[vm->[num_player].process[num_process]->PC] + (tab[1] % IDX_MOD);
	ft_memcpy(vm->tab + addr, &vm->[num_player].process[num_process].reg[tab[0]], REG_CONTENT_SIZE);
//	est ce qu'il faut faire un swap[2] ou swap[4]?
// 	changement de carry? passage de 1 a 0 ou  1 a 1
//	vm->player[num_player].process[num_process].carry = 1;
}






int 	ft_add(t_vm *vm, int num_player, int num_process)
{
//	% 4294967295
//	pas de message d'erreur en cas de depassement
	return (player.process->reg[num_reg1] + player.process->reg[num_reg2]);
}

int 	ft_sub(t_vm *vm, int num_player, int num_process)
{
//	penser a modifier carry si erreur ou pas
//	erreur potentiel : depassement int max
	return (player.process->reg[num_reg1] - player.process->reg[num_reg2]);
}

int 	ft_and(t_vm *vm, int num_player, int num_process)
{
	return (param_1 & param_2);
}

int 	ft_or(t_vm *vm, int num_player, int num_process)
{
	return (param_1 | param_2);
}

int 	ft_xor(t_vm *vm, int num_player, int num_process)
{
	return (param_1 ^ param_2);
}

int 	ft_ldi(t_vm *vm, int num_player, int num_process)
{
//	mettre % 512 ?
	return (vm->tab[param_1 + param_2]);
}

int		ft_sti(t_vm *vm, int num_player, int num_process)
{
	int addr;

	addr = param_1 + param_2;
	ft_memcpy(vm->tab + addr, &reg, REG_CONTENT_SIZE);
}


int 	ft_lld(t_vm *vm, int num_player, int num_process)
{
//	ajouter % 4096? ou autre limite
	return (nbr);
}

int 	ft_lldi(t_vm *vm, int num_player, int num_process)
{
//	ldi sans modulo
	return (vm->tab[param_1 + param_2]);
}

void 	ft_aff(t_vm *vm, int num_player, int num_process)
{
	ft_putchar(vm->tab[index]);
}


void	ft_lfork(t_vm *vm, int num_player, int num_process)
{
	return;
}

void	ft_fork(t_vm *vm, int num_player, int num_process)
{
	return;
}

void 	ft_zjmp(t_vm *vm, int num_player, int num_process)
{
	ft_vm_run(vm,);
	player[num_player].process[num_process].process = index;
}
