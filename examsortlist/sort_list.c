#include "list.h"
#include <unistd.h>

void swap(int *a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *head;
	head = lst;
	int tmp;
	while(lst->next != NULL)
	{
	if (cmp(lst->data, lst->next->data) > 0)
	{
		swap(&lst->data, &lst->next->data);
		lst = head;
	}
	else
		lst = lst->next;
	}
	lst = head;
}