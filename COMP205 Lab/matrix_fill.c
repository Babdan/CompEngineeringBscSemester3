// Dorantes-Nikolaev, Bogdan Itsam
// 11/11/2022, COMP205-02 Systems Programming, Lab5

// Including necessary libraries
#include <stdio.h>
#include <stdlib.h>
//defining size constant as 10
#define SIZE 10

    // Function fill that given a fill rate 0-1.0 fills in a 2d array at random locations between 0,size. filling value is 1
    void fill(int matrix[][SIZE], float fill_rate){
        // For loop to go through the rows
        for(int i = 0; i < SIZE; i++){
            // For loop to go through the columns
            for(int j = 0; j < SIZE; j++){
                // If the random number is less than the fill rate, then the value is 1
                if((float)rand()/RAND_MAX < fill_rate){
                    matrix[i][j] = 1;
                }
                // Otherwise the value is 0
                else{
                    matrix[i][j] = 0;
                }
            }
        }
    }
    //Function to get fill rate from user
    void get_fill_rate(int matrix[][SIZE],float * curr_fill_rate){
        // For loop to go through the rows
        for(int i = 0; i < SIZE; i++){
            // For loop to go through the columns
            for(int j = 0; j < SIZE; j++){
                // If the value is 1, then the fill rate is increased by 1
                if(matrix[i][j] == 1){
                    *curr_fill_rate += 1;
                }
            }
        }
        // Fill rate is divided by the size of the matrix to get the fill rate
        *curr_fill_rate = *curr_fill_rate/(SIZE*SIZE);
    }
    // Function to print the matrix
    void printMatrix(int matrix[][SIZE]) {
        // For loop to go through the rows
        for (int i = 0; i < SIZE; i++) {
            // For loop to go through the columns
            for (int j = 0; j < SIZE; j++) {
                // Prints the value at the current location
                printf("%d ", matrix[i][j]);
            }
            // Prints a new line
            printf("");
    }
}

// Main function
int main(){
    // Creating a 2d square matrix and fill with zeros
    int matrix[SIZE][SIZE] = {0};
    // Fill array by providing fill rate between 0 and 1.0
    fill(matrix, 1.0);
    // Get the fill rate by calling get_fill_rate function and see if it matches the fill rate
    float curr_fill_rate = 0;
    get_fill_rate(matrix, &curr_fill_rate);
    // Print the matrix
    printMatrix(matrix);
    return 0;
}