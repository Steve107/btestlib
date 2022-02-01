#ifndef RANDOMVAL_H
#define RANDOMVAL_H
    
    #ifndef NPERM
        #define NPERM 250     // Default number of permutations to apply
    #endif
        
    #ifndef OVERRIDE_DEFAULT_INTTYPE
        typedef int IntType;  // The default integer type of the function
    #endif

    #ifndef OVERRIDE_DEFAULT_FRACTYPE
        typedef double FracType;  // The default integer type of the function
    #endif
     
    
    // Integer functions prototypes
    IntType randInt(IntType start, IntType end, IntType step); 
    void genIntSeq(IntType* arr, unsigned long int len, IntType start, IntType step);
    void swapInt(IntType* a, IntType* b);
    void reverseIntArr(IntType* arr, unsigned long int len);
    void randIntSeq(IntType* arr, unsigned long int len, IntType start, IntType step);
    void randIntArr(IntType* arr, unsigned long int len, IntType start, IntType end, IntType step);
    void randIntMatrix(IntType* mat, unsigned long int row, unsigned long int col, IntType start, IntType end, IntType step);
    void printIntArr(IntType* arr, unsigned long int len, char* format);
    void printIntMatrix(IntType* mat, unsigned long int row, unsigned long int col, char* format);

    // Fractional functions prototypes
    FracType randFrac(FracType start, FracType end, FracType step); 
    void genFracSeq(FracType* arr, unsigned long int len, FracType start, FracType step);
    void swapFrac(FracType* a, FracType* b);
    void reverseFracArr(FracType* arr, unsigned long int len);
    void randFracSeq(FracType* arr, unsigned long int len, FracType start, FracType step);
    void randFracArr(FracType* arr, unsigned long int len, FracType start, FracType end, FracType step);
    void randFracMatrix(FracType* mat, unsigned long int row, unsigned long int col, FracType start, FracType end, FracType step);
    void printFracArr(FracType* arr, unsigned long int len, char* format);
    void printFracMatrix(FracType* mat, unsigned long int row, unsigned long int col, char* format);
 
    // Chars and strings funcions prototypes
    char randChar(char type);
    void randStr(char* str, char* mask);
 

    #define randBool() randInt(0,1,1) 

    #define ID_MASK      "uunnnnnuu"
    #define DPLATE_MASK  "uunnnuu"
    #define TAXCODE_MASK "uuuuuunnunnunnnu"
    #define TEL_MASK     "nnnnnnnnnn"

#endif
