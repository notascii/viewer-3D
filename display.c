#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "mesh.h"
#include "point.h"
#include "display.h"

GLfloat spin = 0.0f;

void init(void)
{
	glClearColor(0.6f, 0.3f, 0.3f, 0.5f);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
}

void display(void)
{
	int i = 0;
	Point p1, p2, p3;

	/* printf("display : %f %f %f\n", eye_x, eye_y, eye_z); */

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye_x, eye_y, eye_z, 0, 0, 0, 0, 0, 1);
	
	glRotatef(spin, 1.0, 0.0, 0.0);
	
	glBegin(GL_TRIANGLES);
	
	#if 0
	glColor3ub(255, 0, 0); /*face rouge*/
	glVertex3d(1, 1, 1);
	glVertex3d(1, 1, -1);
	glVertex3d(-1, 1, -1);
	glVertex3d(-1, 1, 1);
	
	glColor3ub(0, 255, 0); /*face verte*/
	glVertex3d(1, -1,  1);
	glVertex3d(1, -1, -1);
	glVertex3d(1,  1, -1);
	glVertex3d(1,  1,  1);

	glColor3ub(0, 0, 255); /*face bleue*/
	glVertex3d(-1,-1, 1);
	glVertex3d( 1,-1, 1);
	glVertex3d( 1, 1, 1);
	glVertex3d(-1, 1, 1);
	
	glColor3ub(0, 255, 255); /*face cyan*/
	glVertex3d( 1,-1, 1);
	glVertex3d(-1,-1, 1);
	glVertex3d(-1,-1,-1);
	glVertex3d( 1,-1,-1);
	
	glColor3ub(255, 0, 255); /*face magenta*/
	glVertex3d(-1,-1, 1);
	glVertex3d(-1, 1, 1);
	glVertex3d(-1, 1,-1);
	glVertex3d(-1,-1,-1);
	
	glColor3ub(255, 255, 0); /*face jaune*/
	glVertex3d(-1,-1,-1);
	glVertex3d(-1, 1,-1);
	glVertex3d( 1, 1,-1);
	glVertex3d( 1,-1,-1);
	#endif

	for (i = 0; i < mesh.nb_faces; i++) {
		/* NOTE : changer les p (de point) en v (de vertex) ou inversement */
		p1 = mesh.tab_points[mesh.tab_faces[i].v1 - 1];
		p2 = mesh.tab_points[mesh.tab_faces[i].v2 - 1];
		p3 = mesh.tab_points[mesh.tab_faces[i].v3 - 1];
		glVertex3d(p1.x, p1.y, p1.z);
		glVertex3d(p2.x, p2.y, p2.z);
		glVertex3d(p3.x, p3.y, p3.z);
		/*print_point(&p1);
		print_point(&p2);
		print_point(&p3);*/
	}

	/* printf("%p\n", (void *)mesh.tabPoint); */

    glEnd();
	
	glPopMatrix();
	glutSwapBuffers();
}

void spinDisplay(void)
{
	spin+=2.0f;
	glutPostRedisplay();
}

void reshape(int w, int h)
{
	glViewport (0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5.0,5.0,-5.0,5.0,-5.0,5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mouse(int button, int state, int x, int y)
{
	if (x+y) x=1;
	switch (button) {
		case GLUT_LEFT_BUTTON:
			if (state == GLUT_DOWN)
				glutIdleFunc(spinDisplay);
			break;
		case GLUT_RIGHT_BUTTON:
			if (state == GLUT_DOWN)
				glutIdleFunc(NULL);
			break;
		default:
			break;
	}
}