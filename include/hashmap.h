
#ifndef __HASHMAP_H__
#define __HASHMAP_H__

#include <stddef.h>

typedef struct 
{
    void* item;
    char* name;
    struct hashnode_t* next;
}hashnode_t;


typedef struct 
{
    hashnode_t** map;
    size_t size;
}hashmap_t;

size_t hash(char* name,size_t size);
hashnode_t* init_node(void* item,char* name);
hashmap_t* init_map(int size);
int put_hashmap(hashmap_t* map,hashnode_t* node);
void* get_hashmap(hashmap_t* map, char* name);
hashnode_t* destroy_node(hashnode_t* node);
int destroy_hashmap(hashmap_t* map);
int del_node(hashmap_t* map,char* name);

#endif