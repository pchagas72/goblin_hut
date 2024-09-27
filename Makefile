game:
	gcc -o game main.c player/player.c tilemap/tilemap.c textureManager/textureManager.c objects/tree/tree.c dataStructures/matrix/matrix.c objects/grass/grass.c -lSDL2
