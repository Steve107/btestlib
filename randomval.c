#include "randomval.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static long int randomSeed = 0;
static short int randomGeneratorInitialized = 0;

long int initializeRandomGenerator(int* seed, short int randGenInit){
    
    randomSeed = (seed == NULL) ? time(NULL) : *seed;
    randomGeneratorInitialized = (randGenInit == 1 || randGenInit == 2) ? randGenInit : randomGeneratorInitialized;

    if(randomGeneratorInitialized != 1) { 
        srand(randomSeed);
        randomGeneratorInitialized = (randomGeneratorInitialized == 0) ? 1 : 2;
    }

    return randomSeed; 
}

// Generates a random integer in the interval from start to end (excluded
// with values' difference equal to step

IntType randInt(IntType start, IntType end, IntType step){

    initializeRandomGenerator(NULL, 0);
    
    if(end < start || step <= 0) return 0;  // Avoid invalid values

    IntType diff = ( (end - start) / step ) + 1;    // How many values are present in the interval 
    
    return start + (rand() % diff ) * step; // This way the values satisfy the given conditions
}

// Fills an array of len dimension with random values
// in the interval [start; end) and separated by step

void randIntArr(IntType* arr, unsigned long int len, IntType start, IntType end, IntType step){
    
    unsigned long int i;

    for(i = 0; i < len; i++) 
        arr[i] = randInt(start, end, step);
}

// Fills an array of len dimension with values 
// from start (included), separated by step

void genIntSeq(IntType* arr, unsigned long int len, IntType start, IntType step){
    
    unsigned long int i;

    for(i = 0; i < len; i++) 
        arr[i] = start + i*step;
}

// Swaps two variable values

void swapInt(IntType* a, IntType* b){

    IntType temp = *a;
    *a = *b;
    *b = temp;
}

// Reverses the order of elements in an array

void reverseIntArr(IntType* arr, unsigned long len){
    
    unsigned long int i;

    for(i = 0; i < len/2; i++)
        swapInt(arr+i, arr+(len - 1 - i));
}

void randIntSort(IntType *arr, unsigned long int len, unsigned long int nperm){
    
    unsigned long int choice1, choice2;
    unsigned long int i;

    for(i = 0; i < nperm; i++){

        choice1 = rand() % len;
        choice2 = rand() % len;

        swapInt(arr+choice1, arr+choice2);
    }

}

// Fills an array with a random sequence of unique values 
// beginning from start and separated by step value

void randIntSeq(IntType* arr, unsigned long int len, IntType start, IntType step){

    genIntSeq(arr, len, start, step);
    randIntSort(arr, len, NPERM);
}

void randIntMatrix(IntType* mat, unsigned long int row, unsigned long int col, IntType start, IntType end, IntType step){

    unsigned long int i, j;
    
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            *(mat+i*col+j) = randInt(start, end, step);     
        }
    }

}

void printIntMatrix(IntType* mat, unsigned long int row, unsigned long int col, char* format){
    
    unsigned long int i, j;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            printf(format, *(mat+i*col+j));
        }
        printf("\n");
    }
}

void printIntArr(IntType* arr, unsigned long int len, char* format){    

    //printf("{");

    for(unsigned long int i = 0; i < len; i++){
        printf(format, *(arr+i));
    } 
    
    //if(len != 0) printf("\b\b");
    
    //printf("}\n");
    printf("\n");
}



FracType randFrac(FracType start, FracType end, FracType step){

    initializeRandomGenerator(NULL, 0);
    
    if(end < start || step <= 0) return 0;  // Avoid invalid values

    long int diff = ( (end - start) / step ) + 1;    // How many values are present in the interval 
    
    return start + (rand() % diff) * step; // This way the values satisfy the given conditions
}

// Fills an array of len dimension with random values
// in the interval [start; end) and separated by step

void randFracArr(FracType* arr, unsigned long int len, FracType start, FracType end, FracType step){
    
     unsigned long int i;

    for(i = 0; i < len; i++) 
        arr[i] = randFrac(start, end, step);
}

// Fills an array of len dimension with values 
// from start (included), separated by step

void genFracSeq(FracType* arr, unsigned long int len, FracType start, FracType step){
    
    long unsigned int i;

    for(i = 0; i < len; i++) 
        arr[i] = start + i*step;
}

// Swaps two variable values

void swapFrac(FracType* a, FracType* b){

    FracType temp = *a;
    *a = *b;
    *b = temp;
}

// Reverses the order of elements in an array

void reverseFracArr(FracType* arr, unsigned long int len){
    
    unsigned long int i;

    for(i = 0; i < len/2; i++)
        swapFrac(arr+i, arr+(len - 1 - i));
}

void randFracSort(FracType *arr, unsigned long int  len, IntType nperm){
    
    IntType choice1, choice2;
    IntType i;

    for(i = 0; i < nperm; i++){

        choice1 = rand() % len;
        choice2 = rand() % len;

        swapFrac(arr+choice1, arr+choice2);
    }

}

// Fills an array with a random sequence of unique values 
// beginning from start and separated by step value

void randFracSeq(FracType* arr, unsigned long int len, FracType start, FracType step){

    genFracSeq(arr, len, start, step);
    randFracSort(arr, len, NPERM);
}

void randFracMatrix(FracType* mat, unsigned long int row, unsigned long int col, FracType start, FracType end, FracType step){

    unsigned long int i, j;
    
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            *(mat+i*col+j) = randFrac(start, end, step);            
        }
    }

}

void printFracArr(FracType* arr, unsigned long int len, char* format){
    
    //printf("{");

    for(unsigned long int i = 0; i < len; i++){
        printf(format, arr[i]);
    } 
    
    //if(len != 0) printf("\b\b");
    
    //printf("}\n");
    printf("\n");
}

void printFracMatrix(FracType* mat, unsigned long int row, unsigned long int col, char* format){
    
    unsigned long int i, j;
    
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            printf(format, *(mat+i*col+j));
        }
        printf("\n");
    }

}

char randChar(char type){
    
    static char alpha[53] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static char symbols[32] = "\\`\"#%'&()[]{}*+-/.;:!?<>=^|$@~_";
     
    switch(type){
        case 'l': return randInt('a', 'z', 1);        // Lowercase 
        case 'u': return randInt('A', 'Z', 1);        // Uppercase
        case 'a': return alpha[randInt(0, 51, 1)];    // Alphabetic            
        case 'n': return randInt('0', '9', 1);        // Number
        case 's': return symbols[randInt(0, 30, 1)];  // Symbols
        case 'A': return randInt(32, 126, 1);         // All
        default : return '\0';
    }

}

void randStr(char* str, char* mask){
    
    for(unsigned long int i = 0; mask[i] != '\0'; i++) 
        str[i] = randChar(mask[i]);
}

