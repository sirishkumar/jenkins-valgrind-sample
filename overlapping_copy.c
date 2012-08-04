/* Example program which copies overlapping memory regions with memcpy */

#include <stdlib.h>
#include <string.h>

/* ------------------------------------------------------------------------ */

static void
overlapping_copy (void)
{
  void *a1 = malloc (37);
  void *a2 = a1 + 7;
  int i;
  memset (a1, 0, 17);		/* Initialize source region */
  for (i = 0; i < 8; i++)
    {
      memcpy (a1, a2, 10 + i);	/* Source and destination regions overlap */
    }
  free (a1);
}

/* ------------------------------------------------------------------------ */

int
main (void)
{
  overlapping_copy ();
  return 0;
}
