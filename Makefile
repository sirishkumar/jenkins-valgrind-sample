CFLAGS+=-g

all: mismatched_free

mismatched_free: mismatched_free.c

clean:
	rm -f mismatched_free *.o
