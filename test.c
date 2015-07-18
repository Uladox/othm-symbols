#include <stdio.h>
#include <stdlib.h>
#include <othm_symbols.h>

#ifndef OTHM_SYMBOL_SYMBOL_HI
#define OTHM_SYMBOL_SYMBOL_HI
OTHM_SYMBOL_INIT(hi);
#endif

#ifndef OTHM_SYMBOL_KEYWORD_BYE
#define OTHM_SYMBOL_KEYWORD_BYE
OTHM_KEYWORD_INIT(bye);
#endif

int main(void)
{
	othm_symbols_init_runtime();
	OTHM_SYMBOL_ALLOW_AT_RUNTIME(hi);
	OTHM_KEYWORD_ALLOW_AT_RUNTIME(bye);
	othm_symbol_print(othm_symbol_get_from_string("hi"));
	printf(" ");
	othm_symbol_print(othm_keyword_get_from_string("bye"));
	printf("\n");
	if(OTHM_SYMBOL(hi) == OTHM_SYMBOL(hi))
		printf("%s\n", OTHM_KEYWORD_NAME(bye));
}
