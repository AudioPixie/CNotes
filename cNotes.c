#include <stdio.h> // always include - input and output essentials
#include <stdbool.h> // boolean essentials
#include <math.h> // extra math stuff - includes pow function

/* ------------------------
   GLOBAL VARIABLES
------------------------ */

int foo; 

// variables within functions are local
// if a global and local variable have the same name, local overrides global

/* -----------------------------------
   FUNCTION PROTOTYPE DECLARATION
----------------------------------- */

int add(int a, int b); // first int is return type
void sum(int a, int b);
void stat();

void printArrayWithPointer(int *arr);
void printArrayWithSizedArray(int arr[5]);
void printArrayWithUnsizedArray(int arr[]);

void swapWithPointer(int *a, int *b);
void swapWithoutPointer(int swapme[]);

// int add(int, int);  <-- also acceptable, no paramater names

int main() { // always include - all your code goes in here
    
    char *dashes = "-----------------------------------";

/* ------------------------
   BASIC PRINT
------------------------ */

printf("\n%s\n   BASIC PRINT\n%s\n\n", dashes, dashes);

    printf("Hello World\n"); 
    printf("Hello\nWorld\n"); // line break -> \n
    printf("\n"); // blank line

/* ------------------------
   VARIABLES
------------------------ */

printf("%s\n   VARIABLES\n%s\n\n", dashes, dashes);

    // Names can contain letters (case sensitive), digits (can't start with), and underscores
    // type name = value;

    int number1 = 123;
    double pi1 = 3.14;
    float z1 = 40.5f; // f is not necessessary in c, but is in other languages, a good habit
    char c1 = 'a';
    char ascii = 97; // also a
    char *str1 = "Hello Earth";

    printf("number1: %i, pi1 = %f, z1 = %f, c1 = %c, str1 = %s\n", number1, pi1, z1, c1, str1);

    // % is a placeholder and i/f/c/s is type, specific variables are defined at the end (after "")

    int num1 = 5, num2 = 6, num3 = 7; // multiple declarations of same type

    // replacing values, code is read from top to bottom. These are the same variable names as above
    number1 = 234;
    pi1 = 6.43;
    z1 = 0.12f;
    c1 = 'A';
    str1 = "Hello Moon";

    printf("number1: %i, pi1 = %f, z1 = %f, c1 = %c, str1 = %s\n", number1, pi1, z1, c1, str1);

    const int iCantChange = 10; // cannot be changed after assignment - error will return if attempted

/* ------------------------
   DATA TYPES
---------------------------

    Primary: Integer, Float, Double, Char, Void
    Secondary: Array, Pointer, Structure, Union, Enum

        DATA TYPE   RANGE                           BYTES       FORMAT

        char        -128 ~ 127                      1           %c
        short       -32768 ~ 32767                  2           %d
        int         -2147483648 ~ 2147483647        4           %d || %i
        long        -9.223372e+18 ~ 9.223371e+18    8           %ld
        float       ±3.4e+38                        4           %f
        double      ±1.80e+308                      8           %lf

---------------------------
   ARITHMETIC OPERATORS
---------------------------

    =       assignment
    +       addition
    -       subtraction
    *       multiplication
    /       division
    %       modulo (remainder)
    
    PEDMAS applies - look up C operator precendence for further details

*/

printf("\n%s\n   ARITHMETIC OPERATORS\n%s\n\n", dashes, dashes);

    int a = 3;
    int b = 6;
    int c = 10;
    int result; // blank variable

    result = a + b + c;
    printf("addition: %i\n", result);

    printf("subtraction: %i\n", a - b - c); // you can do operations directly to placeholder

    result = c * a;
    printf("multiplication: %i\n", result);

    result = c / a;
    printf("division: %i\n", result); // integer division is truncated (decimals are chopped off, no rounding)

    result = c % a;
    printf("modulo: %i\n", result);

/* --------------------------------------
   LOGICAL OPERATORS - boolean algebra
-----------------------------------------

    &&      and
    ||      or
    !       not

    A and B are variables - Z is the result

    Not - The opposite
    A   Z
    0   1
    1   0
    
    And - only returns true if BOTH are true
    A   B   Z
    0   0   0
    0   1   0
    1   0   0
    1   1   1

    Or - only returns false if BOTH are false
    A   B   Z
    0   0   0
    0   1   1
    1   0   1
    1   1   1

*/

printf("\n%s\n   LOGICAL OPERATORS\n%s\n\n", dashes, dashes);

    bool x, y, result2;

    x = true;
    y = false;

    result2 = x && y;
    printf("x and y: %i\n", result2); // print as integers, 0 = false, 1 = true

    // ! = NOT/the opposite of

    result2 = x && !y;
    printf("x and not y: %i\n", result2);

    result2 = x || y;
    printf("x or y: %i\n", result2);


/* --------------------------------------
   COMPOUND ASSIGNMENT OPERATORS
-----------------------------------------

    OPERATOR    EQUIVALENT
    x += y      x = x + y
    x -= y      x = x - y  
    x *= y      x = x * y 
    x /= y      x = x / y  
    x %= y      x = x % y   

    x++/++x     x = x + 1   x++ adds 1 AFTER the operation is complete
    x--/--x     x = x - 1   ++x adds 1 BEFORE

*/
printf("\n%s\n   COMPOUND ASSIGNMENT\n%s\n\n", dashes, dashes);

    int comp1 = 5;
    int comp2 = 10;
    int comp3 = 2;

    comp3 *= comp1 + comp2; // comp3 = comp3 * (comp1 + comp2) /AKA/ 30 = 2 * (5 + 10)
    printf("2 * (5 + 10) = %i\n\n", comp3);

    int increment1 = 10;
    int increment2 = 10;

    printf("Does addition after completion: %i\n", increment1++);
    printf("Does addition before completion: %i\n", ++increment2);

/* --------------------------------------
   COMPARISON OPERATORS
-----------------------------------------

    ==      Is equal to
    !=      Is not equal to
    <       Less than
    <=      Less than or equal to
    >       Greater than
    >=      Greater than or equal to

*/

printf("\n%s\n   COMPARISON OPERATORS\n%s\n\n", dashes, dashes);

    int xComp = 10;
    int yComp = 20;
    bool resultComp;

    resultComp = xComp > yComp;
    printf("x > y: %i\n", resultComp);

    resultComp = xComp < yComp;
    printf("x < y: %i\n", resultComp);

/* ------------------------
   CAST OPERATORS
------------------------ */

printf("\n%s\n   CAST OPERATORS\n%s\n\n", dashes, dashes);

    int xCast = 17;
    int yCast = 5;
    float resultCast;

    resultCast = xCast / yCast;
    printf("Without cast: 17 / 5 = %f\n", resultCast); // truncated by default

    resultCast = (float) xCast / yCast; // only xCast is converted here - temporarily
    printf("With cast: 17 / 5 = %f\n", resultCast);

/* ------------------------
   CONDITIONALS
------------------------ */

printf("\n%s\n   CONDITIONALS\n%s\n\n", dashes, dashes);

    int midiNote = 10;

    if(midiNote < 0){
        printf("The MIDI value %i is not valid.\n", midiNote);
    }

    else if(midiNote < 12){
        printf("The MIDI value %i is less than 12.\n", midiNote);
    }

    else if(midiNote < 36){
        printf("The MIDI value %i is less than 36.\n", midiNote);
    }

    else if(midiNote > 127){
        printf("The MIDI value %i is not valid.\n", midiNote);
    }

    else {
        printf("The MIDI value %i is greater than 36.\n", midiNote);
    }
    
/* ------------------------
   SWITCH STATMENT
------------------------ */

printf("\n%s\n   SWITCH STATEMENT\n%s\n\n", dashes, dashes);

    char switchC = 'B'; // characters or integers only

    switch(switchC){

        case 'A':
            printf("The character is A\n");
            break;  // if the case is TRUE with no break, 
                    // all following code will be executed as TRUE until a break is found
        case 'B':
            printf("The character is B\n");
            break;

        case 'C':
            printf("The character is C\n");
            break;

        default:
            printf("The character isn't A, B, or C\n");
    }

/* --------------------------------------
   WHILE LOOPS
-------------------------------------- */

printf("\n%s\n   WHILE LOOPS\n%s\n\n", dashes, dashes);

    int midiNote2 = 60;

    while(midiNote2 <= 62){
        printf("While up: %i\n", midiNote2);
        midiNote2++;
    }

/* --------------------------------------
   FOR LOOPS
-------------------------------------- */

printf("\n%s\n   FOR LOOPS\n%s\n\n", dashes, dashes);

    for(int midiNote3 = 70; midiNote3 <= 72; midiNote3++){
        printf("For up: %i\n", midiNote3);
    }

    printf("\n"); // blank line

    for(int i = 4; i >= 0; i--){
        printf("Countdown: %i\n", i);
    }

/* --------------------------------------
   NESTED FOR LOOPS
-------------------------------------- */

printf("\n%s\n   NESTED FOR LOOPS\n%s\n\n", dashes, dashes);

    for(int x = 1; x < 4; x++){
        printf("The value of x is %i\n", x);

        for(int y = 1; y < 4; y++){
            if(y >= x){
                printf("The value of y is %i\n", y);
            }
        }

        printf("\n"); // blank line
    }

/* --------------------------------------
   USER INPUT
-------------------------------------- */

printf("%s\n   USER INPUT\n%s\n\n", dashes, dashes);

    int userInput;

    printf("Type your number: ");
//    scanf("%i", &userInput); // use & before variable for scanf
    printf("Your number was: %i\n", userInput);

    printf("\n"); // blank line

    char userString[128];
    printf("Type your word: ");
//    scanf("%s", userString); // will cut off at first whitespace
    printf("Your word was: %s\n", userString);

    printf("\n"); // blank line

    char userString2[128];
    printf("Type your sentence: ");
//    scanf("%127[^\n]", userString2); // 127 is buffer size, 128th will be NULL, works with whitespace
    printf("Your sentence was: %s\n", userString2);

    printf("\n"); // blank line


/* --------------------------------------
   FUNCTIONS
-------------------------------------- */

printf("%s\n   FUNCTIONS\n%s\n\n", dashes, dashes);

    // prototype/declaration is at top of doc, definition at the bottom

    int func1 = 10, func2 = 5;
    int func3 = add(func1, func2); // calling the function and assigning the return
    printf("Add function: %i\n", func3);

    sum(10, 3); // sum prints using add - function within a function
    printf("\n");

    stat(); // the static varibale inside the stat function will go up by 1 every time it's called
    stat();

/* -------------------------
   ARRAYS
------------------------- */

printf("\n%s\n   ARRAYS\n%s\n\n", dashes, dashes);

    int data[5]; // fixed size
    int numbers[4] = {5, 6, 7, 8};
    int unfinished[10] = {3, 4}; //everything after index 1 will be 0
    int nosize[] = {5, 4, 3}; // size will automatically be 3

    // accessing elements
    printf("Index 1 of nosize is %i\n\n", nosize[1]);

    for(int i = 0; i < 4; i++){
        printf("Index %i of numbers is %i\n", i, numbers[i]);
    }

    printf("\n");

    // assigning elements

    for(int i = 0; i < 5; i++){
        data[i] = 100 + i;
        printf("Index %i of data is %i\n", i, data[i]);
    }

/* -------------------------
   ARRAYS TO FUNCTIONS
------------------------- */

printf("\n%s\n   ARRAYS TO FUNCTIONS\n%s\n\n", dashes, dashes);

    printArrayWithPointer(data);
    printf("\n");
    printArrayWithSizedArray(data);
    printf("\n");
    printArrayWithUnsizedArray(data);

    // these all operate on the memory space of data[] - changes to arr[] within these functions will replace data[]

/* -------------------------
   ARRAYS AS STRINGS
------------------------- */

printf("\n%s\n   ARRAYS AS STRINGS\n%s\n\n", dashes, dashes);

    char string[] = "String"; // adds \0 automatically, char arrays always need it (even if size is defined)
    printf("%s\n", string);

    char redundant[] = {'S', 't', 'r', 'i', 'n', 'g', '\0'};
    printf("%s\n", redundant);

/* -------------------------
   POINTERS
------------------------- */

printf("\n%s\n   POINTERS\n%s\n\n", dashes, dashes);

    /*
        * = dereference     declares a pointer type/get values back through pointers
        & = reference       gets memory address

        Pointers always store a memory address

    */

    int number = 5, *p;

    p = &number;

    printf("number: %i\n", number);
    printf("&number: %p\n", &number);
    printf("p: %p\n", p);
    printf("*p: %i\n\n", *p);

    int num = 4;
    float pi = 3.14f;

    printf("The memory address of num: %p\n\n", &num);

    int *pnum = &num; // the value of *pn is the address of num
    float *ppi = &pi;
    printf("pnum = %p\nppi = %p\n\n", pnum, ppi); // prints the memory addresses
    printf("*pnum = %i\n*ppi = %f\n", *pnum, *ppi); // prints the content of num and pi using *DEREFERENCE

/* -------------------------
   POINTER ARITHMETIC
------------------------- */

printf("\n%s\n   POINTER ARITHMETIC\n%s\n\n", dashes, dashes);

    *ppi += *pnum; // take the VALUE of where *ppi points and add the VALUE of where *pnum points to it
    printf("*ppi + *pnum = %f\n", *ppi);
    printf("The value of pi: %f\n", pi); // the pointer *ppi overwrote the content of pi

    int iAmString[5] = {1, 2, 3, 4, 5};
    int *ptr = iAmString;

    for(int i = 0; i < 5; i++){
        printf("Index %i: %i\n", i, *ptr);
        ptr++; // moves through the memory addresses - since ptr has the int type, it moves by 4
    }


/* --------------------------------
   FUNCTION WITH POINTER
-------------------------------- */

printf("\n%s\n   FUNCTION WITH POINTER\n%s\n\n", dashes, dashes);

    int xSwap = 10, ySwap = 20;

    printf("Before: %i %i\n", xSwap, ySwap);
    swapWithPointer(&xSwap, &ySwap);
    printf("After: %i %i\n\n", xSwap, ySwap);

    // the same thing with an array, still works as a pointer and changes values at the root memory address
    int arrInit[2] = {30, 40};

    printf("Before: %i %i\n", arrInit[0], arrInit[1]);
    swapWithoutPointer(arrInit);
    printf("After: %i %i\n", arrInit[0], arrInit[1]);

/* --------------------------------
   ARRAY WITH POINTER
-------------------------------- */

printf("\n%s\n   ARRAY WITH POINTER\n%s\n\n", dashes, dashes);

    // Array's names are equivalent to the memory address of their 0 index - the base address

    int aria[4] = {11, 12, 13, 14};
    int *ptrAria = aria; // no & required for array - aria is already a memory address
  //int *ptrAria = &aria[0]     <-- equivalent
    for(int i = 0; i < 4; i++){
        ptrAria = &aria[i];
        printf("%i: %p\n", i, ptrAria); // index memory locations are sequential, 4 bytes each for int, 1 for char, etc.
    }

/* --------------------------------
   SIZEOF() OPERATOR
-------------------------------- */

printf("\n%s\n   SIZEOF() OPERATOR\n%s\n\n", dashes, dashes);

    // returns size in bytes

    int byteSize = sizeof(char);
    printf("Size of char: %i\n", byteSize); // 1
    byteSize = sizeof(double);
    printf("Size of double: %i\n", byteSize); // 8
    
    char stringSize1[4];
    byteSize = sizeof(stringSize1);
    printf("Size of 4 character array: %i\n", byteSize); // 4

    int stringSize2[4];
    byteSize = sizeof(stringSize2);
    printf("Size of 4 integer array: %i\n", byteSize); // 16

    int stringSize3[26];
    byteSize = sizeof(stringSize3) / sizeof(int); // calculates the number of indexes - has to be same data type
    printf("Size of stringSize3: %i\n", byteSize);

/* --------------------------------
   TYPEDEF
-------------------------------- */

    // SHOULD BE outside of main

printf("\n%s\n   TYPEDEF\n%s\n\n", dashes, dashes);

    // a new alias for a type name
    // signed (default) v unsigned - unsigned can't hold negative values, so positive range is doubled

    typedef unsigned char byte;
    byte charbee = 'a';
    printf("A character: %c\n", charbee);

/* --------------------------------
   ENUMERATION
-------------------------------- */

printf("\n%s\n   ENUMERATION\n%s\n\n", dashes, dashes);

    // Declares integral constants - the value increments automatically

    enum Waveform {
        sine, triangle, square = 7, saw // sine = 0, triangle = 1, BUT square = 7, saw = 8, etc.
    }; // declaration SHOULD BE outside of main

    enum Waveform pick; // creates and enum variable
    pick = saw; // assign the "saw" constant
    printf("Wave: %i\n", pick);

    typedef enum Waveform wave; // reassign how to call it for simplicity

    wave pick2 = triangle; // like a pointer, pick2 contains the enum listing, not triangle
    printf("Wave: %i\n", pick2);

    // declaration and typedef combo

    typedef enum Greetings {
        hey, hi, hello
    } greet;

    greet pick3 = hi;
    printf("Greeting: %i\n\n", pick3);

//    printf("Choose a waveform (by int): ");
//    scanf("%i", &pick2);

    switch(pick2){
        case sine: // true if you type 0
            printf("You selected: Sine\n");
            break;
        case triangle:
            printf("You selected: Triangle\n");
            break;
        case square:
            printf("You selected: Square\n");
            break;
        case saw:
            printf("You selected: Saw\n");
            break;
        default:
            printf("You selected: invalid");
    }

/* --------------------------------
   STRUCTURE
-------------------------------- */

printf("\n%s\n   STRUCTURE\n%s\n\n", dashes, dashes);

    // A collection of related variable under the same name

    struct Note {
        unsigned char pitch;
        unsigned char velocity;
        unsigned char channel;
    }; // SHOULD BE outside of main

    typedef struct Note Note;

    Note note1;

    note1.pitch = 60;
    note1.velocity = 100;
    note1.channel = 1;

    printf("Pitch: %i, Velocity: %i, Channel: %i\n", note1.pitch, note1.velocity, note1.channel);

/* --------------------------------
   STRUCTURE WITH ARRAY
-------------------------------- */

printf("\n%s\n   STRUCTURE WITH ARRAY\n%s\n\n", dashes, dashes);

    Note notes[3]; // will contain 3 notes

    for(int i = 0; i < 3; i++){
        notes[i].pitch = 50 + i;
        notes[i].velocity = 70 + i;
        notes[i].channel = 3 + i;
        printf("Pitch: %i, Velocity: %i, Channel: %i\n", notes[i].pitch, notes[i].velocity, notes[i].channel);
    }

/* --------------------------------
   STRUCTURE WITH POINTER
-------------------------------- */

printf("\n%s\n   STRUCTURE WITH POINTER\n%s\n\n", dashes, dashes);

    Note n3;
    Note *pNote = &n3;

    pNote->pitch = 3; // this instead of deref*
    pNote->velocity = 4;
    pNote->channel = 5;

    printf("Pitch: %i, Velocity: %i, Channel: %i\n", pNote->pitch, pNote->velocity, pNote->channel);

/* --------------------------------
   NESTED STRUCTURE
-------------------------------- */

printf("\n%s\n   NESTED STRUCTURE\n%s\n\n", dashes, dashes);

    typedef struct TriChord {
        Note someNotes[3];
    } Triad;

    Triad triad1 = {{
        {45, 32, 4},
        {89, 103, 4},
        {55, 98, 4}
    }};

    triad1.someNotes[0].pitch = 69;

    for(int i = 0; i < 3; i++){
        printf("Pitch: %i, Velocity: %i, Channel: %i\n", 
            triad1.someNotes[i].pitch, 
            triad1.someNotes[i].velocity, 
            triad1.someNotes[i].channel);
    }

/* -------------------------
   END OF MAIN
------------------------- */

    printf("\n");
    return 0; // will stop the code from running - like a break statement for functions

}

