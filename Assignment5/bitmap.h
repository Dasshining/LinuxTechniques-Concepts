#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define SET_BIT(n, bit)    (n|(1<<bit))
#define UNSET_BIT(n, bit)  (n&(~(1<<bit)))
#define IS_BIT_SET(n, bit) ((n&(1<<bit))?1:0)
#define TOGGLE_BIT(n, bit) (IS_BIT_SET(n,bit)?UNSET_BIT(n,bit):SET_BIT(n,bit))
#define COMPLEMENT(n)      (~n)

#define uint8_t_size  8U
#define uint16_t_size 16U
#define uint32_t_size 32U
#define uint64_t_size 64U

typedef struct bitmap_ {
    char *bit_arr;
    int arr_size;
} bitmap_t;

#define ITERATE_BITMAP_BEGIN(bitmap_ptr , bit_state) \
{                                                    \
uint8_t i = 0;                                       \
uint64_t *n = (uint64_t *)bitmap->bit_arr;           \
for (; i <= bitmap_ptr->arr_size; i++){              \
    bit_state = IS_BIT_SET(*n, i);                   \


#define ITERATE_BITMAP_END }}                        \

bitmap_t *bitmap_create (int n_bits);
void      bitmap_print (bitmap_t *bitmap);
void      bitmap_set_bit (bitmap_t *bitmap, int index);
void      bitmap_unset_bit (bitmap_t *bitmap, int index);
int       bitmap_is_bit_set (bitmap_t *bitmap, int index);
void      bitmap_clear (bitmap_t *bitmap); /* Write efficient code */
void      bitmap_set_all (bitmap_t *bitmap); /* Write efficient code */
void      bitmap_free (bitmap_t **bitmap);
bool      bitmap_pattern_match (bitmap_t *bitmap, char *binary_string, int n_bits, int *i);
bool      bitmap_is_full(bitmap_t *bitmap);