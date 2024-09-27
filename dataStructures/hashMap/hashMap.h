

#ifndef HASHMAP_H
#define HASHMAP_H

struct hash_entry{
    char *key;
    int value;
    struct hash_entry *next; // Points to the next entry
};

struct hash_map{
    struct hash_entry **table; // Fuck ton of entries
    int size;
};

unsigned int hash(char* key,struct hash_map *hashmap);

#endif
