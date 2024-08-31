/*******
* Read input from STDIN
* Use: printf(...) or fprintf( stdout, ...) to output your result to stdout.
* Use: fprintf(stderr, ...);  to output debugging information to stderr.
* ***/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
// #include "libisograd.h"

// PPCM for n numbers
int ppcm(int *tab, int n) {
  bool found = false;
  int i = 0;
  while (!found) {
    i++;
    found = true;
    for (int j = 0; j < n; j++) {
      if (i % tab[j] != 0) {
	found = false;
	break;
      }
    }
  }
  return i;
}

int main() {
  char *s = malloc(1024);

  int nb_machines;
  int *tab;
  int *tab_res;

  int i = 0;
  while (scanf("%s", s) != EOF) {
    if (i == 0) {
      nb_machines = atoi(s);
      tab = malloc(nb_machines * sizeof(int));
      tab_res = malloc(nb_machines * sizeof(int));
    } else
	tab[i - 1] = atoi(s);
    i++;
  }
  free(s);

  int actual_ppcm = ppcm(tab, nb_machines);
  for (int i = 0; i < nb_machines; i++) {
    tab[i]++;
    tab_res[i] = ppcm(tab, nb_machines);
    tab[i]--;
  }

  // find max
  int max = 0;
  int index = -1;
  for (int i = 0; i < nb_machines; i++) {
    if (tab_res[i] > max) {
      max = tab_res[i]; 
      index = i;
    }
  }

  if (max > actual_ppcm) {
    printf("%d\n", index);
  } else {
    printf("%d\n", -1);
  }

  free(tab);
  free(tab_res);

  return EXIT_SUCCESS;
}
