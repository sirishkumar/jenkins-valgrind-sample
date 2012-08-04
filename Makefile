CFLAGS += -g

PROGRAMS = already_freed_memory illegal_system_calls mismatched_free overlapping_copy uninitialized_memory

all: $(PROGRAMS)
	for program in $(PROGRAMS); do cp $$program valgrind_$$program; done

already_freed_memory: already_freed_memory.c

illegal_system_calls: illegal_system_calls.c

mismatched_free: mismatched_free.c

overlapping_copy: overlapping_copy.c

uninitialized_memory: uninitialized_memory.c

indent:
	indent *.c

cppcheck:
	cppcheck *.c

run: $(PROGRAMS)
	for program in $(PROGRAMS); do echo $$program; ./$$program; done

clean:
	rm -f $(PROGRAMS) *.o *~ valgrind_*
