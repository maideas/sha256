
C_FILES  = main.c
C_FILES += sha256.c
C_FILES += sha256_bit_func.c
C_FILES += sha256_debug.c

.PHONY: all build clean examples compare

all: build
	./main

build: clean
	gcc -std=c99 -Wall -I. -o main $(C_FILES)

clean:
	-rm -f main

# reference examples ...
examples:
	# -----------------------------------------
	echo -n "" | sha256sum
	# -----------------------------------------
	echo -n "abc" | sha256sum
	# -----------------------------------------
	echo -n "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq" | sha256sum
	# -----------------------------------------
	echo -n "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq1234567" | sha256sum
	# -----------------------------------------
	echo -n "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq12345678" | sha256sum
	# -----------------------------------------
	echo -n "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq123456789" | sha256sum
	# -----------------------------------------

# visual compare ...
compare: examples build
	./main | grep digest

