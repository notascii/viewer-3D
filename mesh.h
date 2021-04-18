#ifndef MESH_H
#define MESH_H

#include "point.h"
#include "face.h"

typedef struct Mesh
{
    int nb_points;
    Point *tab_points;
    int nb_faces;
    Face *tab_faces;
} Mesh;

void read_points(FILE *pOBJfile, Mesh *pMesh);
int vertex_number(FILE *pOBJfile);
void read_faces(FILE *pOBJfile, Mesh *pMesh);
int faces_number(FILE *pOBJfile);

#endif
