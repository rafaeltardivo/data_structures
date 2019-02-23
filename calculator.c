#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

float sum_numbers(float n1, float n2);
float subtract_numbers(float n1, float n2);
float multiply_numbers(float n1, float n2);
float divide_numbers(float dividend, float divisor);

void main(){

    int operation = 0, cont = 0, keep = 0;
    float result = 0.0, n1 = 0.0, n2 = 0.0;
    bool continue_loop = true, keep_result = false;

    while(continue_loop == true){

        printf("\nInsert the first (float) number: ");
        scanf("%f", &n1);
        printf("Insert the second (float) number: ");
        scanf("%f", &n2);

        printf("\nChoose your operation: \n1 - [ + ]\n2 - [ - ]\n3 - [ * ]\n4 - [ / ]\n"); 
        scanf("%d", &operation);

        switch(operation){

            case 1:
                result += sum_numbers(n1, n2);
                printf("The result of your sum is: %.2f", result);
                break;
            case 2:
                result += subtract_numbers(n1, n2);
                printf("The result of your subtraction is: %.2f", result);
                break;
            case 3:
                result += multiply_numbers(n1, n2);
                printf("The result of your multiplication is: %.2f", result);
                break;
            case 4:
                result += divide_numbers(n1, n2);
                printf("The result of your division is: %.2f", result);
                break;
            default:
                printf("Invalid option! Please choose one betwenn 1 ~ 4!");
            
        }

        printf("\nDo you want to continue? \n1 - Yes\nAny other number - No\n");
        scanf("%d", &cont);

        continue_loop = cont == 1 ? true : false;

        if(continue_loop == true){
            printf("\n Do you want to keep your result for the next iteration? \n1 - Yes\nAny other number - No\n");
            scanf("%d", &keep);

            keep_result = keep == 1 ? true : false;

            if(keep_result == false)
                result = 0.0;
        }
    }
}

/*
    sum_numbers: sums two numbers
    arg1: float n1 - float number to be added
    arg2: float n2 - float number to be added

    returns: float - sum result
*/
float sum_numbers(float n1, float n2){
    return n1 + n2;
}

/*
    subtract_numbers: subtracts two numbers
    arg1: float n1 - float number to be subtracted
    arg2: float n2 - float number to be subtracted

    returns: float - subtraction result
*/
float subtract_numbers(float n1, float n2){
    return n1 - n2;
}
/*
    multiply_numbers: multiplies two numbers
    arg1: float n1 - float number to be multiplied
    arg2: float n2 - float number to be multiplied

    returns: float - multiplication result
*/
float multiply_numbers(float n1, float n2){
    return n1 * n2;
}

/*
    divide_numbers: divides two numbers
    arg1: float n1 - float number to be divided
    arg2: float n2 - float number to be divided

    returns: float - division result
*/
float divide_numbers(float dividend, float divisor){

    if(divisor == 0){
        printf("Cannot divide by 0!");
        return 0;
    }

    return dividend/divisor;
}