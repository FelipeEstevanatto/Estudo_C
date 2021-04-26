#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//The thing is, to get 2+2 = 5 you will always have to build a trick to do it, the way you do it can change a lot,
//but basically you are doing a X++ in some place or define 5 somewhere, so the little fun in this exercise is how
//creative ou get to do it

int main(){
	
	//Here is easiest way to do it
	printf("Method 1 - Easy\n\n");
	
	int num = 2;
	printf("%d + %d = %d\n",num,num,5);
	
	getchar(); system("cls");
//
// In this case I tried to evase the X++ and printf("5") methods, first it gets an array and check if you typed 2 + 2 or 2+2 to display
// the result that is 'F'-'A', that are in decimals by the ASCHII table 46 and 41, so 46-41=5 and it prints it out
//
	printf("Method 2 - Not Direct\n\n");
	printf("Type the equation: X + X\n> ");
	char typo[50];
	int result;
	
	gets(typo);
	
	for(int i=0; i < sizeof(typo); i++){
		if( (typo[i] == 50 && typo[i+4] == 50 ) || (typo[i] == 50 && typo[i+2] == 50) ){
			result = 'F'-'A';
			printf("Result: %c + %c = %d\n",typo[i],typo[i], result);
			break;
		}
	}
	
	getchar(); system("cls");
//
// I imagine that besides being creative in the way you do it, another good way to sell the lie is building something true around it,
// thats why this method is just a workind calculator, with 2+2 and 2*2 resulting in 5, it can be done again, in multiple ways
//
	printf("Method 3 - More believable calculator\n\n");
	
	char operator;
	double num1, num2;
    printf("Enter a valid operator (+, -, *,): ");
    scanf("%c", &operator);
    printf("Enter two operands: ");
    scanf("%lf %lf", &num1, &num2);

    switch (operator) {
    case '+':
    	if(num1 == 2 && num2 == 2){
    	printf("%.2lf + %.2lf = %.2lf", num1, num2, num1 + num2 + 1);
		}else
        printf("%.2lf + %.2lf = %.2lf", num1, num2, num1 + num2);
        break;
    case '-':
        printf("%.2lf - %.2lf = %.2lf", num1, num2, num1 - num2);
        break;
    case '*':
    	if(num1 == 2 && num2 == 2){
    	printf("%.2lf + %.2lf = %.2lf", num1, num2,  num1 * num2 + 1);
		}else
        printf("%.2lf * %.2lf = %.2lf", num1, num2, num1 * num2);
        break;
    case '/':
        printf("%.2lf / %.2lf = %.2lf", num1, num2, num1 / num2);
        break;
    default:
        printf("Error! operator is not correct");
    }
	
	return 0;
}