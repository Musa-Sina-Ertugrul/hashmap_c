#include "hashmap.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_second(hashnode_t* node){
    if(node->next==NULL) return 1;
    return 0;
}

int main(){
    hashnode_t* node_1 = init_node(malloc(sizeof(char)),"test");
    hashnode_t* node_2 = init_node(malloc(sizeof(char)),"test");
    hashmap_t* map = init_map(11);
    put_hashmap(map,node_1);
    put_hashmap(map,node_2);
    assert(map->map[6]!=NULL);
    assert(map->map[6]->next!=NULL);
    assert(check_second(map->map[6]->next));
    printf("put test passed\n");
    free(node_1->item);
    free(node_2->item);
    free(node_1);
    free(node_2);
    free(map->map);
    free(map);
}