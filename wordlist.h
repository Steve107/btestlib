#ifndef WORDLIST_H
#define WORDLIST_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define MAX_BUFFER_LEN 150
    
    unsigned long int countLines(FILE *fp);
    char** genWordlist(char* filename);
    
    extern const char* namesWordList[];
    extern const char* surnamesWordList[];
    extern const char* citiesWordList[];
    extern const char* wordsWordList[];

    #define randName()      namesWordList[rand()%NAMES_NUM]
    #define randSurname()   surnamesWordList[rand()%SURNAMES_NUM]
    #define randCity()      citiesWordList[rand()%CITIES_NUM]
    #define randWord()      wordsWordList[rand()%WORDS_NUM]

    #define NAMES_NUM       9221
    #define SURNAMES_NUM    22579
    #define CITIES_NUM      25351
    #define WORDS_NUM       1136

    #define NAMES_MAXLEN       15
    #define SURNAMES_MAXLEN    17
    #define CITIES_MAXLEN      30
    #define WORDS_MAXLEN       14

#endif
 
