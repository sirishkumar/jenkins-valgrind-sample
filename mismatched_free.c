/* Example program which allocates memory and fails to free it */

#include <stdlib.h>

#define CONSTANT 32

int main(void)
{
  int *i_ptr = malloc(sizeof(int));

  *i_ptr = CONSTANT;

  /* free(i_ptr); */
  return 0;
}