/* ------------------------
   FUNCTION DEFINITIONS
------------------------ */

int add(int a, int b){
    return a + b;
}

void sum(int a, int b){ // void returns nothing
    printf("Sum function: %i\n", add(a, b));
}

void stat(){
    static int hi = 0; // static is still local, but continues to exist after function is done
    printf("A static variable: hi = %i\n", hi);
    hi++;
}

void printArrayWithPointer(int *arr){
    for (int i = 0; i < 5; i++){
        printf("Pointer: Index %d = %d\n", i, arr[i]);
    }  
}

void printArrayWithSizedArray(int arr[5]){
    for (int i = 0; i < 5; i++){
        printf("Sized: Index %d = %d\n", i, arr[i]);
    }
}

void printArrayWithUnsizedArray(int arr[]){
    for (int i = 0; i < 5; i++){
        printf("Unsized: Index %d = %d\n", i, arr[i]);
    }  
}

void swapWithPointer(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void swapWithoutPointer(int arra[]){
    int c = arra[0];
    arra[0] = arra[1];
    arra[1] = c;
}


/* 

-------------------------
TERMINAL CONTROLS
-------------------------

    pwd     Print Working Directory (prints the path to the directory [folder] that you are currently in).
    cd      Change Directory (changes working directory to different directory).
    cd ..   Go up a folder
    ls      Lists the files stored in the Working Directory.
    cp      Makes a copy of a file ("cp file.txt filecopy.txt" makes a copy of file.txt and names it filecopy.txt).
    mkdir   Makes a new directory (“mkdir NewDirectory” makes a new folder called “NewDirectory”).
    clear   clears the Terminal Window.
    man     opens the manual for Terminal commands ("man man" will open up the manual for the manual!).
    ~       current directory.

-------------------------
TO RUN
-------------------------

in terminal - get to proper folder using cd+tab and cd ..
make sure you save
run clang cNotes.c
now a.out exists
run ./a.out
will print in terminal

-----------------------------------
SAVE THEN COPY PASTE ME TO RUN
-----------------------------------

cd Desktop/School/Sem\ FINAL/EP-353/Notes/
clang cNotes.c -o cNotes && ./cNotes

*/