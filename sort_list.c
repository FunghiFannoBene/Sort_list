#include "list.h"
#include <unistd.h>

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int		overflow;
	t_list	*head;

	head = lst; //salvo l'inizio lista.
	while (lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) > 0) //paragona il precedente con il successivo, in caso il precedente sia più grande si muovono.
		{
			overflow = lst->data; //save data to overflow. head di swap
			lst->data = lst->next->data; //data diventa next data siccome ha gia salvato il suo val su overflow
			lst->next->data = overflow; //riprende i dati da overflow.
			lst = head; //return to the start perchè deve riordinare dinuovo per essere corretto in caso di valori piu piccoli infondo.
		}
		else
			lst = lst->next;//lista next 
	}
	lst->next = NULL; //fine lista 
	return (head);
}