#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include "mesh.h"
#include "point.h"

#define MAX_LINE_LEN 100

void read_points(FILE *pOBJfile, Mesh *pMesh)
{
    Point point;
    int r = 0;
    int i = 0;

    char line[MAX_LINE_LEN];

    if (pOBJfile == NULL) {
        printf("(1) error : NULL pointer\n");
        exit(EXIT_FAILURE);
    }

     while (fgets(line, MAX_LINE_LEN, pOBJfile) != NULL) {
       r = sscanf(line, "v %lf %lf %lf", &point.x, &point.y, &point.z);
        if ((r == 3) && (i < pMesh->nb_points)) {
            pMesh->tab_points[i].x = point.x;
            pMesh->tab_points[i].y = point.y;
            pMesh->tab_points[i].z = point.z;
            i++;
        }
    }

    /* on se replace au début du fichier pour de futurs appels à la fonction read */
    rewind(pOBJfile);
}

int vertex_number(FILE *pOBJfile)
{
    int r = 0;
    int nb_of_vertex = 0;
    char line[MAX_LINE_LEN];
    Point point;

    while (fgets(line, MAX_LINE_LEN, pOBJfile) != NULL) {
        r = sscanf(line, "v %lf %lf %lf", &point.x, &point.y, &point.z);
        if (r == 3) {
            nb_of_vertex++;
        }
    }
    rewind(pOBJfile);

    return (nb_of_vertex);
}

void read_faces(FILE *pOBJfile, Mesh *pMesh)
{
    int r = 0;
    int i = 0;
    Face face;

    char line[MAX_LINE_LEN];

    if (pOBJfile == NULL) {
        printf("(1) error : NULL pointer\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_LEN, pOBJfile) != NULL) {
        r = sscanf(line, "f %d %d %d", &face.v1, &face.v2, &face.v3);
        if ((r == 3) && (i < pMesh->nb_faces)) {
            pMesh->tab_faces[i].v1 = face.v1;
            pMesh->tab_faces[i].v2 = face.v2;
            pMesh->tab_faces[i].v3 = face.v3;
            i++;
        }
    }

    /* on se replace au début du fichier pour de futurs appels à la fonction read */
    rewind(pOBJfile);
}

int faces_number(FILE *pOBJfile)
{
    int r = 0;
    int nb_of_faces = 0;
    char line[MAX_LINE_LEN];
    Face face;

    while (fgets(line, MAX_LINE_LEN, pOBJfile) != NULL) {
        r = sscanf(line, "f %d %d %d", &face.v1, &face.v2, &face.v3);
        if (r == 3) {
            nb_of_faces++;
        }
    }
    rewind(pOBJfile);

    return (nb_of_faces);
}