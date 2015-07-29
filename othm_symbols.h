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
 #ifndef OTHM_SYMBOLS_H
#define OTHM_SYMBOLS_H

#include <othm_hashmap.h>

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

#define OTHM_SYMBOL_EXPORT(SYMBOL) \
	extern struct othm_symbol_struct OTHM_SYMBOL_SYMBOL ## SYMBOL
#define OTHM_KEYWORD_EXPORT(KEYWORD) \
	extern struct othm_symbol_struct OTHM_SYMBOL_KEYWORD ## KEYWORD

#define OTHM_SYMBOL(SYMBOL) (&OTHM_SYMBOL_SYMBOL ## SYMBOL)
#define OTHM_KEYWORD(KEYWORD) (&OTHM_SYMBOL_KEYWORD ## KEYWORD)

#define OTHM_SYMBOL_NAME(SYMBOL) ((char *)(OTHM_SYMBOL(SYMBOL))->request.data)
#define OTHM_KEYWORD_NAME(KEYWORD) ((char *)(OTHM_KEYWORD(KEYWORD))->request.data)

#define OTHM_SYMBOL_ALLOW_AT_RUNTIME(SYMBOL) \
	othm_symbol_allow_at_runtime(OTHM_SYMBOL(SYMBOL))

#define OTHM_KEYWORD_ALLOW_AT_RUNTIME(KEYWORD) \
	othm_symbol_allow_at_runtime(OTHM_KEYWORD(KEYWORD))

struct othm_symbol_struct {
	struct othm_request request;
};

extern char othm_symbol_symbol_type[];
extern char othm_symbol_keyword_type[];

extern struct othm_hashmap *othm_global_symbol_map;

void othm_symbols_init_runtime(void);

void othm_symbol_allow_at_runtime(struct othm_symbol_struct *symbol);

int othm_symbol_pointer_compare(void *storage, void *data);

int othm_symbol_string_compare(void *storage, void *data);

struct othm_symbol_struct *othm_symbol_get_from_string(char *name);

struct othm_symbol_struct *othm_keyword_get_from_string(char *name);

void othm_symbol_print(struct othm_symbol_struct *symbol);

#endif
