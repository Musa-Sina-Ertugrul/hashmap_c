#include "hashmap.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char* test_bucket = (char*)malloc(sizeof(char));
    test_bucket[0] = 't';
    hashnode_t* node_1 = init_node(test_bucket,"test_1");
    hashnode_t* node_2 = init_node(test_bucket,"test_2");
    hashmap_t* map = init_map(11);
    put_hashmap(map,node_1);
    put_hashmap(map,node_2);
    char* test_1 = (char*)get_hashmap(map,"test_1");
    char* test_2 = (char*)get_hashmap(map,"test_2");
    assert(test_1[0]=='t');
    assert(test_2[0]=='t');
    printf("get test passed\n");
    free(node_1->item);
    free(node_1);
    free(node_2);
    free(map->map);
    free(map);

}