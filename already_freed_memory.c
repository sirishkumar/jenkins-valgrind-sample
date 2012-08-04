/* Example program which access memory that was already freed */

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define TEST_STRING "A test string that is longer than 12 bytes"

/* ------------------------------------------------------------------------ */

static void
access_already_freed_memory (void)
{
  char *s = malloc (80);
  strcpy (s, TEST_STRING);
  assert (!strcmp (s, TEST_STRING));
  free ((void *) s);
  strcpy (s, "");		/* Assigning to already freed memory */
  strcpy (s + 1, TEST_STRING);	/* Assigning to already freed memory */
  memcpy (s + 3, TEST_STRING, 12);	/* Assigning to already freed memory */
}

/* ------------------------------------------------------------------------ */

int
main (void)
{
  access_already_freed_memory ();
  return 0;
}
