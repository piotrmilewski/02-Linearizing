#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

void flip_line(int *x0, int *y0, int *x1, int *y1){
  int xtmp = *x0;
  int ytmp = *y0;
  *x0 = *x1;
  *y0 = *y1;
  *x1 = xtmp;
  *y1 = ytmp;
}

//octant 1
void draw_octant1(int x0, int y0, int x1, int y1, screen s, color c, int a, int b){
  int d = (2 * a) + b;
  while (x0 <= x1){
    plot(s, c, x0, y0);
    if (d > 0){
      y0++;
      d += (2 * b);
    }
    x0++;
    d += (2 * a);
  }
}

//octant 2
void draw_octant2(int x0, int y0, int x1, int y1, screen s, color c, int a, int b){
  int d = a + (2 * b);
  while (y0 <= y1){
    plot(s, c, x0, y0);
    if (d < 0){
      x0++;
      d += (2 * a);
    }
    y0++;
    d += (2 * b);
  }
}

//octant 7
void draw_octant7(int x0, int y0, int x1, int y1, screen s, color c, int a, int b){
  int d = a - (2 * b);
  while (y0 <= y1){
    plot(s, c, x0, y0);
    if (d > 0){
      x0++;
      d += (2 * a);
    }
    y0--;
    d -= (2 * b);
  }
}

//octant 8
void draw_octant8(int x0, int y0, int x1, int y1, screen s, color c, int a, int b){
  int d = (2 * a) - b;
  while (x0 <= x1){
    plot(s, c, x0, y0);
    if (d < 0){
      y0--;
      d -= (2 * b);
    }
    x0++;
    d += (2 * a);
  }
}

//Line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  //ensure line is drawn from left to right
  if (x0 > x1)
    flip_line(&x0, &y0, &x1, &y1);
  //set A, -B, and slope
  int a = y1 - y0; //change in y
  int b = -(x1 - x0); //negated change in x
  float m = ((float) a)/(-b); //slope
  //execute proper octant function
  if (m <= 1 && m > 0)
    draw_octant1(x0, y0, x1, y1, s, c, a, b);
  else if (m > 1)
    draw_octant2(x0, y0, x1, y1, s, c, a, b);
  else if (m < -1)
    draw_octant7(x0, y0, x1, y1, s, c, a, b);
  else
    draw_octant8(x0, y0, x1, y1, s, c, a, b);
}
