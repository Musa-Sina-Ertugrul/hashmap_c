#include "hashmap.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    hashnode_t* node_1 = init_node(malloc(sizeof(char)),"test_1");
    hashnode_t* node_2 = init_node(malloc(sizeof(char)),"test_2");
    hashnode_t* node_3 = init_node(malloc(sizeof(char)),"test_3");
    hashmap_t* map = init_map(1);
    put_hashmap(map,node_1);
    put_hashmap(map,node_2);
    put_hashmap(map,node_3);
    assert(del_node(map,"test_2"));
    assert(!del_node(map,"test_4"));
    assert(del_node(map,"test_3"));
    assert(del_node(map,"test_1"));
    assert(map->map[0]==NULL);
    printf("del test passed\n");
    return 0;
}