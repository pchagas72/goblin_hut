

#ifndef TILEMAP_H
#define TILEMAP_H

#include "../dataStructures/matrix/matrix.h"

struct tilemap{
    int width;
    int height;
    struct matrix map;
};

void render();

#endif
