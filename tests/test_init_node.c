#include "hashmap.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    hashnode_t* node = init_node(calloc((size_t)1,sizeof(char)),"test");
    assert(!strcmp(node->name,"test"));
    size_t test_size = sizeof(node->item);
    assert(test_size==sizeof(char*));
    assert(node->next==NULL);
    assert(node->item!=NULL);
    printf("init_node test passed\n");
    free(node->item);
    free(node);
    return 0;
}