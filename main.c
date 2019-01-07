// Author       :   Alex Kourkoumelis
// Date         :   2/17/2018
// Title        :   WordEncryption
// Description  :   Takes a single word input and integer input from the user
//              :   then converts each letter by the integer given
//              :   displays encoded word

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main() {
    printf("Hello, World!\n");

    //takes a single word as input
    char decoded[128];
    printf("\nEnter a word:\t\t");
    scanf("%s", decoded);

    //takes an integer as input
    char offsetChar[128];
    printf("Enter a number:\t\t");
    scanf("%s", offsetChar);

    //converts integer input from character to integer
    int offset;
    offset = atoi(offsetChar);

    //if number entered is larger than 26(alphabet length) then it's modded by 26
    if(offset > 26){
        offset = offset%26;
    }

    //for debugging
//    printf("\nWord chosen was:\t%s", decoded);
//    printf("\nNumber chosen was:\t%d\n", offset);


    char encoded[128];
    int tempChar;

    //for loop to convert letter by letter
    for (int i = 0; i < strlen(decoded); i++){

        //each letter is converted to an integer
        tempChar = decoded[i];

        //then the offset is added
        tempChar += offset;

        //if the offset causes the letter to go past the end of the alphabet
        //then it wraps back around
        if(tempChar > 122){
            tempChar -= 26;
        }

        //saves each new character into the encoded char array
        encoded[i] = tempChar;

    }

    //display results
    printf("\nDecoded word:\t\t%s", decoded);
    printf("\nEncoded word:\t\t%s", encoded);

    return 0;
}