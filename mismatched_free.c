/* Example program which allocates memory and fails to free it */

#include <stdlib.h>
#include <string.h>

#define CONSTANT 32

/* ------------------------------------------------------------------------ */

static void
illegal_free_from_stack (void)
{
  const char *s = "A string on the stack";
  free ((void *) s);		/* Freeing a string on the stack */
}

/* ------------------------------------------------------------------------ */

static void
leak_memory (void)
{
  int *i_ptr = malloc (sizeof (int));
  double *d_ptr = malloc (sizeof (double));
  char *s = malloc (80);
  *i_ptr = 1234;
  *d_ptr = 1.234e-5;
  strcpy (s, "leak_memory function wrote this");
}

/* ------------------------------------------------------------------------ */

int
main (void)
{
  leak_memory();
  illegal_free_from_stack();
  return 0;
}
