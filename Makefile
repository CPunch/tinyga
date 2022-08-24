# make clean && make && ./bin/tinyga

CC=clang
CFLAGS=-fPIE -Wall -O3 -Isrc -std=c89
LDFLAGS=-lm #-fsanitize=address
OUT=bin/tinyga

CHDR=\
	src/tinyga.h\

CSRC=\
	src/tinyga.c\
	src/main.c\

COBJ=$(CSRC:.c=.o)

.c.o:
	$(CC) -c $(CFLAGS) $< -o $@

$(OUT): $(COBJ) $(CHDR)
	mkdir -p bin
	$(CC) $(COBJ) $(LDFLAGS) -o $(OUT)

clean:
	rm -rf $(COBJ) $(OUT)
