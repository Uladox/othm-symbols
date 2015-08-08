#include "othm_symbols.h"
#include <string.h>
#include <stdio.h>

char othm_symbol_symbol_key_type[] = "symbol";
char othm_symbol_keyword_key_type[] = "keyword";

struct othm_hashmap *othm_global_symbol_map;

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
	request.key_type = othm_symbol_symbol_key_type;
	request.check_key = othm_symbol_string_compare;
	return othm_hashmap_get(othm_global_symbol_map, &request);
}

struct othm_symbol_struct *othm_keyword_get_from_string(char *name)
{
	struct othm_request request;
	request.data = name;
	request.data_size = strlen(name) + 1;
	request.key_type = othm_symbol_keyword_key_type;
	request.check_key = othm_symbol_string_compare;
	return othm_hashmap_get(othm_global_symbol_map, &request);
}

void othm_symbol_print(struct othm_symbol_struct *symbol)
{
	char key_type_char;
	if (symbol->request.key_type == othm_symbol_symbol_key_type) {
		key_type_char = '\'';
	} else if (symbol->request.key_type == othm_symbol_keyword_key_type) {
		key_type_char = ':';
	} else {
		key_type_char = '?';
	}
	printf("%c%s", key_type_char, (char *) symbol->request.data);
}
