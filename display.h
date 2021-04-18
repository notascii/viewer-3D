#ifndef DISPLAY_H
#define DISPLAY_H

extern GLfloat spin;

void init(void);
void display(void);
void spinDisplay(void);
void reshape(int w, int h);
void mouse(int button, int state, int x, int y);

#endif