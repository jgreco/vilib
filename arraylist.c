#include <stdlib.h>

#include "arraylist.h"

static int resize(arraylist L);

int al_first(arraylist L)
{
	return 0;
}

int al_end(arraylist L)
{
	return L->last+1;
}

int al_next(int p, arraylist L)
{
	if(p < al_end(L))
		return p+1;
	else
		assert(0);  /* shit bricks */
}

int al_previous(int p, arraylist L)
{
	if(p > al_first(L))
		return p-1;
	else
		assert(0);  /* shit bricks */
}

void *al_retrieve(int p, arraylist L)
{
	if(p >= al_first(L) && p < al_end(L))
		return L->data[p];
	else
		assert(0);  /* shit bricks */
}

int al_insert(void *data, int p, arraylist L)
{
	if(L->len == L->last+1)
		resize(L);

	if(p != al_end(L))
	{
		int i;

		for(i = L->last; i>=p; i--)
			L->data[i+1] = L->data[i];
	}

	L->data[p] = data;
	L->last++;

	return 0;
}

int al_delete(int p, arraylist L)
{
	if(p != al_previous(al_end(L), L)) {
		int i;

		for(i=p; i<L->last; i++)
			L->data[i] = L->data[i+1];
	}

	L->last--;

	return 0;
}

int al_empty(arraylist L)
{
	return L->last == -1;
}

arraylist al_makenull(arraylist L)
{
	if(L==NULL)
		L = (arraylist)malloc(sizeof(struct arraylist_str));
	else
		free(L->data);

	L->data = malloc(10 * sizeof(void*));

	L->len = 10;
	L->last = -1;

	return L;
}

int al_destroy(arraylist L)
{
	free(L->data);
	free(L);

	return 0;
}

int resize(arraylist L)
{
	int i = L->len;

	void *tmp = realloc(L->data, i*2*sizeof(void*));

	if(tmp)
		L->data = tmp;

	L->len = i*2;

	return 0;
}
