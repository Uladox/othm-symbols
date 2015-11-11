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

#define OTHM_SYMBOL_INIT(NAME)						\
	struct othm_symbol_struct OTHM_SYMBOL_SYMBOL ## NAME = {	\
		.request.data = #NAME,					\
		.request.data_size = sizeof(#NAME),			\
		.request.key_type = othm_symbol_symbol_key_type,	\
		.request.check_key = othm_symbol_pointer_compare	\
	};								\
	struct othm_symbol_struct *					\
	OTHM_SYMBOL_SYMBOL ## NAME ## REF =				\
		&OTHM_SYMBOL_SYMBOL ## NAME

#define OTHM_SYMBOL_INIT_TAGGED_LEFT(NAME, LTAG_TYPE, ...)		\
	struct {							\
		LTAG_TYPE ltag;						\
		struct othm_symbol_struct symbol;			\
	} OTHM_SYMBOL_SYMBOL ## NAME ## LTAGGED = {			\
		.symbol.request.data = #NAME,				\
		.symbol.request.data_size = sizeof(#NAME),		\
		.symbol.request.key_type = othm_symbol_symbol_key_type,	\
		.symbol.request.check_key = othm_symbol_pointer_compare, \
		__VA_ARGS__						\
	};								\
	struct othm_symbol_struct *					\
	OTHM_SYMBOL_SYMBOL ## NAME ## REF =				\
		&OTHM_SYMBOL_SYMBOL ## NAME ## LTAGGED.symbol

#define OTHM_SYMBOL_INIT_TAGGED_RIGHT(NAME, RTAG_TYPE, ...)		\
	struct {							\
		struct othm_symbol_struct symbol;			\
		RTAG_TYPE rtag;						\
	} OTHM_SYMBOL_SYMBOL ## NAME ## RTAGGED = {			\
		.symbol.request.data = #NAME,				\
		.symbol.request.data_size = sizeof(#NAME),		\
		.symbol.request.key_type = othm_symbol_symbol_key_type,	\
		.symbol.request.check_key = othm_symbol_pointer_compare, \
		__VA_ARGS__						\
	};								\
	struct othm_symbol_struct *					\
	OTHM_SYMBOL_SYMBOL ## NAME ## REF =				\
		&OTHM_SYMBOL_SYMBOL ## NAME ## RTAGGED.symbol

#define OTHM_SYMBOL_INIT_TAGGED_BOTH(NAME, LTAG_TYPE, RTAG_TYPE, ...)	\
	struct {							\
		LTAG_TYPE ltag;						\
		struct othm_symbol_struct symbol;			\
		RTAG_TYPE rtag;						\
	} OTHM_SYMBOL_SYMBOL ## NAME ## BTAGGED = {			\
		.symbol.request.data = #NAME,				\
		.symbol.request.data_size = sizeof(#NAME),		\
		.symbol.request.key_type = othm_symbol_symbol_key_type,	\
		.symbol.request.check_key = othm_symbol_pointer_compare, \
		__VA_ARGS__						\
	};								\
	struct othm_symbol_struct *					\
	OTHM_SYMBOL_SYMBOL ## NAME ## REF =				\
		&OTHM_SYMBOL_SYMBOL ## NAME ## BTAGGED.symbol

#define OTHM_KEYWORD_INIT(NAME)						\
	struct othm_symbol_struct OTHM_SYMBOL_KEYWORD ## NAME = {	\
		.request.data = #NAME,					\
		.request.data_size = sizeof(#NAME),			\
		.request.key_type = othm_symbol_keyword_key_type,	\
		.request.check_key = othm_symbol_pointer_compare	\
	};								\
	struct othm_symbol_struct *					\
	OTHM_SYMBOL_KEYWORD ## NAME ## REF =				\
		&OTHM_SYMBOL_KEYWORD ## NAME

#define OTHM_KEYWORD_INIT_TAGGED_LEFT(NAME, LTAG_TYPE, ...)		\
	struct {							\
		LTAG_TYPE ltag;						\
		struct othm_symbol_struct symbol;			\
	} OTHM_SYMBOL_KEYWORD ## NAME ## LTAGGED = {			\
		.symbol.request.data = #NAME,				\
		.symbol.request.data_size = sizeof(#NAME),		\
		.symbol.request.key_type = othm_symbol_keyword_key_type, \
		.symbol.request.check_key = othm_symbol_pointer_compare, \
		__VA_ARGS__						\
	};								\
	struct othm_symbol_struct *					\
	OTHM_SYMBOL_KEYWORD ## NAME ## REF =				\
		&OTHM_SYMBOL_KEYWORD ## NAME ## LTAGGED.symbol

