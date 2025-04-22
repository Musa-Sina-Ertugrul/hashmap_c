#include "hashmap.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    hashnode_t* node_1 = init_node(malloc(sizeof(char)),"test");
    hashnode_t* node_2 = init_node(malloc(sizeof(char)),"test");
    hashnode_t* node_3 = init_node(malloc(sizeof(char)),"test");
    hashmap_t* map = init_map(1);
    put_hashmap(map,node_1);
    put_hashmap(map,node_2);
    put_hashmap(map,node_3);
    assert(destroy_hashmap(map));
    printf("destroy test passed\n");
    return 0;
}