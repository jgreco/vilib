#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include <assert.h>

#define for_each(i, l) for(i = al_first(l); i != al_end(l); i = al_next(i, l))

typedef struct arraylist_str {
	void **data;
	int len;

	int last;
} *arraylist;

int al_first(arraylist L);
int al_end(arraylist L);
int al_next(int p, arraylist L);
int al_previous(int p, arraylist L);
void *al_retrieve(int p, arraylist L);
/* int al_locate( ... */
int al_insert(void *data, int p, arraylist L);
int al_delete(int p, arraylist L);

int al_empty(arraylist L);

arraylist al_makenull(arraylist L);
int al_destroy(arraylist L);

#endif
