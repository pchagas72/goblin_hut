#ifndef OBJECT_IDS_H
#define OBJECT_IDS_H

struct tile_type{
    const int ID;
    const char* sprite;
};

#define GRASS 0
#define GRASS_TEXTURE "./sprites/grass.bmp"
#define TREE 1
#define TREE_TEXTURE "./sprites/tree.bmp"

#endif
