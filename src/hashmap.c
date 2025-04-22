#include "hashmap.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

size_t hash(char* name,size_t size){
    unsigned long hash = 5381;
    int c;

    while ((c = *name++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return ((size_t)hash) % size;
}

hashnode_t* init_node(void* item,char* name){
    if(!item) return NULL;
    if(!strcmp("",name)) return NULL;
    hashnode_t* node = (hashnode_t*)malloc(sizeof(hashnode_t));
    node->item = item;
    node->name = name;
    node->next = NULL;
    return node;
}

hashmap_t* init_map(int size){
    if(size < 1) return NULL;
    hashnode_t** map = (hashnode_t**) malloc(sizeof(hashnode_t*)*(size_t)size);
    hashmap_t* hashmap = (hashmap_t*) malloc(sizeof(hashmap_t));
    hashmap->map = map;
    hashmap->size = (size_t)size;
    for(size_t i=0;i<(size_t)size;++i){
        hashmap->map[i] = NULL;
    }
    return hashmap;
}

int put_hashmap(hashmap_t* map,hashnode_t* node){
    if(!map) return NULL;
    if(!node) return NULL;
    size_t index = hash(node->name,map->size);
    if(map->map[index] != NULL){
        hashnode_t* past= NULL;
        hashnode_t* current = map->map[index];
        while (current!=NULL)
        {
            past=current;
            current=current->next;
        }
        past->next=node;
        return 1;
    }
    map->map[index] = node;
    return 1;
}

void* get_hashmap(hashmap_t* map, char* name){
    if(!map) return NULL;
    if(!strcmp("",name)) return NULL;
    size_t index = hash(name,map->size);
    char* node_name = map->map[index];
    if(!strcmp(node_name,name)){
        hashnode_t* current = map->map[index];
        while (current!=NULL && strcmp(current->name,name))
        {
            current=current->next;
        }
        return current->item;
    }
    return map->map[index]->item;
}

hashnode_t* destroy_node(hashnode_t* node){
    if(node==NULL) return NULL;
    destroy_node(node->next);
    free(node->item);
    free(node);
    return NULL;
}

int destroy_hashmap(hashmap_t* map){
    if(!map) return NULL;
    for(size_t i=0;i<map->size;++i){
        if(map->map!=NULL){
            destroy_node(map->map[i]);
        }
    }
    free(map->map);
    free(map);
    return 1;
}

int del_node(hashmap_t* map,char* name){
    size_t index = hash(name,map->size);
    hashnode_t* past = NULL;
    hashnode_t* current = map->map[index];
    if(current == NULL) return 0;
    if(!strcmp(name,current->name)){
        map->map[index] = current->next;
        if(current->next != NULL) {
            current->next = NULL;
            destroy_node(current);
        }
        return 1;
    }
    while (current->next != NULL && strcmp(current->name,name))
    {
        past=current;
        current=current->next;
    }
    if(strcmp(name,current->name)) return 0;
    past->next = current->next;
    if(current->next != NULL) {
        current->next = NULL;
        destroy_node(current);
    }
    return 1;
}

