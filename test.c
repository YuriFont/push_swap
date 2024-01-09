#include "push_swap.h"
#include <stdio.h>
int	main(void)
{
	t_snode	a;
	t_snode	b;
	t_snode c;
	t_snode	*stack_a;

	stack_a = &a;
	b.data = 4;
	a.data = 5;
	c.data = 6;
	a.next = &b;
	a.prev = NULL;
	b.prev = &a;
	b.next = &c;
	c.next = NULL;
	printf("list01: %d", stack_a->data);
	printf(" %d", stack_a->next->data);
	printf(" %d\n", stack_a->next->next->data);
	sa(&stack_a);
	printf("list02: %d", stack_a->data);
	printf(" %d", stack_a->next->data);
	printf(" %d\n", stack_a->next->next->data);
}
