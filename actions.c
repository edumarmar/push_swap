//#include "push_swap.h"
#include <stdio.h>

void swap(int *stack)
{
	int aux;

	aux = stack[0];
	stack[0] = stack[1];
	stack[1]= aux;
}

void insert(int nbr, int *stack, int position)
{
	// length yet to be calculated
	int i = 4;

	while (i > position)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[position] = nbr;
}

void shift_left(int *stack)
{
	// change len here
	int len = 5;
	int i = 0;

	while (i < len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = 0;
}



int main()
{
	int stack[100] = {1, 2 ,3, 4};
	ra(stack);
	printf("%i,  %i,  %i, %i, %i", stack[0],stack[1],stack[2], stack[3], stack[4]);
}
