/*******
* Read input from STDIN
* Use: printf(...) or fprintf( stdout, ...) to output your result to stdout.
* Use: fprintf(stderr, ...);  to output debugging information to stderr.
* ***/
#include <stdlib.h>
#include <stdio.h>
// #include "libisograd.h"

int main() {
  char *s = malloc(1024);

  int i = 0;

  while (scanf("%s", s) != EOF) {
  }
  free(s);

  return EXIT_SUCCESS;
}
