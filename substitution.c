/*
Vishnu Kamaraju
77vishnu.k@gmail.com
*/

/*
The key is 26 characters long and only contains alphabets. This means A-Z alphabets assign themselves to the exact same position
in the key. For example, if
Key: VCHPRZGJNTLSKFBDQWAXEUYMOI
Then A corresponds to V, B to C, C to H, and so on.
To achieve this output, simply add 13 to the input string's character if the character is a capital letter or add 7 if lower and modulo
the sum by 26. The result will be between 0-25. Match this number with that element in the KEY array and that is your cipher character
for the given character.
*/

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int substitution(char key[],string message); // function that performs encryption.

int main (int argc, string argv[])
{
    char k[26];
    if (argc<2) // if key is not mentioned.
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (argc>2) // if more than 2 arguments are mentioned.
    {
        printf("Only 2 arguments \n");
        return 1;
    }

    else
    {
        int n = strlen(argv[1]);
        if(n%26 !=0) // key length checker.
        {
            printf("Key must contain 26 characters\n");
            return 1;
        }
        int counter=0;
        while(counter<26)
        {
            if (!isalpha(argv[1][counter])) // check if any character of key is not alphabet.
            {
                printf("Key must only contain alphabetic characters\n");
                return 1;
            }
            k[counter]=argv[1][counter];
            for(int i =0; i<counter;i++) // check for repeated characters
            {
                if(argv[1][counter] == k[i])
                {
                    printf("Key must not contain repeated characters\n");
                    return 1;
                }
            }
            counter++;
        }
    }
    string input = get_string("plaintext: ");
    substitution(k,input);
}

int substitution(string key,string message)
{
    char alpha_cap[26],alpha_small[26]; // storing capital letters and small letters.
    for(int i =0; i<26; i++)
    {
        alpha_cap[i] = 65 +i;
        alpha_small[i] = 97 +i;
    }
    printf("ciphertext: ");
    for (int j =0, n = strlen(message); j<n; j++)
    {
        int counter =0;
        if (!isalpha(message[j])) // if the character is not alphabet.
        {
            printf("%c",message[j]);
        }
        else
        {
            if(isupper(message[j]))
            {
                counter = message[j] + 13; // add 13 and modulo the whole sum with 26 (below) gets a value between 0-25.
                printf("%c",toupper(key[counter%26]));   // print that corresponding letter's key value.
            }
            else
            {
                counter = message[j] + 7;
                printf("%c",tolower(key[counter%26]));   // print that corresponding letter's key value in lower case.

            }
        }
    }
    printf("\n");
    return 0;
}
