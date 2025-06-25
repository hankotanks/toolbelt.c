CC := gcc

ROOT := $(dir $(dir $(CURDIR)))

CFLAGS := -I$(ROOT)common -I$(ROOT)tokenizer -isystem$(ROOT)ext 

all: demo.o tokenizer.o
	$(CC) -o demo $^

demo.o:
	$(CC) $(CFLAGS) -c demo.c -o $@

tokenizer.o:
	$(CC) $(CFLAGS) -c $(ROOT)tokenizer/tokenizer.c -o $@ '-DTOKENS="../tokenizer_demo/demo_tokens.h"'