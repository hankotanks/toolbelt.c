#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__

#include <stddef.h>
#include <stdbool.h>
#ifdef TOKENS
#include TOKENS
#endif

struct token {
    enum {
#define X(n_) n_,
        TOKEN_TYPE_LIST
#undef X
    } type;
    const char* ptr;
    ptrdiff_t span;
};

const struct token* tokenize(const char* ptr, const bool dump);
void free_tokens(const struct token* tokens);

#endif // __TOKENIZER_H__
