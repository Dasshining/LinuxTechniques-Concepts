#include "bitmap.h"


int main(){
    bitmap_t *myBitmap = bitmap_create(14);
    
    bitmap_set_bit(myBitmap, 2);
    bitmap_set_bit(myBitmap, 16);
    bitmap_set_bit(myBitmap, 8);
    bitmap_print(myBitmap);
    
    bitmap_unset_bit(myBitmap, 6);
    bitmap_unset_bit(myBitmap, 8);
    bitmap_print(myBitmap);
    
    printf("Is bit 2 set? 1 TRUE, 0 FALSE: %d\n",bitmap_is_bit_set(myBitmap, 18));
    printf("Is bit 8 set? 1 TRUE, 0 FALSE: %d\n",bitmap_is_bit_set(myBitmap, 8));
    
    bitmap_clear(myBitmap);
    bitmap_print(myBitmap);
    printf("is bit map full?: %d\n",bitmap_is_full(myBitmap));

    printf("\n\nBit pattern match\n");
    int patternSize = 4;
    char pattern[] = "X1 X1";
    int index = 0;
    int *ptrToIndex = &index;
    printf("%s\n", pattern);
    bitmap_set_bit(myBitmap, 2);
    bitmap_set_bit(myBitmap, 4);
    bitmap_print(myBitmap);
    bool doesPatternMatch = bitmap_pattern_match(myBitmap, pattern, patternSize, ptrToIndex);
    printf("Patter matches? true or false? %d, \nin which bit? %d\n", doesPatternMatch, index);
    printf("End of Bit pattern match\n\n");

    bitmap_set_all(myBitmap);
    bitmap_print(myBitmap);
    printf("is bit map full?: %d\n",bitmap_is_full(myBitmap));

    bitmap_free(&myBitmap);
    bitmap_print(myBitmap);   
}

bitmap_t * bitmap_create (int n_bits){
    int N_bytes = n_bits / 8 + ((n_bits % 8) ? 1 : 0);
    bitmap_t *bitmap = (bitmap_t *)calloc(1,sizeof(bitmap_t));
    bitmap->bit_arr = (char *)calloc(N_bytes, sizeof(char));
    bitmap->arr_size = n_bits;
    return bitmap;
}

void bitmap_print (bitmap_t *bitmap){
    if (bitmap && bitmap->bit_arr){
        uint64_t *n = (uint64_t*)bitmap->bit_arr;
        uint64_t bits = *n;
        uint8_t bit = 0, c = 1;
        printf("n = ");
        for(int i = bitmap->arr_size - 1; i >= 0; i--){
            bit = (uint8_t)(bits >> i) & 0x01;
            printf("%d", bit);
            if((c%4)==0)
                printf(" ");
            c++;
        }
        printf("\n");
    } else {
        printf("Bitmap is NULL");
    }
}

void bitmap_set_bit (bitmap_t *bitmap, int index){
    if (index > bitmap->arr_size){
        printf("Can't set a bit out of the bitmap size\n");
        return;
    } else {
        uint64_t *n = (uint64_t *)bitmap->bit_arr;
        *n = SET_BIT(*n,index);
    }
}

void bitmap_unset_bit (bitmap_t *bitmap, int index){
    if (index > bitmap->arr_size){
        printf("Can't unset a bit out of the bitmap size\n");
        return;
    } else {
        uint64_t *n = (uint64_t *)bitmap->bit_arr;
        *n = UNSET_BIT(*n,index);
    }
}

int bitmap_is_bit_set (bitmap_t *bitmap, int index){
    if (index > bitmap->arr_size){
        printf("Can't assert a bit out of the bitmap size, return -1\n");
        return -1;
    } else {
        uint64_t *n = (uint64_t *)bitmap->bit_arr;
        bool isBitSet = 0;
        isBitSet = IS_BIT_SET(*n, index);
        return isBitSet;
    }
}

