#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "serialize.h"

int main(){
    ser_buff_t *ser_buff = NULL;
    init_serialized_buffer(&ser_buff);  /*Using first API*/
    init_serialized_buffer_of_defined_size(&ser_buff, 1024); /*Using Second API*/
    char str[40] = "My name is Aldo";
    serialize_string(ser_buff, str, 40);

    return 0;
}

// Must initialize the serialize buffer with default size = SERIALIZE_BUFFER_DEFAULT_SIZE bytes
void init_serialized_buffer(ser_buff_t **b){
    (*b) = (ser_buff_t *)calloc(1, sizeof(ser_buff_t));
    (*b)->b = (ser_buff_t *)calloc(1, SERIALIZE_BUFFER_DEFAULT_SIZE);
    (*b)->size = SERIALIZE_BUFFER_DEFAULT_SIZE;
    (*b)->next = 0;
    (*b)->checkpoint = 0;
}

// Must initialize the serialize buffer with size specified as 2nd argument
void init_serialized_buffer_of_defined_size(ser_buff_t **b, int size){
    (*b) = (ser_buff_t *)calloc(1, sizeof(ser_buff_t));
    (*b)->b = (ser_buff_t *)calloc(1, size);
    (*b)->size = size;
    (*b)->next = 0;
    (*b)->checkpoint = 0;
}

void resize_buffer(ser_buff_t *b){
    b->size = b->size*2;

}

/* The above must API copy 'size' bytes of 'data' into serialized buffer. 
 * If the buffer do not space to accommodate 'size' bytes of data , then expand the buffer to twice 
 * its current size while preserving the content already copied into it.
 */
void serialize_string(ser_buff_t *b, char *data, int size){
    int availableSize = b->size - b->next;
    char isResize = 0;

    while (availableSize < size){
        b->size = b->size*2;
        availableSize = b->size - b->next;
        isResize = 1;
    }

    if(isResize == 0){
        memcpy(b->b + b->next, data, size);
        b->next += size;
        return;
    }

    b->b = realloc(b->b, b->size);
    memcpy((char *)b->b + b->next, data, size);
    b->next += size;
}

// Return 0 if serialize buffer is empty, else -1
int is_serialized_buffer_empty(ser_buff_t *b){
    uint8_t isEmpty = -1;
    if(b->b == 0){
        isEmpty = 0;
    }
    return isEmpty;
}