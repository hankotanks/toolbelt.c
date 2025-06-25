#include <string.h>
#include "tokenizer_prelude.h"

#define TOKEN_TYPE_LIST\
    X(TOKEN_IDENT)\
    X(TOKEN_SYMBOL)\
    X(TOKEN_NUMBER)\
    X(TOKEN_CHAR)\
    X(TOKEN_STRING)

#define CHAR_ALPHA "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"
#define CHAR_NUMERIC "1234567890"
#define CHAR_ALPHA_NUMERIC CHAR_ALPHA CHAR_NUMERIC
#define CHAR_IDENT CHAR_ALPHA_NUMERIC "_"
#define CHAR_SYMBOL "&*$#[](){}+-/^%!~<>|=:;.,?"

TOKEN_PARSER_DECL(TOKEN_IDENT) {
    return strchr(CHAR_ALPHA, *ptr) ? tokenize_while(ptr, CHAR_IDENT) : 0;
}

TOKEN_PARSER_DECL(TOKEN_SYMBOL) {
    return (ptrdiff_t) (strchr(CHAR_SYMBOL, *ptr) ? 1 : 0);
}

TOKEN_PARSER_DECL(TOKEN_NUMBER) {
    return tokenize_while(ptr, CHAR_NUMERIC);
}

TOKEN_PARSER_DECL(TOKEN_CHAR) {
    return tokenize_between_symbol(ptr, '\'');
}

TOKEN_PARSER_DECL(TOKEN_STRING) {
    return tokenize_between_symbol(ptr, '"');
}