#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
// These are my functions
    bool only_digits(string key);
    char rotate(char c, int i);

// Check if the user has inputted a single thing into the terminal. If not, remind them of usage and return 1

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

// Call function to check if user has inputted only a digit. If not, remind them of usage and return 1
    if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

// Change the string into an int
    int key = atoi(argv[1]) % 26;

// Prompt user for string
    string text = get_string("plaintext: ");

// Shift letters by key and print them out
    printf("ciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char o = rotate(text[i], key);
        printf("%c", o);
    }
    printf("\n");
    return 0;
}


// This function checks if the key is only digits
bool only_digits(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (isdigit(key[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

// This function rotates the characters according to the key
char rotate(char x, int key)
{
    if (isspace(x) || isdigit(x) || ispunct(x))
    {
        return x;
    }
    else if (isupper(x))
    {
        int y = (int) x - 65;
        y = y + key;
        y = y % 26;
        y = y + 65;
        return y;
    }
    else if (islower(x))
    {
        int y = (int) x - 97;
        y = y + key;
        y = y % 26;
        y = y + 97;
        return y;
    }
    else
    {
        return x;
    }
}

