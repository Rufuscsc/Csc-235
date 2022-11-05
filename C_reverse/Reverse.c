#include <stdio.h>
#include <string.h>


/**
 * The function takes a string as an argument and prints it in reverse
 */
void reverse(char sentence[400]){

    /* Declaring two variables, i and len. */
    int i, len;
    len = strlen(sentence);
    
    /* Printing the sentence in reverse. */
    for(int i=len-1; i>=0; i--)
        printf("%c",sentence[i]);

}

/**
 * It reverses the sentence.
 */
int main(){

    /* Declaring a character array of size 400. */
    char sentence[400];

    /* Asking the user to enter a sentence to be reversed. */
    printf("Enter sentence to be reversed: ");
    gets(sentence);

    /* Calling the function reverse. */
    reverse(sentence);
   
}