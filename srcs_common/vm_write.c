
#include "corewar.h"

void	vm_write_1(t_vm *vm, unsigned int PC, unsigned char data)
{
	vm->tab[cal_PC_add(PC, 0)] = data;
}

void	vm_write_2(t_vm *vm, unsigned int PC, unsigned short data)
{
	int a;
	unsigned char *ptr;

	a = 0;
	ptr = (unsigned char*)&data;
	swap_2(&data);
	while (a < 2)
	{
		vm->tab[cal_PC_add(PC, a)] = ptr[a];
		a++;
	}
}

void	vm_write_4(t_vm *vm, unsigned int PC, unsigned int data)
{
	int a;
	unsigned char *ptr;

	a = 0;
	ptr = (unsigned char*)&data;
	swap_4(&data);
	while (a < 4)
	{
		vm->tab[cal_PC_add(PC, a)] = ptr[a];
		a++;
	}
}