#compiler flags
CFLAGS=-g -O3

# first target is built by default
all: tokenizer

# include file dependencies
history.o : history.h history.c
tokenizer.o: tokenizer.h tokenizer.c
uimain.o: tokenizer.h uimain.c

# $@=target, $^=prerequisites
tokenizer: history.o tokenizer.o uimain.o
	cc -o $@ $^ $(CFLAGS)

# deletes files generated by compilation
clean:
	rm -f *.o *.h~ *.c~ tokenizer

run: 
	./tokenizer
