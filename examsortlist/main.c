#include "list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int crescent(int a, int b)
{
	return(a-b);
}

int dcrescent(int a, int b)
{
	return(b-a);
}

t_list *addfrontnum(t_list **lista, int val)
{
	t_list *new;
	new = malloc(sizeof(t_list));
	if(new == NULL)
		return(NULL);
	new->data = val;
	new->next = NULL;
	if(lista != NULL)
		new->next = *lista;
	*lista = new;
}

int main(int argc, char** argv)
{
	t_list *lista;
	lista = NULL;
	int i;
	i=1;
	if(argc > 1)
	{
		while(argv[i])
			addfrontnum(&lista, atoi(argv[i++]));
	}
	lista = sort_list(lista, crescent);
	lista = sort_list(lista, dcrescent);
	t_list *scorri;
	scorri = lista;
	while(scorri != NULL)
	{
		printf("%d", scorri->data);
		scorri = scorri->next;
	}
}