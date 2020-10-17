#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdint.h>

#define MULTIPLICATION 1
#define DIVISION 2
#define ADDITION 3
#define SUBTRACTION 4

/* github.com/r0ss1n1 */
/* Charles Thomas Wallace Truscott, Byron Bay, NSW, Australia */
/* Implementing a calculator. Will take any arithmetic expression and print it in words and numbers to the console */
/* Need a stack or queue - Kernighan's C manual demonstrates a similar program (reverse Polish calculator) with a stack */
/* Need to convert integer pointer with individual digits size %c (char) to concatenated integers i.e. input 1000 
first_two_digits = strcat(1, 0) second_two_digits(0, 0), num = strcat(first_two_digits, second_two_digits) (int) num
or (long int) num ... etc ... needs uniqueness e.g. allowing calculator to only support 10^9 *.

/* Need to implement stack, queue, maybe flick back to Kernighan's 'Reverse Polish Calculator' demonstration */
/* And then parentheses, exponents, multiplication, division, addition, subtraction done from left to right */
/* Tricky to evaluate parentheses in terms of searching the whole char array or incrementing a pointer via each */
/* char in the char array to find how many parentheses match */
typedef struct Calculation {

	int first_integer;
	int second_integer;
	int priority;

} Calculation;
int main(void) {

/* I love you Dad, Mark William Watters b. 1955 */
	int y, z;
	char calculation[100];
	char * test;
	fgets(calculation, 100, stdin);
	for (int i = 0; calculation[i] != '\0';){

		if (calculation[i] == (char) '+') {
			printf("plus ");
			++i;

		} else if (calculation[i] == (char) '-') {
			printf("minus ");
			++i;

		} else if (calculation[i] == (char) '*') {
			printf("times ");
			++i;

		} else if (calculation[i] == (char) '/') {
			printf("divided by ");
			++i;
		} else if (calculation[i] == '\n') {
			++i;
		} else if (calculation[i] == 0x20) {
			++i;
		} else if (isdigit(calculation[i]) && isdigit(calculation[i+1])) {
			for(; isdigit(calculation[i]); ++i){
				printf("%d", calculation[i] - '0');
			}
			printf(" ");
			++i;
			/*printf("%d%d", calculation[i] - '0', calculation[i+1] - '0');*/
		}  else if (isdigit(calculation[i]) && !isdigit(calculation[i-1])) {
			printf("%d ", calculation[i] - '0');
			++i;

			/*printf("%d%d", calculation[i] - '0', calculation[i+1] - '0');*/
		} else if (isdigit(calculation[i]) && calculation[i-2] == '*') {
			printf("%d ", calculation[i] - '0');
			++i;
		}  else if (isdigit(calculation[i]) && calculation[i-2] == '/') {
			printf("%d ", calculation[i] - '0');
			++i;
		}  else if (isdigit(calculation[i]) && calculation[i-2] == '-') {
			printf("%d ", calculation[i] - '0');
			++i;
		}  else if (isdigit(calculation[i]) && calculation[i-2] == '+') {
			printf("%d ", calculation[i] - '0');
			++i;
		} else if (isdigit(calculation[i]) && calculation[i-1] == 0x20) {
			printf("%d ", calculation[i] - '0');
			++i;
		}

	/* Create an integer array dereferencing temporary Calculation data type addresses */
	/* Recurse over the list where priority for multiplication comes first, division   */
	/* second, addition third and subtraction fourth. need a new way to uniquely place */
	/* in the array some way to distinguish between arithmetic operator and operand,   */
	/* as I need a way to determine the size and allocation of different integer input */
	/* and converting them to machine readable numbers */

	/* Go through the array from left to right until the highest priority flag is found*/
	/* then retrieve integers, perform the arithmetic, store evaluation in new array   */
	/* until the lowest priority evaluation furthermost right has been reached i.e.    */
	/* calculation[100] */ 

	/* Charles Thomas Wallace Truscott, github.com/r0ss1n1, 11:45 AEST 17th Oct 2020   */
	
	}



	return 0;

}