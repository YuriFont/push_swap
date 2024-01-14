#include "push_swap.h"
#include <stdio.h>
int	main(void)
{
	/* Stack a =  5 4 6 */
	t_snode	a0;
	t_snode	a1;
	t_snode a2;
	t_snode	*stack_a;
	stack_a = &a0;
	a1.data = 4;
	a0.data = 5;
	a2.data = 6;
	a0.next = &a1;
	a0.prev = NULL;
	a1.prev = &a0;
	a1.next = &a2;
	a2.next = NULL;

	/*Stack b = 2 1 3 */
	t_snode b0;
	t_snode b1;
	t_snode b2;
	t_snode *stack_b;
	stack_b = &b0;
	b0.data = 2;
	b0.next = &b1;
	b0.prev = NULL;
	b1.data = 1;
	b1.next = &b2;
	b1.prev = &b0;
	b2.data = 3;
	b2.next = NULL;
	b2.prev = &b1;

	/* Teste - sa */
	printf("Teste - sa\n\n");
	printf("Stack_a: %d", stack_a->data);
	printf(" %d", stack_a->next->data);
	printf(" %d\n", stack_a->next->next->data);
	sa(&stack_a);
	printf("Stack_a: %d", stack_a->data);
	printf(" %d", stack_a->next->data);
	printf(" %d\n\n\n", stack_a->next->next->data);

	/* Teste - sb */
	printf("Teste - sb\n\n");
	printf("Stack_b: %d", stack_b->data);
	printf(" %d", stack_b->next->data);
	printf(" %d\n", stack_b->next->next->data);
	sb(&stack_b);
	printf("Stack_b: %d", stack_b->data);
	printf(" %d", stack_b->next->data);
	printf(" %d\n\n\n", stack_b->next->next->data);
	
	/* Teste - ss */
	printf("Teste - ss\n\n");
	printf("Stack_a: %d", stack_a->data);
	printf(" %d", stack_a->next->data);
	printf(" %d\n", stack_a->next->next->data);
	printf("Stack_b: %d", stack_b->data);
	printf(" %d", stack_b->next->data);
	printf(" %d\n", stack_b->next->next->data);
	ss(&stack_a, &stack_b);
	printf("Stack_a: %d", stack_a->data);
	printf(" %d", stack_a->next->data);
	printf(" %d\n", stack_a->next->next->data);
	printf("Stack_b: %d", stack_b->data);
	printf(" %d", stack_b->next->data);
	printf(" %d\n\n\n", stack_b->next->next->data);

	/* Teste - pa */
	printf("Teste - pa\n\n");
	printf("Stack_a: %d", stack_a->data);
	printf(" %d", stack_a->next->data);
	printf(" %d\n", stack_a->next->next->data);
	printf("Stack_b: %d", stack_b->data);
	printf(" %d", stack_b->next->data);
	printf(" %d\n", stack_b->next->next->data);
	pa(&stack_a, &stack_b);
	printf("Stack_a: %d", stack_a->data);
	printf(" %d", stack_a->next->data);
	printf(" %d", stack_a->next->next->data);
	printf(" %d\n", stack_a->next->next->next->data);
	printf("Stack_b: %d", stack_b->data);
	printf(" %d\n\n\n", stack_b->next->data);

	/* Teste - pb */
	printf("Teste - pb\n\n");
	printf("Stack_a: %d", stack_a->data);
	printf(" %d", stack_a->next->data);
	printf(" %d", stack_a->next->next->data);
	printf(" %d\n", stack_a->next->next->next->data);
	printf("Stack_b: %d", stack_b->data);
	printf(" %d\n", stack_b->next->data);
	pb(&stack_b, &stack_a);
	printf("Stack_a: %d", stack_a->data);
	printf(" %d", stack_a->next->data);
	printf(" %d\n", stack_a->next->next->data);
	printf("Stack_b: %d", stack_b->data);
	printf(" %d", stack_b->next->data);
	printf(" %d\n\n\n", stack_b->next->next->data);

	/* Teste - ra */
	printf("Teste - ra\n\n");
	printf("Stack_a: %d %d %d\n", stack_a->data, stack_a->next->data, stack_a->next->next->data);
	ra(&stack_a);
	printf("Stack_a: %d %d %d\n\n\n", stack_a->data, stack_a->next->data, stack_a->next->next->data);

	/* Teste - rb */
	printf("Teste - rb\n\n");
	printf("Stack_b: %d %d %d\n", stack_b->data, stack_b->next->data, stack_b->next->next->data);
	rb(&stack_b);
	printf("Stack_b: %d %d %d\n\n\n", stack_b->data, stack_b->next->data, stack_b->next->next->data);

	/* Teste - rr */
	printf("Teste - rr\n\n");
	printf("Stack_a: %d %d %d\n", stack_a->data, stack_a->next->data, stack_a->next->next->data);
	printf("Stack_b: %d %d %d\n", stack_b->data, stack_b->next->data, stack_b->next->next->data);
	rr(&stack_a, &stack_b);
	printf("Stack_a: %d %d %d\n", stack_a->data, stack_a->next->data, stack_a->next->next->data);
	printf("Stack_b: %d %d %d\n\n\n", stack_b->data, stack_b->next->data, stack_b->next->next->data);

	/* Teste - rra */
	printf("Teste - rra\n\n");
	printf("Stack_a: %d %d %d\n", stack_a->data, stack_a->next->data, stack_a->next->next->data);
	rra(&stack_a);
	printf("Stack_a: %d %d %d\n\n\n", stack_a->data, stack_a->next->data, stack_a->next->next->data);

	/* Teste - rrb */
	printf("Teste - rrb\n\n");
	printf("Stack_b: %d %d %d\n", stack_b->data, stack_b->next->data, stack_b->next->next->data);
	rrb(&stack_b);
	printf("Stack_b: %d %d %d\n\n\n", stack_b->data, stack_b->next->data, stack_b->next->next->data);

	/* Teste - rrr */
	printf("Teste - rrr\n\n");
	printf("Stack_a: %d %d %d\n", stack_a->data, stack_a->next->data, stack_a->next->next->data);
	printf("Stack_b: %d %d %d\n", stack_b->data, stack_b->next->data, stack_b->next->next->data);
	rrr(&stack_a, &stack_b);
	printf("Stack_a: %d %d %d\n", stack_a->data, stack_a->next->data, stack_a->next->next->data);
	printf("Stack_b: %d %d %d\n\n\n", stack_b->data, stack_b->next->data, stack_b->next->next->data);

	return (0);
}
