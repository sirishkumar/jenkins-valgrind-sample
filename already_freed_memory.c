/* Example program which access memory that was already freed */

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define TEST_STRING "A test string"

/* ------------------------------------------------------------------------ */

static void
access_already_freed_memory (void)
{
  char *s = malloc (80);
  strcpy (s, TEST_STRING);
  assert (!strcmp (s, TEST_STRING));
  free ((void *) s);
  strcpy (s, "");		/* Assigning to already freed memory */
}

/* ------------------------------------------------------------------------ */

int
main (void)
{
  access_already_freed_memory ();
  return 0;
}
