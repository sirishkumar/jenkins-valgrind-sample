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
illegal_free_from_heap_inside_allocated_region (void)
{
  void *p = malloc (80);
  free (p + 8);			/* Freeing an address inside an allocated region */
}

/* ------------------------------------------------------------------------ */

static void
illegal_free_from_heap_outside_allocated_region (void)
{
  void *p = malloc (80);
  free (p - 4);			/* Freeing an address inside an allocated region */
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
  /* Memory allocated in this function is not freed before function exit */
}

/* ------------------------------------------------------------------------ */

int
main (void)
{
  illegal_free_from_stack ();
  illegal_free_from_heap_inside_allocated_region ();
  illegal_free_from_heap_outside_allocated_region ();
  leak_memory ();
  return 0;
}
