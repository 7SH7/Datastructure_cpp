// 아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. 
// Signed: Kim Seunghwan Student Number: 22000116
/**
 * @file main.cpp
 * @author Seongbin Kim (seongbin10209@gmail.com)
 * @brief This code is used to test functions with implications from the preprocessor of gcc.
 * @version 1.1
 * @date 2023-02-15
 * 
 * Note:
 * The C preprocessor, is a macro processor that is used automatically by the C compiler to transform your program.
 * The transformation occurs before compilation.
 * It is called a macro processor because it allows you to define macros,
 * which are brief abbreviations for longer constructs. 
 * 
 * This file covers the following topics of the C preprocessor:
 * Header Files 	- #include
 * Macros			- #define
 * Conditionals	    - #ifdef
 * Et cetera
 * 
 * Check official manuals for detailed descriptions:
 * @link https://gcc.gnu.org/onlinedocs/cpp/
 * 
 * Usage:
 * 	step(1). $ g++ -E main.cpp > main.i
 *  - This redirects the output of the preprocessed main.cpp to the main.i file.
 *      - More about output redirection: @link https://www.guru99.com/linux-redirection.html
 *  - Take a screenshot of the contents of main.i
 *      - $ cat main.i
 *          - To view the contents.
 * 
 *  step(2). g++ -o filename main.cpp
 *  - To create an executable file with a desirable name.
 * 	- Then follow the instructions printed!
 * 	- Have fun!
 * 
 * God is good, all the time!
 * Happy Coding~~
 */
#if 0
#include "stdio.h"
#endif

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif



int main() {
    #if 0

    #ifdef DEBUG
    printf("\nDEBUG - Hello World!\n");
    #else
    printf("\nHello World!\n");
    printf("Well Done! Now try compiling with the DEBUG option.\n\n");
    #endif

    DPRINT( printf("Notice these lines are also executed.\n"); );
    DPRINT( printf("Next try switching the #if 1 -> 0 at line 41 & 54\n"); );
    DPRINT( printf("Then compare the results of the file main.i with step(1).\n\n"); );

    #else

    /*
    Will this line appear in the main.i file?
    If you add comments explaining at least 3 lines of the code you might get some bonus points!
    You can use #if and #else #endif to separate the execution parts. 
    There was not much mention of #pragma in the given file. 
    So, I search about that, tand the #pragma region name, #pragma region, was then able to hide the code between them.
    Preprocessing machines are recommended for use in the c language, but cpp recommends using them less frequently.
    A preprocessor function is performed before compiling, and the file extension at this time is .i.
    */

    #endif
}

