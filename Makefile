CC=gcc
CFLAGS=-Wall -Werror -ggdb
LDFLAGS=

.PHONY: all
all: sizes fisqrt ex-gslist-1 echo

clean:
	rm -f sizes fisqrt ex-gslist-1

sizes: sizes.c
	$(CC) -o sizes sizes.c $(CFLAGS) $(LDFLAGS)

fisqrt: fisqrt.c
	$(CC) -o fisqrt fisqrt.c $(CFLAGS) $(LDFLAGS)

ex-gslist-1: ex-gslist-1.c
	$(CC) -o ex-gslist-1 ex-gslist-1.c \
	$(CFLAGS) \
	$(LDFLAGS) \
	$(shell pkg-config --libs glib-2.0) \
	$(shell pkg-config --cflags glib-2.0)

echo: echo.c
	$(CC) -o echo echo.c $(CFLAGS) $(LDFLAGS)
