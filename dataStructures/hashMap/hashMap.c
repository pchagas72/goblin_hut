

#include "./hashMap.h"

unsigned int hash(char* key,struct hash_map *hashmap){
    unsigned long int hashval = 0;
    while (*key){
        hashval = (hashval << 5) + *key;
        key++;
    }
    return hashval % hashmap->size;
}
