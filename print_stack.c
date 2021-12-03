#include "push_swap.h"

static void print_stack_bon_sens(t_stack *stack)
{
	while (stack != NULL)
	{
		printf("%d ", stack->element);
		stack = stack->next;
	}
	printf("\n");
}

static void print_stack_mau_sens(t_stack *stack)
{
	t_stack *last;

	last = get_last_element(stack);
	while (last != NULL)
	{
		printf("%d ", last->element);
		last = last->prec;
	}
	printf("\n");
}