#define OTHM_KEYWORD_INIT_TAGGED_RIGHT(NAME, RTAG_TYPE, ...)		\
	struct {							\
		struct othm_symbol_struct symbol;			\
		RTAG_TYPE rtag;						\
	} OTHM_SYMBOL_KEYWORD ## NAME ## RTAGGED = {			\
		.symbol.request.data = #NAME,				\
		.symbol.request.data_size = sizeof(#NAME),		\
		.symbol.request.key_type = othm_symbol_keyword_key_type, \
		.symbol.request.check_key = othm_symbol_pointer_compare, \
		__VA_ARGS__						\
	};								\
	struct othm_symbol_struct *					\
	OTHM_SYMBOL_KEYWORD ## NAME ## REF =				\
		&OTHM_SYMBOL_KEYWORD ## NAME ## RTAGGED.symbol

#define OTHM_KEYWORD_INIT_TAGGED_BOTH(NAME, LTAG_TYPE, RTAG_TYPE, ...) \
	struct {							\
		LTAG_TYPE ltag;						\
		struct othm_symbol_struct symbol;			\
		RTAG_TYPE rtag;						\
	} OTHM_SYMBOL_KEYWORD ## NAME ## BTAGGED = {			\
		.symbol.request.data = #NAME,				\
		.symbol.request.data_size = sizeof(#NAME),		\
		.symbol.request.key_type = othm_symbol_keyword_key_type, \
		.symbol.request.check_key = othm_symbol_pointer_compare, \
		__VA_ARGS__						\
	};								\
	struct othm_symbol_struct *					\
	OTHM_SYMBOL_KEYWORD ## NAME ## REF =				\
		&OTHM_SYMBOL_KEYWORD ## NAME ## BTAGGED.symbol

/* NOTE, this uses function declarations that are not prototypes, it
   will work with any standard C compiler, but might return warnings! */
#define OTHM_PRIM_FUNCT_INIT(NAME, PRIM_FUNCT, RETURN_TYPE)		\
	RETURN_TYPE PRIM_FUNCT ();					\
	struct othm_funct OTHM_SYMBOL_PRIM_OTHM_FUNCT ## NAME = {	\
		.function = (void (*) (void)) PRIM_FUNCT,		\
		.name = #NAME						\
        };								\
	struct othm_symbol_struct OTHM_SYMBOL_PRIM_FUNCT ## NAME = {	\
		.request.data = &OTHM_SYMBOL_PRIM_OTHM_FUNCT ## NAME,	\
		.request.data_size = sizeof(struct othm_funct),		\
		.request.key_type = othm_symbol_funct_key_type,		\
		.request.check_key = othm_symbol_pointer_compare	\
	};								\
	struct othm_symbol_struct *					\
	OTHM_SYMBOL_PRIM_FUNCT ## NAME ## REF =				\
		&OTHM_SYMBOL_PRIM_FUNCT ## NAME

#define OTHM_PRIM_FUNCT_INIT_TAGGED_LEFT(NAME, PRIM_FUNCT, RETURN_TYPE,	\
					 LTAG_TYPE, ...)		\
	RETURN_TYPE PRIM_FUNCT ();					\
	struct othm_funct OTHM_SYMBOL_PRIM_OTHM_FUNCT ## NAME = {	\
		.function = (void (*) (void)) PRIM_FUNCT,		\
		.name = #NAME						\
        };								\
	struct {							\
		LTAG_TYPE ltag;						\
		struct othm_symbol_struct symbol;			\
	} OTHM_SYMBOL_PRIM_FUNCT ## NAME ## LTAGGED = {			\
		.symbol.request.data =					\
		&OTHM_SYMBOL_PRIM_OTHM_FUNCT ## NAME,			\
		.symbol.request.data_size = sizeof(struct othm_funct),	\
		.symbol.request.key_type = othm_symbol_funct_key_type,	\
		.symbol.request.check_key = othm_symbol_pointer_compare, \
		__VA_ARGS__						\
	};								\
	struct othm_symbol_struct *					\
	OTHM_SYMBOL_PRIM_FUNCT ## NAME ## REF =				\
		&OTHM_SYMBOL_PRIM_FUNCT ## NAME ##LTAGGED.symbol

#define OTHM_PRIM_FUNCT_INIT_TAGGED_RIGHT(NAME, PRIM_FUNCT, RETURN_TYPE, \
					  RTAG_TYPE, ...)		\
	RETURN_TYPE PRIM_FUNCT ();					\
	struct othm_funct OTHM_SYMBOL_PRIM_OTHM_FUNCT ## NAME = {	\
		.function = (void (*) (void)) PRIM_FUNCT,		\
		.name = #NAME						\
        };								\
	struct {							\
		struct othm_symbol_struct symbol;			\
		RTAG_TYPE rtag;						\
	} OTHM_SYMBOL_PRIM_FUNCT ## NAME ## RTAGGED = {			\
		.symbol.request.data =					\
		&OTHM_SYMBOL_PRIM_OTHM_FUNCT ## NAME,			\
		.symbol.request.data_size = sizeof(struct othm_funct),	\
		.symbol.request.key_type = othm_symbol_funct_key_type,	\
		.symbol.request.check_key = othm_symbol_pointer_compare, \
		__VA_ARGS__						\
	};								\
	struct othm_symbol_struct *					\
	OTHM_SYMBOL_PRIM_FUNCT ## NAME ## REF =				\
		&OTHM_SYMBOL_PRIM_FUNCT ## NAME ##RTAGGED.symbol

