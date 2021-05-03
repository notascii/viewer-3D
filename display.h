#ifndef DISPLAY_H
#define DISPLAY_H

extern GLfloat spin;
extern Mesh mesh;
extern double eye_x, eye_y, eye_z;

void init(void);
void display(void);
void spinDisplay(void);
void reshape(int w, int h);
void mouse(int button, int state, int x, int y);

#endif