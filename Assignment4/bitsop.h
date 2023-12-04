#include <stdint.h>
#include <stdio.h>

#define SET_BIT(n, bit)    (n|(1<<bit))
#define UNSET_BIT(n, bit)  (n&(~(1<<bit)))
#define IS_BIT_SET(n, bit) ((n&(1<<bit))?1:0)
#define TOGGLE_BIT(n, bit) (IS_BIT_SET(n,bit)?UNSET_BIT(n,bit):SET_BIT(n,bit))
//#define TOGGLE_BIT(n, bit) (((n^(1<<bit))&(1<<bit))?(n|(1<<bit)):(n&(~(1<<bit))))
#define COMPLEMENT(n) (~n)

void print_bit_pattern(uint32_t n);

uint8_t count_bit_set(uint32_t n);

uint32_t min_bits_occupied(uint32_t n);

uint32_t shift_patter_towards_right(uint32_t n, uint8_t k);

uint16_t print_IP_to_bin(char *ip);

uint8_t isPowerOfTwo(uint32_t n);

uint32_t make_p_q_inclusive_mask(uint32_t n, uint8_t p, uint8_t q);