#include "list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

t_list *addfrontnum(t_list *lista, int val)
{
	t_list *nuovo_lista;
	nuovo_lista = (t_list *)malloc(sizeof(t_list));
	if (nuovo_lista == NULL) //buono da usare. in caso la memoria sia tutta occupata.
		return (NULL);
	nuovo_lista->data = val;
	if(lista == NULL)
		nuovo_lista->next = NULL;
	else
		nuovo_lista->next = lista;
	return(nuovo_lista);
}

int orderascending(int a, int b)
{
	return(a-b);
}


int orderdescending(int a, int b)
{
	return(b-a);
}

int main(int argc, char**argv)
{
	t_list *lista;
	lista = NULL; //vale già come next null
	int i;
	i = 1;
	if(argc > 1)
	{
		while (argv[i])
			lista = addfrontnum(lista, atoi(argv[i++]));
		sort_list(lista, orderdescending);
		t_list *scorri;
		scorri = lista;
		while(scorri != NULL)
		{
			printf("%d", scorri->data);
			scorri = scorri->next;
		}
	}
}