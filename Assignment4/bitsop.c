#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitsop.h"

int main(){
	uint32_t num = 5;
	
	/* 1. Write a function which print the bit pattern of a uint32_t number n.
	 * For example, if n = 40, then output should be 0010 1000
	 */
	print_bit_pattern(num);
	
	//2. Must set xth bit in number n, where bit = 2 ^ x.
	num = SET_BIT(num, 8);
	print_bit_pattern(num);

	//3. Must unset xth bit in number n, where bit = 2 ^ x.
	num = UNSET_BIT(num, 5);
	print_bit_pattern(num);

	//4. MUST return TRUE or FALSE depending on xth bit is set or not.
	printf("Is bit set?: %d\n",IS_BIT_SET(num, 0));
	num = SET_BIT(num, 5);
	print_bit_pattern(num);
	printf("Is bit set?: %d\n",IS_BIT_SET(num, 4));

	//5. Must Toggle xth bit in number not
	num = TOGGLE_BIT(num, 5);
	print_bit_pattern(num);
	
	//6. must compute the complement of number n. n itself should not get modified.
	uint32_t numComplement = COMPLEMENT(num);
	print_bit_pattern(numComplement);


	/* 7. fn which returns number of bits set in uint32_t number n.
	 * For example, for n = 40, it should return 2 because binary of 40 is 0010 1000
	 * uint8_t count_bit_set(uint32_t n);
	 */
	count_bit_set(num);


	/* 8. Rotate the bit pattern of number n by k units towards right.
	 * For example, if n = 40 , binary = 0010 1000 and if k = 4, then 
	 * resultatnt bit pattern should be 1000 0010
	 */
	 printf("Starting num shift test\n");
	 uint32_t numShift = 40;
	 numShift = shift_patter_towards_right(numShift, 4);
	 printf("Is this working? ");
	 print_bit_pattern(numShift);

	/* 9. Given an IP Address and a mask value - 20.1.1.2/24. Apply the 
	 * Mask on IP Address and print the bit pattern of resultant ip address obtained.
	 */
	uint16_t ip = print_IP_to_bin("20.1.1.2");
	print_bit_pattern(ip);
	ip = ip & 0xFFFFFF00;
	print_bit_pattern(ip);

	/* 10. Given a 32 bit integer, and two integers p and q such that 0 <= p < q <= 31, 
	 * which represent bit positions, print equivalent integer formed by 
	 * bits in interval [p, q] (p, q inclusive) and remaining bits set to zero.
	 */
	uint32_t numMask = make_p_q_inclusive_mask(0xFFFFFFFF, 3, 12);
	print_bit_pattern(0xFFFFFFFF);
	print_bit_pattern(numMask);

	/* 11. Test whether the integer n is a power of two or not ?
	 * bool isPowerOfTwo(uint32_t n);
	 */
	printf("8 is power of 2: %d\n", isPowerOfTwo(8));
	printf("15 is power of 2: %d\n", isPowerOfTwo(15));
	printf("33,554,432 is power of 2: %d\n", isPowerOfTwo(33554432));

	return 0;
}

/*Prints a bit patter on a 32 bit format with space between each byte (0000 0000)*/
void print_bit_pattern(uint32_t n){
	uint8_t bit = 0; 
	uint8_t c = 1;
	uint8_t numBits = (uint8_t)sizeof(n)*8;
	printf("n = ");
	for(int i = numBits - 1; i >= 0; i--){
		bit = (uint8_t)(n >> i) & 0x01;
		printf("%d", bit);
		if((c%4)==0)
			printf(" ");
		c++;

	}
	printf("\n");
}

/* Counts the number of set bits on a value */
uint8_t count_bit_set(uint32_t n){
	uint8_t bit = 0;
	uint8_t numBits = sizeof(n)*8;
	for(uint8_t i = 0; i < numBits; i++){
		bit += IS_BIT_SET(n,i);
	}
	//printf("num of bit set = %d \n", bit);
	
	return bit;
}

/* Return the minumum fo bytes needed for a value */
uint32_t min_bits_occupied(uint32_t n){
	uint32_t size = 0;
	while (n!=0){
		n>>=8;
		size++;
	}

	if((size%2)!=0){
		size++;
	} else {
		/* Do nothing */
	}
	return (size*4)-1;
}

/* shifts bit pattern towards right, the overflowing bits return to the MSB */
uint32_t shift_patter_towards_right(uint32_t n, uint8_t k){
	uint32_t tempNum = n;
	uint8_t numBytes = min_bits_occupied(n);
	for(int i = 0; i < k; i++){
		if(IS_BIT_SET(tempNum,0)){
			tempNum = tempNum >> 1;
			tempNum = SET_BIT(tempNum,numBytes);
		} else {
			tempNum = tempNum >> 1;
		}
	}
	return tempNum;
}

uint16_t print_IP_to_bin(char *ip){
	uint8_t decValue = 0;
	uint16_t binValue = 0;
	char ipCopy[20];
	char *token;

	strcpy(ipCopy, ip);
	ipCopy[sizeof(ipCopy) - 1] = '\0';

	token = strtok(ipCopy, ".");

	while (token != NULL)
	{
		decValue = atoi(token);
		if(decValue < 0 || decValue > 255){
			printf("Invalid IP: %s\n",ipCopy);
			return 0;
		}
		binValue = (binValue << 8) | decValue;
		token = strtok(NULL, ".");
	}
	return binValue;
}

uint8_t isPowerOfTwo(uint32_t n){
	uint8_t nBits = count_bit_set(n);
	if(nBits != 1)
		return 0;
	else
		return 1;
}

uint32_t make_p_q_inclusive_mask(uint32_t n, uint8_t p, uint8_t q){
	uint32_t mask = 0;
	uint8_t numBits = (uint8_t)sizeof(n)*8;
	for (int i = p; i >= 0; i--){
		mask = SET_BIT(mask, i);
	}
	for (int i = q; i <= numBits; i++){
		mask = SET_BIT(mask, i);
	}
	n = n & (~mask);
	return n;
}