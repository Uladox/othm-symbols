#ifndef OTHM_SYMBOLS_H
#define OTHM_SYMBOLS_H

#include <othm_hashmap.h>
#include <string.h>

#define OTHMSYMBOLSTRUCT(SYMBOL) ((struct othm_symbol_struct *) (SYMBOL))
#define OTHM_SYMBOL_INIT(SYMBOL)					\
	struct othm_symbol_struct OTHM_SYMBOL_SYMBOL ## SYMBOL = {	\
		.request.data = #SYMBOL,				\
		.request.data_size = sizeof(#SYMBOL),			\
		.request.type = othm_symbol_symbol_type,		\
		.request.check_key = othm_symbol_pointer_compare	\
	}

#define OTHM_KEYWORD_INIT(KEYWORD)					\
	struct othm_symbol_struct OTHM_SYMBOL_KEYWORD ## KEYWORD = {	\
		.request.data = #KEYWORD,				\
		.request.data_size = sizeof(#KEYWORD),			\
		.request.type = othm_symbol_keyword_type,		\
		.request.check_key = othm_symbol_pointer_compare	\
	}

#define OTHM_SYMBOL(SYMBOL) (&OTHM_SYMBOL_SYMBOL ## SYMBOL)
#define OTHM_KEYWORD(KEYWORD) (&OTHM_SYMBOL_KEYWORD ## KEYWORD)

#define OTHM_SYMBOL_NAME(SYMBOL) ((OTHM_SYMBOL(SYMBOL))->request.data)
#define OTHM_KEYWORD_NAME(KEYWORD) ((OTHM_KEYWORD(KEYWORD))->request.data)

#define OTHM_SYMBOL_ALLOW_AT_RUNTIME(SYMBOL) \
	othm_symbol_allow_at_runtime(OTHM_SYMBOL(SYMBOL))

#define OTHM_KEYWORD_ALLOW_AT_RUNTIME(KEYWORD) \
	othm_symbol_allow_at_runtime(OTHM_KEYWORD(KEYWORD))

char othm_symbol_symbol_type[] = "symbol";
char othm_symbol_keyword_type[] = "keyword";

struct othm_hashmap *othm_global_symbol_map;

struct othm_symbol_struct {
	struct othm_request request;
};

void othm_symbols_init_runtime(void)
{
	othm_global_symbol_map = othm_hashmap_new_seq(4);
}

void othm_symbol_allow_at_runtime(struct othm_symbol_struct *symbol)
{
	othm_hashmap_add(othm_global_symbol_map,
			 OTHMREQUEST(symbol),
			 symbol);
}

int othm_symbol_pointer_compare(void *storage, void *data)
{
	return storage == data;
}

int othm_symbol_string_compare(void *storage, void *data)
{
	return !(strcmp((char *)storage, (char *)data));
}

struct othm_symbol_struct *othm_symbol_get_from_string(char *name)
{
	struct othm_request request;
	request.data = name;
	request.data_size = strlen(name) + 1;
	request.type = othm_symbol_symbol_type;
	request.check_key = othm_symbol_string_compare;
	return othm_hashmap_get(othm_global_symbol_map, &request);
}

struct othm_symbol_struct *othm_keyword_get_from_string(char *name)
{
	struct othm_request request;
	request.data = name;
	request.data_size = strlen(name) + 1;
	request.type = othm_symbol_keyword_type;
	request.check_key = othm_symbol_string_compare;
	return othm_hashmap_get(othm_global_symbol_map, &request);
}

void othm_symbol_print(struct othm_symbol_struct *symbol)
{
	char type_char;
	if (symbol->request.type == othm_symbol_symbol_type) {
		type_char = '\'';
	} else if (symbol->request.type == othm_symbol_keyword_type) {
		type_char = ':';
	} else {
		type_char = '?';
	}
	printf("%c%s", type_char, symbol->request.data);
}

#endif
