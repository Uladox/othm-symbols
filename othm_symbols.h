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
		.request.key_type = othm_symbol_symbol_key_type,	\
		.request.check_key = othm_symbol_pointer_compare	\
	};								\
	struct othm_symbol_struct *					\
	OTHM_SYMBOL_SYMBOL ## SYMBOL ## REF =				\
		&OTHM_SYMBOL_SYMBOL ## SYMBOL

#define OTHM_SYMBOL_INIT_TAGGED_LEFT(LTAG_TYPE, SYMBOL)			\
	struct {							\
		LTAG_TYPE ltag;						\
		struct othm_symbol_struct OTHM_SYMBOL_SYMBOL ## SYMBOL = { \
			.request.data = #SYMBOL,			\
			.request.data_size = sizeof(#SYMBOL),		\
			.request.key_type = othm_symbol_symbol_key_type, \
			.request.check_key = othm_symbol_pointer_compare \
		};							\
	} OTHM_SYMBOL_SYMBOL ## SYMBOL ## LTAGGED;			\
	struct othm_symbol_struct *					\
	OTHM_SYMBOL_SYMBOL ## SYMBOL ## REF =				\
		&OTHM_SYMBOL_SYMBOL ## SYMBOL ## LTAGGED.

#define OTHM_SYMBOL_INIT_TAGGED_LEFT(RTAG_TYPE, SYMBOL)			\
	struct {							\
		struct othm_symbol_struct OTHM_SYMBOL_SYMBOL ## SYMBOL = { \
			.request.data = #SYMBOL,			\
			.request.data_size = sizeof(#SYMBOL),		\
			.request.key_type = othm_symbol_symbol_key_type, \
			.request.check_key = othm_symbol_pointer_compare \
		};							\
		RTAG_TYPE rtag;
	} OTHM_SYMBOL_SYMBOL ## SYMBOL ## LTAGGED;			\
	struct othm_symbol_struct *					\
	OTHM_SYMBOL_SYMBOL ## SYMBOL ## REF =				\
		&OTHM_SYMBOL_SYMBOL ## SYMBOL ## LTAGGED

#define OTHM_KEYWORD_INIT(KEYWORD)					\
	struct othm_symbol_struct OTHM_SYMBOL_KEYWORD ## KEYWORD = {	\
		.request.data = #KEYWORD,				\
		.request.data_size = sizeof(#KEYWORD),			\
		.request.key_type = othm_symbol_keyword_key_type,	\
		.request.check_key = othm_symbol_pointer_compare	\
	};								\
	struct othm_symbol_struct *					\
	OTHM_SYMBOL_KEYWORD ## KEYWORD ## REF =				\
		&OTHM_SYMBOL_KEYWORD ## KEYWORD

/* NOTE, this uses function declarations that are not prototypes, it
   will work with any standard C compiler, but might return warnings! */
#define OTHM_PRIM_FUNCT_INIT(PRIM_FUNCT, NAME, RETURN_TYPE)		\
	RETURN_TYPE PRIM_FUNCT ();					\
	struct othm_funct OTHM_SYMBOL_PRIM_OTHM_FUNCT ## PRIM_FUNCT = {	\
		.function = (void (*) (void)) PRIM_FUNCT,		\
		.name = #NAME						\
        };								\
	struct othm_symbol_struct OTHM_SYMBOL_PRIM_FUNCT ## PRIM_FUNCT = { \
		.request.data = &OTHM_SYMBOL_PRIM_OTHM_FUNCT ## PRIM_FUNCT, \
		.request.data_size = sizeof(struct othm_funct),		\
		.request.key_type = othm_symbol_funct_key_type,		\
		.request.check_key = othm_symbol_pointer_compare	\
	};								\
	struct othm_symbol_struct *					\
	OTHM_SYMBOL_PRIM_FUNCT ## PRIM_FUNCT ## REF =			\
		&OTHM_SYMBOL_PRIM_FUNCT ## PRIM_FUNCT

#define OTHM_SYMBOL_EXPORT(SYMBOL)					\
	extern struct othm_symbol_struct *				\
	OTHM_SYMBOL_SYMBOL ## SYMBOL ## REF
#define OTHM_KEYWORD_EXPORT(KEYWORD)					\
	extern struct othm_symbol_struct *				\
	OTHM_SYMBOL_KEYWORD ## KEYWORD ## REF
#define OTHM_PRIM_FUNCT_EXPORT(PRIM_FUNCT)				\
	extern struct othm_symbol_struct *				\
	OTHM_SYMBOL_PRIM_FUNCT ## PRIM_FUNCT

