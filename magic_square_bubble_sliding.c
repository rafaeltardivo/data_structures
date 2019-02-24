#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// 4x4 magic square const
const int MAGIC_CONST = 4 * (4*4 + 1) / 2;

void turn_into_single(int square[4][4], int linear_array[16]);
void bubble_sort(int linear_array[16]);
bool is_repeated(int linear_array[16]);

bool is_repeated(int linear_array[16]);
bool are_line_sums_equal(int square[4][4]);
bool are_column_sums_equal(int square[4][4]);
bool are_diagonals_equal(int square[4][4]);
void show_square(int square[4][4]);

void main(){
    int square[4][4] = {0};
    int line_array[16] = {0};

    // step 1 - get user input
    for(int l = 0; l < 4; l++){
        for(int c = 0; c < 4; c++ ){
            printf("Insert a number (%d x %d): ", l, c);
            scanf("%d", &square[l][c]);
        }
    }

    // step 1 - check for line
    turn_into_single(square, line_array);

    // step 2 - sort the array
    bubble_sort(line_array);

    // step 3 - check if is repeated
    if(is_repeated(line_array) == true)
        exit(1);

    // step 4 - check for line sums
    if(are_line_sums_equal(square) == false)
        exit(1);

    // step 5 - check for column sums
    if(are_column_sums_equal(square) == false)
        exit(1);

    // step 6 - check for primary and secondary diagonals
    if(are_diagonals_equal(square) == false)
        exit(1);

    show_square(square);
}

/*
    Turns a multidimentional array into a single dimention one

    arg1: the multidimentional array to be turned
    arg2: the single dimention array to receive the multidimentional one

*/
void turn_into_single(int square[4][4], int linear_array[16]){

    int lc = 0;

    for(int l = 0; l < 4; l++){
        for(int c = 0; c < 4; c++, lc++){
            linear_array[lc] = square[l][c];
        }
    }
}

/*
    Sorts the array using bubble sort algo

    arg1: the single dimention array to be sorted

*/
void bubble_sort(int linear_array[16]){

    int temp = 0;

    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 16; j++){
            if(linear_array[j] > linear_array[j+1]){
                temp = linear_array[j];
                linear_array[j] = linear_array[j+1];
                linear_array[j + 1] = temp;
            }
        }
    }
}

/*
    Checks if the there are repeated numbers using sliding windows method

    arg1: the single dimention array to be sorted

    returns: true if there are repeated numbers, false if there are not

*/
bool is_repeated(int linear_array[16]){
    for(int i = 0; i < 15; i++){
        if(linear_array[i] == linear_array[i + 1]){
            printf("\nRepeated number at %d!\n", linear_array[i]);
            return true;
        }
    }
    return false;
}

bool are_line_sums_equal(int square[4][4]){
    int lines_sum[4] = {0};

    for(int l = 0; l < 4; l++){
        for(int c = 0; c < 4; c++ ){
            lines_sum[l] += square[l][c];
        }
    }

    for(int i = 0; i < 4; i++){
        if(lines_sum[i] != MAGIC_CONST){
            printf("Line %d sum (%d) is not equal to %d!\n", i, lines_sum[i], MAGIC_CONST);
            return false;
        }
    }
    return true;
}

bool are_column_sums_equal(int square[4][4]){
    int columns_sum[4] = {0};

    for(int c = 0; c < 4; c++){
        for(int l = 0; l < 4; l++ ){
            columns_sum[c] += square[l][c];
        }
    }

    for(int i = 0; i < 4; i++){
        if(columns_sum[i] != MAGIC_CONST){
            printf("Column %d sum (%d) is not equal to %d!\n", i, columns_sum[i], MAGIC_CONST);
            return false;
        }
    }
    return true;
}

bool are_diagonals_equal(int square[4][4]){
    int primary_diag_sum = 0, secondary_diag_sum = 0;

    for(int l = 0, c = 0; l < 4; l++, c++){
        primary_diag_sum += square[l][c];
    }

    if(primary_diag_sum != MAGIC_CONST){
        printf("Primary diagonal sum (%d) is not equal to %d!\n", primary_diag_sum, MAGIC_CONST);
        return false;
    }

    for(int l = 0, c = 3; l < 4; l++, c--){
        secondary_diag_sum += square[l][c];
    }

    if(secondary_diag_sum != MAGIC_CONST){
        printf("Secondary diagonal sum (%d) is not equal to %d!\n", secondary_diag_sum, MAGIC_CONST);
        return false;
    }

    return true;
}

void show_square(int square[4][4]){
    for(int l = 0; l < 4; l++){
        printf("\n");
        printf(
            "[ %02d ][ %02d ][ %02d ][ %02d ]",
            square[l][0], square[l][1], square[l][2], square[l][3]
        );
    }
    printf("\n\n");
}   