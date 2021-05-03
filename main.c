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

double eye_x, eye_y, eye_z;
Mesh mesh;

int main(int argc, char **argv)
{
    char title[10] = "Viewer 3D";
    
    /* int i = 0; */
    FILE *pfile = NULL;

    eye_x = strtod(argv[2], NULL);
    eye_y = strtod(argv[3], NULL);
    eye_z = strtod(argv[4], NULL);

    printf("main : %f %f %f\n", eye_x, eye_y, eye_z);

    pfile = fopen(argv[1], "r");

    if (pfile == NULL) {
        printf("error: NULL pointer\n");
        return (-1);
    }

    mesh.nb_points = vertex_number(pfile);
    mesh.tab_points = (Point *)malloc(mesh.nb_points * sizeof(Point));
    mesh.nb_faces = faces_number(pfile);
    mesh.tab_faces = (Face *)malloc(mesh.nb_faces * sizeof(Face));

    read_points(pfile, &mesh);
    read_faces(pfile, &mesh);

    #if 0
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
    #endif

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

    fclose(pfile);
    free(mesh.tab_points);

    return (0);
}
