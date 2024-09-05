/*******
* Read input from STDIN
* Use: printf(...) or fprintf( stdout, ...) to output your result to stdout.
* Use: fprintf(stderr, ...);  to output debugging information to stderr.
* ***/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include "libisograd.h"

typedef struct {
	char n[4];
	int f;
	int p;
	int r;
} line;

line *calculate(line *current, line *best) {
  if (best == NULL)
    return current;
  int best_calculated = best->f * (best->p + best->r);
  int current_calculated = current->f * (current->p + current->r);
  if (current_calculated < best_calculated) {
    free(best);
    return current;
  }
  return best;
}

int main() {
  char *s = malloc(1024);

  line *best = NULL;
  line *current = NULL;

  int i = 0;

  while (scanf("%s", s) != EOF) {
    switch (i) {
      case 0:
	current = malloc(sizeof(line));
	strcpy(current->n, s);
	break;
      case 1:
	current->f = atoi(s);
	break;
      case 2:
	current->p = atoi(s);
	break;
      case 3:
	current->r = atoi(s);
	break;
      default:
	return EXIT_FAILURE;
    }
    i = (i + 1) % 4;
    if (i == 0)
      best = calculate(current, best);
  }

  printf("%s\n", best->n);

  if (best == current)
    free(best);
  else {
    free(best);
    free(current);
  }
  free(s);

  return EXIT_SUCCESS;
}
