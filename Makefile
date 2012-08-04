CFLAGS += -g

PROGRAMS = mismatched_free already_freed_memory

all: $(PROGRAMS)

already_freed_memory: already_freed_memory.c

mismatched_free: mismatched_free.c

indent:
	indent *.c

run: $(PROGRAMS)
	for program in $(PROGRAMS); do echo $$program; ./$$program; done

clean:
	rm -f $(PROGRAMS) *.o
