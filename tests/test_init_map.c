#include "hashmap.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_init(hashmap_t* hashmap){

    for(size_t i=0;i<hashmap->size;++i){
        if (hashmap->map[i] != NULL){
            return 0;
        }
    }
    return 1;
}

int main(){
    hashmap_t* hashmap = init_map(11);
    assert(hashmap->map!=NULL);
    assert(hashmap->size==(size_t)11);
    assert(check_init(hashmap));
    printf("init_map test passed\n");
    free(hashmap->map);
    free(hashmap);
    return 0;
}
