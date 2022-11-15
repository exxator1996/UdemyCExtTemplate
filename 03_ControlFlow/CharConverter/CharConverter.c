#include <stdbool.h>
#include <stdio.h>

int main()
{
    char character;

    printf("Please enter any ASCII character: ");
    scanf("%c", &character);

    // is numeric
    if(character >= '0' && character <= '9')
        printf("Is numeric \n");
    // is upper case
    if(character >= 'A' && character <= 'Z')
        printf("Is upper case\n");
    // is lower case
    if(character >= 'a' && character <= 'b')
        printf("Is lower case\n");
    // is alpha
    if((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'b'))
        printf("Is alpha\n");
    // is alpha numeric
    if((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'b') || (character >= '0' && character <= '9'))
        printf("Is alpha numeric\n");
    // to upper case
    if(character >= 'a' && character <= 'b')
        printf("To upper case: %c\n", character - 32);
    // to lower case
    if(character >= 'A' && character <= 'Z')
        printf("To lower case: %c\n", character + 32);
    return 0;
}
