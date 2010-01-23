#include "vilib.h"
#include <stdlib.h>

vl_buff *vilib_init()
{
	vl_buff *new = (vl_buff* )malloc(sizeof(vl_buff));

	new->text_size = sizeof(char) * 10240;

	new->dot = new->end = new->text = (char *)malloc(new->text_size);

	new->input = al_makenull(NULL);
	new->output = al_makenull(NULL);

	/* TODO: insert a 'dummy line' ('\n') */

	return new;
}

int vilib_q_input(vl_buff *buff, char *in, size_t size)
{
	int i;
	vl_atom *tmp;

	arraylist input = buff->input;

	for(i=0; i<size; i++) {
		tmp = (vl_atom * )malloc(sizeof(vl_atom));
		tmp->type = VL_CHAR;
		tmp->payload = in[i];

		al_insert(tmp, al_end(input), input);
	}

	return i;
}

int vilib_q_special_input(vl_buff *buff, vl_type in)
{
	arraylist input = buff->input;

	vl_atom *tmp = (vl_atom * )malloc(sizeof(vl_atom));

	tmp->type = in;

	al_insert(tmp, al_end(input), input);

	return 1;
}

vl_atom **vilib_cooked_output(vl_buff *buff)
{
	int num, i, p;
	arraylist output;

	output = buff->output;
	num = al_end(output);
	p = al_first(output);

	vl_atom **out = (vl_atom ** )malloc(sizeof(vl_atom * ) * num);

	for_each(i, output) {
		out[i] = al_retrieve(i, output);
	}

	al_destroy(output);
	buff->output = al_makenull(NULL);

	return out;
}
