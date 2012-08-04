CFLAGS += -g

PROGRAMS = mismatched_free

all: indent $(PROGRAMS)

mismatched_free: mismatched_free.c

indent:
	indent *.c

clean:
	rm -f $(PROGRAMS) *.o
