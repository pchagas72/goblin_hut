#include "../dataStructures/matrix/matrix.h"
#include "../tilemap/tilemap.h"
#include <stdio.h>
#include <SDL2/SDL.h>


int main(){
    struct tilemap map; 
    map.width = 9;
    map.height = 6;
    map.mapMatrix = create_matrix(map.height, map.width);
    for (int i = 0; i < map.height; i++){
        for (int j = 0; j < map.width; j++){
            if (j == 0 || j == 8 || i == 0 || i == 5){
                map.mapMatrix->content[i][j] = TREE;
            } else{
                map.mapMatrix->content[i][j] = GRASS;
            }
        }
    }
    for (int i = 0; i < map.height; i++){
        for (int j = 0; j < map.width; j++){
            if (j == map.width-1) {
                printf("%d\n", map.mapMatrix->content[i][j]);
            } else{
                printf("%d", map.mapMatrix->content[i][j]);
            }
        }
    }
}
