#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool string_starts_with(char *string, char *substr)
{
    if (string == NULL || substr == NULL)
        return false;

    if (strncmp(string, substr, strlen(substr)) == 0)
        return true;
    else
        return false;
}

bool string_ends_with(char *string, char *substr)
{
    if (string == NULL || substr == NULL)
        return false;

    char *stringCheckPos = strchr(string, '\0') - strlen(substr);

    if (strncmp(stringCheckPos, substr, strlen(substr)) == 0)
        return true;
    else
        return false;
}

char *string_find_first_not_of(char *string, char *substr)
{
    if (string == NULL || substr == NULL)
        return NULL;

    if(string_starts_with(string, substr))
        return string + strlen(substr);
    else
        return NULL;
}

int main()
{
    char text[50] = "jan schaffranek";

    printf("string_starts_with: %d\n", string_starts_with(text, "jan"));
    printf("string_ends_with: %d\n", string_ends_with(text, "anek"));

    printf("string_starts_with: %d\n", string_starts_with(text, "an"));
    printf("string_ends_with: %d\n", string_ends_with(text, "ane"));

    printf("string_find_first_not_of: %s\n", string_find_first_not_of(text, "jan "));
    printf("string_find_first_not_of: %s\n", string_find_first_not_of(text, "ja"));

    return 0;
}
