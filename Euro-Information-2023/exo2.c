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
  char src[6];
  char dest[6];
} link_t;

void add_server(char **servers, int *nb_servers, char *server) {
  // check if server already exists
  for (int i = 0; i < *nb_servers; i++)
    if (strcmp(servers[i], server) == 0)
      return;	
  strcpy(servers[*nb_servers], server);
  *nb_servers += 1;
}

void free_all(char **servers, int m1, link_t *links) {
  for (int i = 0; i < m1; i++)
    free(servers[i]);
  free(servers);
  free(links);
}

int main() {
  char *s = malloc(1024);

  int m1;
  int m2;

  int i = 0;

  char **servers;
  int nb_servers = 0;
  link_t *links;

  while (scanf("%s", s) != EOF) {
    switch(i) {
      case 0:
	m1 = atoi(s);
	servers = malloc(m1 * sizeof(char *));
	for (int j = 0; j < m1; j++) {
	  servers[j] = malloc(6);
	}
	break;
      case 1:
	m2 = atoi(s);
	links = malloc(m2 * sizeof(link_t));
	break;
      default:
	add_server(servers, &nb_servers, s);
	if ((i%2) == 0)
	  strcpy(links[i/2-1].src, s);
	else
	  strcpy(links[i/2-1].dest, s);
	break;
    }
    i++;
  }
  free(s);

  for (int i = 0; i < nb_servers; i++) {
    char *name_server = servers[i];
    char *name_server_dest;
    int nb_links = 0;
    int nb_links_dest = 0;
    for (int j = 0; j < m2; j++)
      if (strcmp(links[j].src, name_server) == 0)
	nb_links++;
    if (nb_links == 1) {
      for (int j = 0; j < m2; j++)
	if (strcmp(links[j].src, name_server) == 0)
	  name_server_dest = links[j].dest;
      for (int j = 0; j < m2; j++)
	if (strcmp(links[j].src, name_server_dest) == 0)
	  nb_links_dest++;
      if (nb_links_dest == (m1-2)) {
	printf("%s\n", name_server);
	free_all(servers, m1, links);
	return EXIT_SUCCESS;
      }
    }
  }
  return EXIT_FAILURE;
}
