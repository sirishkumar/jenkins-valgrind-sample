/* Example program which accesses uninitialized memory */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 80

#define TEST_STRING "A test?"

/* ------------------------------------------------------------------------ */

static void
access_uninitialized_int (void)
{
  int *i_ptr = malloc (sizeof (int));
  char *s = "some space on the stack";
  sprintf (s, "%d", i_ptr);	/* Reads the contents of uninitialized i_ptr */
  free (i_ptr);
}

/* ------------------------------------------------------------------------ */

int
main (void)
{
  access_uninitialized_int ();
  return 0;
}
