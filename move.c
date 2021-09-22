/////////////////////////////////

void ra(int *stack_a)
{
	int len = 4;
	insert(stack_a[0], stack_a, len);
	shift_left(stack_a);
}

void rb(int *stack_b)
{
	int len = 4;
	insert(stack_b[0], stack_b, len);
	shift_left(stack_b);
}

void rr(int *stack_a, int stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

//////////////////////////////////

void pa(int *stack_a, int *stack_b)
{
	insert(stack_b[0], stack_a, 0);
	shift_left(stack_b);
}

void pb(int *stack_a, int *stack_b)
{
	insert(stack_a[0], stack_b, 0);
	shift_left(stack_a);
}

/////////////////////////////////////////////
void sa(int *stack_a)
{
	swap(stack_a);
}

void sb(int *stack_b)
{
	swap(stack_b);
}

void ss(int *stack_a, int *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
/////////////////////////////////////////////////

void rra(int *stack_a)
{
	insert(stack_a[len], stack_a, 0);
	stack_a[len] = 0;
}

void rrb(int *stack_a)
{
	insert(stack_a[len], stack_a, 0);
	stack_a[len] = 0;
}

void rrr(int *stack_a, int *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

