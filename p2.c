/*
 * Code by GABRIEL MEDINA for CSUDH CSC 321 FALL 2017
 * refined by: gabriel medina
 * music by: gabriel medina
 * coffee runner: gabriel medina
 * primary procrastinator: gabriel medina
 */

#include <stdio.h>

/* 
 * this function prints the bits by using a mask
 *  parameter x is pointer, which lets us fudge the type checking
 *  parameter o is a switch: 0 is int, 1 is double
 */
void maskPrint(unsigned long int* x, int o) {
   unsigned long int mask = (1L << 63);      // this is the mask, set to 2^63

   for (int k = 0; k < 64; k++)              // runs one time per bit
   {
      if (o==0 && (k%4)==0) printf(" ");     // readability: seperation every 4 bits
      if (o==1 && k==1) printf(" ");         // seperate the sign bit from the exp
      if (o==1 && k==12) printf(" ");        // seperate the exp from the mantissa

      // bitwise AND, compare bit to mask at position 63-k
      if ( (*x & mask) > 0) printf("1");  
      else printf("0");                      // print 0 or 1 appropriately
      mask = mask >> 1;                      // shift mask to next position
   }
   printf("\n");                             // newline, for formatting
}

int main() {
   unsigned long int i = 0;                  // 64bit int
   double d = 0;                             // 64bit float

   while (1)                                 // enter infinite loop
   {
      printf("Enter an integer number: \n");
      if ( scanf("%li", &i) )                // get user input,  if input is numerical
         maskPrint(&i,0);                    // call function, pass address and option
      else break;                            // input is not numerical, exit loop

      printf("Enter a double number: \n");
      if ( scanf("%lf", &d) )                // get user input, if input is numerical
         maskPrint((unsigned long int*)&d,1);// cast as long int to trick the compiler
      else break;                            // input is not numerical, exit loop
   }
   return(0);
}