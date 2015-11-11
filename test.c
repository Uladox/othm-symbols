#include <stdio.h>
#include <stdlib.h>
#include <othm_symbols.h>
#include "test2.h"

#ifndef OTHM_SYMBOL_SYMBOL_HI
#define OTHM_SYMBOL_SYMBOL_HI
OTHM_SYMBOL_INIT_TAGGED_BOTH(hi, char, int);
#endif

#ifndef OTHM_SYMBOL_KEYWORD_BYE
#define OTHM_SYMBOL_KEYWORD_BYE
OTHM_KEYWORD_INIT_TAGGED_RIGHT(bye, double);
#endif

OTHM_PRIM_FUNCT_INIT_TAGGED_BOTH(equal, equal, void,
				 void *, long int);

int main(void)
{
	/* equal(OTHM_SYMBOL(cat)); */
	printf("calling %s results in:\n", OTHM_PRIM_FUNCT_STR_NAME_L(equal));
	OTHM_PRIM_FUNCT_APPLY_L
		(equal, void (*) (struct othm_symbol_struct *),
		 (OTHM_SYMBOL(cat)));
	othm_symbols_init_runtime();
	OTHM_SYMBOL_ALLOW_AT_RUNTIME(hi);
	OTHM_KEYWORD_ALLOW_AT_RUNTIME(bye);
	othm_symbol_print(othm_symbol_get_from_string("hi"));
	printf(" ");
	othm_symbol_print(othm_keyword_get_from_string("bye"));
	printf("\n");
	if(OTHM_SYMBOL(hi) == OTHM_SYMBOL(hi))
		printf("%s\n", OTHM_KEYWORD_STR_NAME_L(bye));
}
