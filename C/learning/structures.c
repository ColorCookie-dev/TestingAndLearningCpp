#include <stdio.h>

struct point {
  int x;
  int y;
};

typedef struct {
  int x;
  int y;
} cool_point;


void move_cool_point(cool_point *p) {
  (*p).x++;
  (*p).y++;
}

int main() {

  struct point p;                 // struct name is used
  cool_point cool_p;             // no struct key word is used


  p.x = 5;
  p.y = 10;

  cool_p.x = 5;
  cool_p.y = 6;

  struct point p2;
  p2.x = 34;
  p2.y = 123;

  move_cool_point(&cool_p);

  printf("point 1 :-  %d  %d\n", p.x, p.y);
  printf("point 2 :-  %d  %d\n", p2.x, p2.y);

  printf("Cool Point 1 :-  %d  %d\n", cool_p.x, cool_p.y);
}
