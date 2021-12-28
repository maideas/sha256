
C_FILES  = main.c
C_FILES += sha256.c
C_FILES += sha256_bit_func.c
C_FILES += sha256_debug.c

all: build
	./main

build:
	gcc -Wall -I. -o main $(C_FILES)

clean:
	-rm -f main