#define OTHM_SYMBOL(SYMBOL) (OTHM_SYMBOL_SYMBOL ## SYMBOL ## REF)
#define OTHM_KEYWORD(KEYWORD) (OTHM_SYMBOL_KEYWORD ## KEYWORD ## REF)
#define OTHM_PRIM_FUNCT(PRIM_FUNCT)			\
	(OTHM_SYMBOL_PRIM_FUNCT ## PRIM_FUNCT ## REF)

#define OTHM_SYMBOL_NAME_L(SYMBOL)			\
	((char *)(OTHM_SYMBOL(SYMBOL))->request.data)
#define OTHM_KEYWORD_NAME_L(KEYWORD)			\
	((char *)(OTHM_KEYWORD(KEYWORD))->request.data)
#define OTHM_PRIM_FUNCT_NAME_L(PRIM_FUNCT)				\
	((char *)							\
	 ((struct othm_funct *) (OTHM_PRIM_FUNCT(PRIM_FUNCT))->request.data) \
	 ->name)

#define OTHM_SYMBOL_NAME(SYMBOL)		\
	((char *)(SYMBOL)->request.data)
#define OTHM_KEYWORD_NAME(KEYWORD)		\
	((char *)(KEYWORD)->request.data)
#define OTHM_PRIM_FUNCT_NAME(PRIM_FUNCT)				\
	((char *)							\
	 ((struct othm_funct *) (PRIM_FUNCT)->request.data) \
	 ->name)

#define OTHM_SYMBOL_ALLOW_AT_RUNTIME(SYMBOL)			\
	othm_symbol_allow_at_runtime(OTHM_SYMBOL(SYMBOL))

#define OTHM_KEYWORD_ALLOW_AT_RUNTIME(KEYWORD)			\
	othm_symbol_allow_at_runtime(OTHM_KEYWORD(KEYWORD))

#define OTHM_PRIM_FUNCT_ALLOW_AT_RUNTIME(PRIM_FUNCT)		\
	othm_symbol_allow_at_runtime(OTHM_PRIM_FUNCT(PRIM_FUNCT))

/* This is a macro that takes a othm function symbol, a type for
   the symbol, and some values to apply the symbol on. It generates
   the an identifier for the symbol OTHM_SYMBOL_PRIM_FUNCT ## PRIM_FUNCT
   then it gets the data in the request (which is an othm_funct), this
   requires converting the .data from void* to struct othm_funct*
   next it casts the function in the stuct othm_funct* to the given
   type before calling it on the params. It is not too dificult to
   figure out, but I dout many C programmers understand the preprocessor
   as well as they should. Seriously, learn the preprocessor!
*/
#define OTHM_PRIM_FUNCT_APPLY_L(PRIM_FUNCT, FUNCTION_TYPE_CAST, PARAMS)	\
	((FUNCTION_TYPE_CAST)						\
	 (((struct othm_funct *)					\
	   OTHM_SYMBOL_PRIM_FUNCT ## PRIM_FUNCT.request.data)		\
	  ->function))PARAMS

#define OTHM_PRIM_FUNCT_APPLY(PRIM_FUNCT, FUNCTION_TYPE_CAST, PARAMS)	\
	((FUNCTION_TYPE_CAST)						\
	 (((struct othm_funct *)					\
	   (PRIM_FUNCT).request.data)					\
	  ->function))PARAMS

#define OTHM_PRIM_FUNCT_GET(PRIM_FUNCT, FUNCTION_TYPE_CAST)		\
	((FUNCTION_TYPE_CAST)						\
	 (((struct othm_funct *)					\
	   (PRIM_FUNCT)->request.data)					\
	  ->function))

struct othm_symbol_struct {
	struct othm_request request;
};

extern char othm_symbol_symbol_key_type[];
extern char othm_symbol_keyword_key_type[];
extern char othm_symbol_funct_key_type[];

extern struct othm_hashmap *othm_global_symbol_map;

void othm_symbols_init_runtime(void);

void othm_symbol_allow_at_runtime(struct othm_symbol_struct *symbol);

int othm_symbol_pointer_compare(void *storage, void *data);

int othm_symbol_string_compare(void *storage, void *data);

struct othm_symbol_struct *othm_symbol_get_from_string(char *name);

struct othm_symbol_struct *othm_keyword_get_from_string(char *name);

void othm_symbol_print(struct othm_symbol_struct *symbol);

#endif
