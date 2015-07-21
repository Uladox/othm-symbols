#include <stdio.h>
#include "test2.h"

#ifndef OTHM_SYMBOL_SYMBOL_CAT
#define OTHM_SYMBOL_SYMBOL_CAT
OTHM_SYMBOL_INIT(cat);
#endif

void equal(struct othm_symbol_struct *a)
{
	if(a == OTHM_SYMBOL(cat))
		printf("CATSSS!");
}