#define OTHM_PRIM_FUNCT_INIT_TAGGED_BOTH(NAME, PRIM_FUNCT, RETURN_TYPE, \
					 LTAG_TYPE, RTAG_TYPE, ...)	\
	RETURN_TYPE PRIM_FUNCT ();					\
	struct othm_funct OTHM_SYMBOL_PRIM_OTHM_FUNCT ## NAME = {	\
		.function = (void (*) (void)) PRIM_FUNCT,		\
		.name = #NAME						\
        };								\
	struct {							\
		LTAG_TYPE ltag;						\
		struct othm_symbol_struct symbol;			\
		RTAG_TYPE rtag;						\
	} OTHM_SYMBOL_PRIM_FUNCT ## NAME ## BTAGGED = {			\
		.symbol.request.data =					\
		&OTHM_SYMBOL_PRIM_OTHM_FUNCT ## NAME,			\
		.symbol.request.data_size = sizeof(struct othm_funct),	\
		.symbol.request.key_type = othm_symbol_funct_key_type,	\
		.symbol.request.check_key = othm_symbol_pointer_compare, \
		__VA_ARGS__						\
	};								\
	struct othm_symbol_struct *					\
	OTHM_SYMBOL_PRIM_FUNCT ## NAME ## REF =				\
		&OTHM_SYMBOL_PRIM_FUNCT ## NAME ##BTAGGED.symbol

#define OTHM_SYMBOL_EXPORT(NAME)					\
	extern struct othm_symbol_struct *				\
	OTHM_SYMBOL_SYMBOL ## NAME ## REF
#define OTHM_KEYWORD_EXPORT(NAME)					\
	extern struct othm_symbol_struct *				\
	OTHM_SYMBOL_KEYWORD ## NAME ## REF
#define OTHM_PRIM_FUNCT_EXPORT(NAME)					\
	extern struct othm_symbol_struct *				\
	OTHM_SYMBOL_PRIM_FUNCT ## NAME ## REF

#define OTHM_SYMBOL(NAME) (OTHM_SYMBOL_SYMBOL ## NAME ## REF)
#define OTHM_KEYWORD(NAME) (OTHM_SYMBOL_KEYWORD ## NAME ## REF)
#define OTHM_PRIM_FUNCT(NAME)			\
	(OTHM_SYMBOL_PRIM_FUNCT ## NAME ## REF)

#define OTHM_SYMBOL_STR_NAME_L(NAME)			\
	((char *)(OTHM_SYMBOL(NAME))->request.data)
#define OTHM_KEYWORD_STR_NAME_L(NAME)			\
	((char *)(OTHM_KEYWORD(NAME))->request.data)
#define OTHM_PRIM_FUNCT_STR_NAME_L(NAME)				\
	((char *)							\
	 ((struct othm_funct *) (OTHM_PRIM_FUNCT(NAME))->request.data)	\
	 ->name)

#define OTHM_SYMBOL_STR_NAME(SYMBOL)		\
	((char *)(SYMBOL)->request.data)
#define OTHM_KEYWORD_STR_NAME(KEYWORD)		\
	((char *)(KEYWORD)->request.data)
#define OTHM_PRIM_FUNCT_STR_NAME(PRIM_FUNCT)				\
	((char *)							\
	 ((struct othm_funct *) (PRIM_FUNCT)->request.data) \
	 ->name)

#define OTHM_SYMBOL_ALLOW_AT_RUNTIME(NAME)		\
	othm_symbol_allow_at_runtime(OTHM_SYMBOL(NAME))

#define OTHM_KEYWORD_ALLOW_AT_RUNTIME(NAME)			\
	othm_symbol_allow_at_runtime(OTHM_KEYWORD(NAME))

#define OTHM_PRIM_FUNCT_ALLOW_AT_RUNTIME(NAME)			\
	othm_symbol_allow_at_runtime(OTHM_PRIM_FUNCT(NAME))

/* This is a macro that takes a othm function symbol, a type for
   the symbol, and some values to apply the symbol on. It generates
   the an identifier for the symbol OTHM_SYMBOL_PRIM_FUNCT ## NAME
   then it gets the data in the request (which is an othm_funct), this
   requires converting the .data from void* to struct othm_funct*
   next it casts the function in the stuct othm_funct* to the given
   type before calling it on the params. It is not too dificult to
   figure out, but I dout many C programmers understand the preprocessor
   as well as they should. Seriously, learn the preprocessor!
*/
#define OTHM_PRIM_FUNCT_APPLY_L(NAME, FUNCTION_TYPE_CAST, PARAMS)	\
	((FUNCTION_TYPE_CAST)						\
	 (((struct othm_funct *)					\
	   OTHM_SYMBOL_PRIM_FUNCT ## NAME ## REF->request.data)			\
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
