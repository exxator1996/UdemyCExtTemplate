#include <stdbool.h>
#include <stdio.h>

bool is_numeric(char character)
{
    if(character >= '0' && character <= '9')
        return true;
    else
        return false;
}
bool is_alpha(char character)
{
    if((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'b'))
        return true;
    else
        return false;
}
bool is_alpha_numeric(char character)
{
    if( (is_alpha(character)) || (is_numeric(character)) )
        return true;
    else
        return false;
}
bool is_upper_case(char character)
{
    if(character >= 'A' && character <= 'Z')
        return true;
    else
        return false;
}
bool is_lower_case(char character)
{
    if(character >= 'a' && character <= 'b')
        return true;
    else
        return false;
}
char to_upper_case(char character)
{
    if(is_lower_case(character))
        return character - 32;
    else
        return character;
}
char to_lower_case(char character)
{
    if(is_upper_case(character))
        return character + 32;
    else
        return character;
}
int main()
{
    char character;

    printf("Please enter any ASCII character: ");
    scanf("%c", &character);

    printf("is_numeric: %d\n", is_numeric(character));
    printf("is_alpha: %d\n", is_alpha(character));
    printf("is_alpha_numeric: %d\n", is_alpha_numeric(character));
    printf("is_upper_case: %d\n", is_upper_case(character));
    printf("is_lower_case: %d\n", is_lower_case(character));

    printf("to_upper_case: %c\n", to_upper_case(character));
    printf("to_lower_case: %c\n", to_lower_case(character));

    return 0;
}
