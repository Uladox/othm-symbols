/*    This file is part of Othm_symbols.
 *
 *    Othm_symbols is free software: you can redistribute it and/or modify
 *    it under the terms of the Lesser GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    Othm_symbols is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    Lesser GNU General Public License for more details.
 *
 *    You should have received a copy of the Lesser GNU General Public License
 *    along with Ruspma.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "othm_symbols.h"
#include <string.h>
#include <stdio.h>

char othm_symbol_symbol_key_type[] = "symbol";
char othm_symbol_keyword_key_type[] = "keyword";
char othm_symbol_funct_key_type[] = "function";


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
	char *key_type_str;
	if (symbol->request.key_type == othm_symbol_symbol_key_type) {
		key_type_str = "'";
	} else if (symbol->request.key_type == othm_symbol_keyword_key_type) {
		key_type_str = ":";
	} else if (symbol->request.key_type == othm_symbol_funct_key_type) {
		key_type_str = "#'";
	} else {
		key_type_str = "?";
	}
	printf("%s%s", key_type_str, (char *) symbol->request.data);
}
