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

char global_stack[100];
int add_to_stack(int * stack);
int evaluate_stack(int * stack);
int main(void) {

/* I love you Dad, Mark William Watters b. 1955 */
	int y, z;
	char * pointer_gs = (char *) global_stack;
	char calculation[100];
	char * test;
	fgets(calculation, 100, stdin);
	for (int i = 0; calculation[i] != '\0';){

		if (calculation[i] == (char) '+') {
			* pointer_gs = calculation[i];
			++pointer_gs;
			++i;

		} else if (calculation[i] == (char) '-') {
			* pointer_gs = calculation[i];
			++pointer_gs;
			++i;

		} else if (calculation[i] == (char) '*') {
			* pointer_gs = calculation[i];
			++pointer_gs;
			++i;


		} else if (calculation[i] == (char) '/') {
			* pointer_gs = calculation[i];
			++pointer_gs;
			++i;

		} else if (calculation[i] == '\n') {
			++i;
		} else if (calculation[i] == 0x20) {
			* pointer_gs = calculation[i];
			++pointer_gs;
			++i;

		} else if (isdigit(calculation[i]) && isdigit(calculation[i+1])) {
			for(; isdigit(calculation[i]); ++i){
				* pointer_gs = calculation[i];
				++pointer_gs;
			}
			* pointer_gs = 0x20;
			++pointer_gs;
			++i;

			/*printf("%d%d", calculation[i] - '0', calculation[i+1] - '0');*/
		}  else if (isdigit(calculation[i]) && !isdigit(calculation[i-1])) {
			* pointer_gs = calculation[i];
			++pointer_gs;
			++i;
			/*printf("%d%d", calculation[i] - '0', calculation[i+1] - '0');*/
		} else if (isdigit(calculation[i]) && calculation[i-2] == '*') {
			* pointer_gs = calculation[i];
			++pointer_gs;
			++i;
		}  else if (isdigit(calculation[i]) && calculation[i-2] == '/') {
			* pointer_gs = calculation[i];
			++pointer_gs;
			++i;
		}  else if (isdigit(calculation[i]) && calculation[i-2] == '-') {
			* pointer_gs = calculation[i];
			++pointer_gs;
			++i;
		}  else if (isdigit(calculation[i]) && calculation[i-2] == '+') {
			* pointer_gs = calculation[i];
			++pointer_gs;
			++i;
		}  else if (isdigit(calculation[i]) && calculation[i+2] == '*') {
			* pointer_gs = calculation[i];
			++pointer_gs;
			++i;
		}  else if (isdigit(calculation[i]) && calculation[i+2] == '/') {
			* pointer_gs = calculation[i];
			++pointer_gs;
			++i;
		}  else if (isdigit(calculation[i]) && calculation[i+2] == '-') {
			* pointer_gs = calculation[i];
			++pointer_gs;
			++i;
		}  else if (isdigit(calculation[i]) && calculation[i+2] == '+') {
			* pointer_gs = calculation[i];
			++pointer_gs;
			++i;
		} else if (isdigit(calculation[i]) && calculation[i+1] == 0x20) {
			* pointer_gs = calculation[i];
			++pointer_gs;
			++i;
		}
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
	

	for(int i = 0; i < 100; ++i){
		printf("%c", global_stack[i]);	
	}
	return 0;

}
/*
int add_to_stack(char * stack) {
	while(* stack != '\0') {
		* global_stack = stack;
		++stack;
		++globalstack;
	}
	while(* global_stack != '\0'){
		printf("%s", * ip);
		++global_stack;
	}

}

*/