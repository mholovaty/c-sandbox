CC=gcc
CFLAGS=-Wall -Werror -ggdb -O0
LDFLAGS=

GLIB_CFLAGS=$(shell pkg-config --libs glib-2.0)
GLIB_LDFLAGS=$(shell pkg-config --cflags glib-2.0)

.PHONY: all
all: sizes fisqrt ex-gslist-1 echo cat

clean:
	rm -f *.exe

sizes: sizes.c
	$(CC) -o sizes sizes.c $(CFLAGS) $(LDFLAGS)

fisqrt: fisqrt.c
	$(CC) -o fisqrt fisqrt.c $(CFLAGS) $(LDFLAGS)

ex-gslist-1: ex-gslist-1.c
	$(CC) -o ex-gslist-1 ex-gslist-1.c \
	$(CFLAGS) $(LDFLAGS) $(GLIB_CFLAGS) $(GLIB_LDFLAGS)

echo: echo.c
	$(CC) -o echo echo.c $(CFLAGS) $(LDFLAGS)

cat: cat.c
	$(CC) -o cat cat.c $(CFLAGS) $(LDFLAGS)
