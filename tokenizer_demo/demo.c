#include "log.h"
#include "fio.h"
#include "tokenizer.h"

int main(int argc, char* argv[]) {
    if(argc != 2) LOG(LOG_ERROR, "Must provide source file (try fizzbuzz.c).");
    const char* program = read_file_contents(argv[1]);
    if(!program) LOG(LOG_ERROR, "Unable to find file at %s.", argv[1]);

    const struct token* tokens = tokenize(program, true);

    free_tokens(tokens);
    free((char*) program);

    return 0;
}