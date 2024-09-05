/*******
* Read input from STDIN
* Use: printf(...) or fprintf( stdout, ...) to output your result to stdout.
* Use: fprintf(stderr, ...);  to output debugging information to stderr.
* ***/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
// #include "libisograd.h"

#define PI 3.14159

typedef struct {
  int x;
  int y;
} Point;

int main() {
  char *s = malloc(1024);
  
  int i = 0;
  int nb_points = 0;
  Point *points = NULL;

  while (scanf("%s", s) != EOF) {
    if (i == 0) {
      nb_points = atoi(s);
      points = malloc(nb_points * sizeof(Point));
    } else
				if (i%2)
					points[(i-1)/2].x = atoi(s);
				else
					points[(i-1)/2].y = atoi(s);
		i++;
	}
  free(s);

  printf("%.5f\n", PI * rayon);

  return EXIT_SUCCESS;
}

