#ifndef VILIB_H_
#define VILIB_H_

#include <stddef.h>
#include "arraylist.h"

typedef enum { VL_UP, VL_DOWN, VL_RIGHT, VL_LEFT, VL_BACKSPACE, VL_END, VL_HOME, VL_DELETE, VL_CHAR } vl_type;

typedef struct {
	vl_type type;
	char payload;
} vl_atom;

typedef struct {
	char *text, *end;  /* user data */
	char *dot;  /* where actions take place */
	int text_size;

	arraylist input;
	arraylist output;
} vl_buff;

vl_buff *vilib_init();  /* initialize a vilib buffer */

int vilib_q_intput(vl_buff *buff, char *input, size_t size);  /* queue text input */
int vilib_q_special_input(vl_buff *buff, vl_type input);

int vilib_process(vl_buff *buff);

vl_atom **vilib_cooked_output(vl_buff *buff);

#endif
