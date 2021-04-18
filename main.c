#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "mesh.h"
#include "point.h"
#include "face.h"
#include "display.h"

/* 
LISTER LES FONCTIONS DE CHAQUE MODULE :
- fonctions de point.c
- fonctions de mesh.c */


int main(int argc, char **argv)
{
    char title[10] = "App";
    
    int i = 0;
    FILE *pf_cube = NULL;

    pf_cube = fopen("pyramide.obj", "r");

    mesh.nb_points = vertex_number(pf_cube);
    mesh.tab_points = (Point *)malloc(mesh.nb_points * sizeof(Point));
    mesh.nb_faces = faces_number(pf_cube);
    mesh.tab_faces = (Face *)malloc(mesh.nb_faces * sizeof(Face));


    read_points(pf_cube, &mesh);
    read_faces(pf_cube, &mesh);

    printf("Nombre de vertex dans le fichier : %d\n", mesh.nb_points);
    for (i = 0; i < mesh.nb_points; i++) {
        printf("point %d ", i);
        print_point(&mesh.tab_points[i]);
    }
    printf("\nNombre de faces dans le fichier : %d\n", mesh.nb_faces);
    for (i = 0; i < mesh.nb_faces; i++) {
        printf("face %d ", i);
        print_face(&mesh.tab_faces[i]);
    }

    /* printf("%p\n", (void *)mesh.tabPoint); */

    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(200, 200);
	glutCreateWindow(title);
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);

	glutMainLoop();

    fclose(pf_cube);
    free(mesh.tab_points);

    return (0);
}
