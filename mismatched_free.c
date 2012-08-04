/* Example program which allocates memory and fails to free it */

#include <assert.h>
#include <stdlib.h>

int main(void)
{
  int *i = malloc(sizeof(int));
  assert(i != 0);
  /* free(i); */
  return 0;
}