void bitmap_clear (bitmap_t *bitmap){
    if (bitmap && bitmap->bit_arr){
        uint8_t arr_size = bitmap->arr_size;
        if(arr_size <= uint8_t_size){
            uint8_t *cleanData = (uint8_t *)bitmap->bit_arr;
            *cleanData = 0;
        } else if (arr_size <= uint16_t_size){
            uint16_t *cleanData = (uint16_t *)bitmap->bit_arr;
            *cleanData = 0;
        } else if (arr_size <= uint32_t_size){
            uint32_t *cleanData = (uint32_t *)bitmap->bit_arr;
            *cleanData = 0;
        } else {
            uint64_t *cleanData = (uint64_t *)bitmap->bit_arr;
            *cleanData = 0;
    }
    } else {
        printf("Bitmap is NULL");
    }
}

void bitmap_set_all (bitmap_t *bitmap){
    if (bitmap && bitmap->bit_arr){
    uint8_t arr_size = bitmap->arr_size;
    if(arr_size <= uint8_t_size){
        uint8_t *setData = (uint8_t *)bitmap->bit_arr;
        *setData = 0xFF;
    } else if (arr_size <= uint16_t_size){
        uint16_t *setData = (uint16_t *)bitmap->bit_arr;
        *setData = 0xFFFF;
    } else if (arr_size <= uint32_t_size){
        uint32_t *setData = (uint32_t *)bitmap->bit_arr;
        *setData = 0xFFFFFFFF;
    } else {
        uint64_t *setData = (uint64_t *)bitmap->bit_arr;
        *setData = 0xFFFFFFFFFFFFFFFF;
    }
    } else {
        printf("Bitmap is NULL");
    }
}

void bitmap_free (bitmap_t **bitmap){
    free((*bitmap)->bit_arr);
    free(*bitmap);
    (*bitmap)->bit_arr = NULL;
    *bitmap = NULL;
}

/* bool bitmap_is_full(bitmap_t *bitmap){
    bool isBitSet = true;
    bool isBitMapFull = true;
    for(int i = 0; i <= bitmap->arr_size; i++){
        isBitSet = bitmap_is_bit_set(bitmap, i); 
        if(false == isBitSet){
            isBitMapFull = false;
            break;
        }
    }
    return isBitMapFull;
} */

bool bitmap_pattern_match (bitmap_t *bitmap, char *binary_string, int n_bits, int *i){
    uint8_t bitIndex = 0;
    uint8_t strIndex = 0;
    uint64_t bitmapArrayCopy = *bitmap->bit_arr;
    bool isPatterMatch = false;
    if(bitmap->arr_size < n_bits){
        isPatterMatch = false;
    } else {
        for (int j = 0; j <= (bitmap->arr_size-n_bits); j++)
        {
            bitIndex = 0;
            strIndex = 0;
            isPatterMatch = true;
            printf("%x\n",bitmapArrayCopy);
            for (int i = 0; i <= n_bits; i++){
                if (binary_string[strIndex] == 'X'){
                    strIndex++;
                    bitIndex++;
                    continue;
                } else if (binary_string[strIndex] == ' '){
                    strIndex++;
                    continue;
                } 

                uint8_t currentBit = (uint8_t)IS_BIT_SET(bitmapArrayCopy, bitIndex);
                uint8_t currentStrBit = (uint8_t)(binary_string[strIndex] - '0');
                printf("%d: %d -> ", bitIndex, currentBit);
                printf("%d: %d - %d\n", strIndex, binary_string[strIndex]-'0', currentStrBit);
                
                if (currentBit != currentStrBit) {
                    isPatterMatch = false;
                    break;
                }
                strIndex++;
                bitIndex++;
            }
            *i = j;
            printf("Next iteration\n");
            if(false == isPatterMatch){
                bitmapArrayCopy = bitmapArrayCopy >> 1;
            } else {
                break;
            }
        }
    }
    return isPatterMatch;
}

bool bitmap_is_full(bitmap_t *bitmap){
    bool isBitSet = true;
    bool isBitMapFull = true;
    ITERATE_BITMAP_BEGIN(bitmap, isBitSet){
        if(false == isBitSet){
            isBitMapFull = false;
        }
    } ITERATE_BITMAP_END;
    return isBitMapFull;
}