#include "hashmap.h"
#include <assert.h>
#include <stdio.h>

int main(){
    char* name = "test";
    size_t index = hash(name,(size_t)11);
    printf("%d th index\n",(int)index);
    assert((int)index == 6);
    printf("hash test passed\n");
}