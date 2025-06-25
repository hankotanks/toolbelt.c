#include "tokenizer.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define STB_DS_IMPLEMENTATION
#include <stb_ds.h>

#ifndef TOKEN_TYPE_LIST
#define TOKEN_TYPE_LIST
#endif

ptrdiff_t tokenize_symbol(const char* ptr, const char symbol) {
    return (ptrdiff_t) (*ptr == symbol);
}

ptrdiff_t tokenize_while(const char* ptr, const char* symbols) {
    const char* ptr_curr = ptr;
    while(strchr(symbols, *ptr_curr) && (*ptr_curr) != '\0') ++ptr_curr;
    return (ptr_curr == ptr) ? (ptrdiff_t) 0 : (ptr_curr - ptr);
}

ptrdiff_t tokenize_until(const char* ptr, const char* symbols) {
    const char* ptr_curr = ptr;
    while(strchr(symbols, *ptr_curr) == NULL && (*ptr_curr) != '\0') ++ptr_curr;
    return (ptr_curr == ptr) ? (ptrdiff_t) 0 : (ptr_curr - ptr);
}

ptrdiff_t tokenize_between_symbol(const char* ptr, const char symbol) {
    char symbols[2];
    symbols[0] = symbol;
    symbols[1] = '\0';
    if(tokenize_symbol(ptr, symbol)) 
        return tokenize_until(ptr + 1, symbols) + 2;
    return (ptrdiff_t) 0;
}

ptrdiff_t tokenize_skip_whitespace(const char* ptr) {
    return tokenize_while(ptr, " \t\r\n");
}

const char* stringify_token_type(const struct token token) {
    switch(token.type) {
#define X(n_) case n_: return #n_;
        TOKEN_TYPE_LIST
#undef X
        default: return "TOKEN_ERROR";
    }
}

#define TOKEN_DUMP(t)\
    printf("%s(%.*s) ", stringify_token_type((t)), (int) (t).span, (t).ptr)

const struct token* tokenize(const char* ptr, const bool dump) {
    struct token* tokens = NULL;
    ptrdiff_t span;
    (void) span;
    struct token curr;
    while(*ptr != '\0') {
        ptr += tokenize_skip_whitespace(ptr);
        span = 0;
#define X(n_)\
        if((span = parse_##n_(ptr))) {\
            curr = (struct token) { (n_), ptr, span };\
            if(dump) TOKEN_DUMP(curr);\
            stbds_arrput(tokens, curr);\
            ptr += span;\
            continue;\
        }
        TOKEN_TYPE_LIST
#undef X
    }

    return tokens;
}

void free_tokens(const struct token* tokens) {
    stbds_arrfree(tokens);
}
