/* Example program which copies overlapping memory regions with memcpy */

#include <stdlib.h>
#include <string.h>

/* ------------------------------------------------------------------------ */

static void
overlapping_copy (void)
{
  void *a1 = malloc (17);
  void *a2 = a1 + 7;
  memset (a1, 0, 17);
  memcpy (a1, a2, 10);		/* Source and destination regions overlap */
  free(a1);
}

/* ------------------------------------------------------------------------ */

int
main (void)
{
  overlapping_copy ();
  return 0;
}
