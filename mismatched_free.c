/* Example program which allocates memory and fails to free it */

#include <assert.h>
#include <stdlib.h>

#define CONSTANT 32

int main(void)
{
  int *i_ptr = malloc(sizeof(int));
  assert(i_ptr != 0);
  *i_ptr = CONSTANT;
  assert(*i_ptr == CONSTANT);
  /* free(i_ptr); */
  return 0;
}
