#ifndef __TOKENIZER_PRELUDE_H__
#define __TOKENIZER_PRELUDE_H__

#include <stddef.h>
#include <stdbool.h>

#if defined(__GNUC__) || defined(__clang__)
#define TOKEN_PARSER_UNUSED __attribute__((unused))
#else
#define TOKEN_PARSER_UNUSED
#endif

#define TOKEN_PARSER_DECL(type) static inline ptrdiff_t TOKEN_PARSER_UNUSED parse_##type(const char* ptr)

ptrdiff_t tokenize_symbol(const char* ptr, const char symbol);
ptrdiff_t tokenize_while(const char* ptr, const char* matches);
ptrdiff_t tokenize_until(const char* ptr, const char* matches);
ptrdiff_t tokenize_between_symbol(const char* ptr, const char symbol);

#endif // __TOKENIZER_PRELUDE_H__
