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

#define PI 3.14159265358979323846

typedef struct {
  int x;
  int y;
} Point;

typedef struct {
	Point centre;
	double rayon;
} Cercle;

Cercle two_points(Point a, Point b) {
	Point centre = {(a.x+b.x)/2, (a.y+b.y)/2};
	double rayon = ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))/4;
	return (Cercle){centre, rayon};
}

Cercle three_points(Point a, Point b, Point c) {
	double x12 = a.x-b.x;
	double x13 = a.x-c.x;
	double y12 = a.y-b.y;
	double y13 = a.y-c.y;
	double y31 = c.y-a.y;
	double y21 = b.y-a.y;
	double x31 = c.x-a.x;
	double x21 = b.x-a.x;
	double sx13 = a.x*a.x-c.x*c.x;
	double sy13 = a.y*a.y-c.y*c.y;
	double sx21 = b.x*b.x-a.x*a.x;
	double sy21 = b.y*b.y-a.y*a.y;
	double X = -(sx13*y12+sy13*y12+sx21*y13+sy21*y13)/(2*(x31*y12-x21*y13));
	double Y = -(sx13*x12+sy13*x12+sx21*x13+sy21*x13)/(2*(y31*x12-y21*x13));
	double center = - a.x*a.x - a.y*a.y + 2*X*a.x + 2*Y*a.y;
	double r_squared = X*X + Y*Y - center;
	return (Cercle){{X, Y}, r_squared};
}

Cercle three_points_or_less(Point *points, int nb_points) {
	if (nb_points == 0)
		return (Cercle){{0, 0}, 0};
	if (nb_points == 1)
		return (Cercle){points[0], 0};
	if (nb_points == 2)
		return two_points(points[0], points[1]);
	return three_points(points[0], points[1], points[2]);
}

Cercle welzl(Point *points, int nb_points, Point *cercle, int nb_cercle) {
	if (nb_points == 0 || nb_cercle == 3)
		return three_points_or_less(cercle, nb_cercle);
	Point p = points[nb_points-1];
	Cercle c = welzl(points, nb_points-1, cercle, nb_cercle);
	if (((p.x-c.centre.x)*(p.x-c.centre.x)+(p.y-c.centre.y)*(p.y-c.centre.y)) <= c.rayon)
		return c;
	nb_cercle++;
	cercle = realloc(cercle, nb_cercle * sizeof(Point));
	cercle[nb_cercle-1] = p;
	return welzl(points, nb_points-1, cercle, nb_cercle);
}

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

	Cercle c = welzl(points, nb_points, NULL, 0);

  printf("%.5f\n", PI * c.rayon);

  return EXIT_SUCCESS;
}

