/* Example program which allocates memory and fails to free it */

#include <stdlib.h>

#define CONSTANT 32

int
main (void)
{
  int *i_ptr = malloc (sizeof (int));
  const char *s = "A string on the stack";

  *i_ptr = CONSTANT;

  /* free(i_ptr); */
  free ((void *) s);		/* Freeing a string on the stack */
  return 0;
}
