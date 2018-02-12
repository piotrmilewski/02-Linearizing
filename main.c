#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  c.red = MAX_COLOR;
  c.green = MAX_COLOR;
  c.blue = MAX_COLOR;

  clear_screen(s);

  //rectangular outline
  draw_line(90, 50, 250, 50, s, c);
  draw_line(250, 50, 410, 50, s, c);
  draw_line(90, 250, 250, 250, s, c);
  draw_line(250, 250, 410, 250, s, c);
  draw_line(90, 50, 90, 250, s, c);
  draw_line(410, 50, 410, 250, s, c);

  //number 6
  draw_line(110, 150, 190, 225, s, c);
  draw_line(110, 75, 190, 75, s, c);
  draw_line(110, 150, 190, 150, s, c);
  draw_line(110, 75, 110, 150, s, c);
  draw_line(190, 75, 190, 150, s, c);

  //number 9
  draw_line(210, 75, 290, 150, s, c);
  draw_line(210, 150, 290, 150, s, c);
  draw_line(210, 225, 290, 225, s, c);
  draw_line(210, 150, 210, 225, s, c);
  draw_line(290, 150, 290, 225, s, c);

  //number 4
  draw_line(310, 125, 390, 125, s, c);
  draw_line(310, 125, 370, 225, s, c);
  draw_line(370, 75, 370, 225, s, c);

  //right terminal
  draw_line( 150, 250, 150, 350, s, c);
  draw_line( 130, 350, 170, 350, s, c);
  draw_line( 130, 390, 170, 390, s, c);
  draw_line( 130, 350, 130, 390, s, c);
  draw_line( 170, 350, 170, 390, s, c);
  
  //left terminal
  draw_line( 350, 250, 350, 350, s, c);
  draw_line( 330, 350, 370, 350, s, c);
  draw_line( 330, 390, 370, 390, s, c);
  draw_line( 330, 350, 330, 390, s, c);
  draw_line( 370, 350, 370, 390, s, c);
 
  //electricity
  draw_line( 310, 370, 330, 370, s, c);
  draw_line( 170, 370, 190, 370, s, c);
  draw_line( 190, 370, 200, 380, s, c);
  draw_line( 200, 380, 220, 360, s, c);
  draw_line( 220, 360, 240, 380, s, c);
  draw_line( 240, 380, 260, 360, s, c);
  draw_line( 260, 360, 280, 380, s, c);
  draw_line( 280, 380, 300, 360, s, c);
  draw_line( 300, 360, 310, 370, s, c);
 
  display(s);
  save_extension(s, "lines.png");
}
