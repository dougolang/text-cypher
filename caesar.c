//a program that converts messages to secret code
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//user provides a command line argument that gets the key (will be a letter or positive int) (use argv)

bool only_digits(string s);
char rotate(int key, char c);
int main(int argc, string argv[])
{

//make sure there is a digit char in argv1
    if (argv[1] == NULL || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
//convert argv1 from a string to an int
    int key = atoi(argv[1]);

//take user input
    string input = get_string("Plain Text: ");
    printf("Cipher Text: ");
    for( int i = 0; i < strlen(input); i++)
    {
        char letter = input[i];
        char updatedLetter = rotate(key, letter);
        printf("%c", updatedLetter);
    }
    printf("\n");

    return 1;
}

bool only_digits(string s)
{
    int arglength = strlen(s);
    for (int i = 0; i < arglength; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

//rotate the characters by the key amount and printf the results

char rotate(int key, char c)
{
    int asciiEquiv = (int)c;
    int change = 65;

    if (!isalpha(c))
    {
        return c;
    }
    if (islower(c))
    {
        change = 97;
    }
    int alphaIndex = asciiEquiv - change;
    int newIndex = (alphaIndex + key) % 26;
    int newAscii = newIndex + change;
    char newLetter = (char)newAscii;
    return newLetter;
}