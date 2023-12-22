/* Questions are based on following short C program:
 * In below program code, Address of instructions at line no 15 and 22 are also given.
 * ssume the function B() is currently executing on CPU.
 * lso, given that the base address (also called frame pointer) of the stack frame of function A is 0xbffff0c8.
 * ssume, the program runs on a 32 bit system - which means size of interger data type is 4Bytes, and 4Bytes of memory is used to store any address.
 */

3 int B (int a , int b , int c ) {    /* Currently in execution */
4
5    int res = 0; 
6    res = a + b + c;
7    return res;
8 }

11 int A (int a, int b) { /* base pointer = 0xbffff0c8 */
12    
13     int c = 0 ;
14     c = a + b;
15     int d = B (c, a, b);  /*I3 0x8048440 */ /* 15 */
16     return d;
17 }

19 int main (int argc, char **argv) {
20  
21     int res = 0;
22     res = A (4, 5);  /* I1 : 0x8048469*/ /* 22 */
23     return 0;
24 }