#include "sort.h"

/**
 * insertion_sort_list - insertion sort method.
 * @list: double linked list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *tpre, *tnext, *t;
	int i, j, size = 0, tmp;

	temp = *list;
	while (temp)
	{
		temp = temp->next;
		size++;
	}

	temp = (*list)->next;

	for (i = 1; i < size; i++)
	{
		tmp = temp->n;
		t = temp->next;
		j = i - 1;
		while (j >= 0 && temp->prev->n > tmp)
		{
			/* guardar temporales */
			tpre = temp->prev;
			tnext = temp->next;

			/* validar si el previo es la cabeza */
			if (tpre->prev)
				tpre->prev->next = temp;
			else
				*list = temp;
			temp->prev->next = tnext;
			temp->prev = temp->prev->prev;
			tpre->prev = temp;
			/* validar si el siguiente es null */
			if (temp->next)
				temp->next->prev = tpre;
			temp->next = tpre;
			j--;
			print_list(*list);
		}
		temp = t;
	}
}
