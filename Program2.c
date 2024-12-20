#include <stdio.h>
#include <ctype.h>

void Vowel_Cons_Count(const char *str, int *vowels, int *consonants)
{
    *vowels = 0;
    *consonants = 0;
    char c;

    for (int i = 0; str[i] != '#'; i++)
    {
        c = tolower(str[i]);
        if ((c >= 'a' && c <= 'z') &&
            (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'))
        {
            (*vowels)++;
        }
        else if (c >= 'a' && c <= 'z')
        {
            (*consonants)++;
        }
    }
}

int main()
{
    char text[100];
    int vowels = 0, consonants = 0;

    printf("Enter a line of text (max 80 characters, terminated by '#'):\n");

    fgets(text, sizeof(text), stdin);


    Vowel_Cons_Count(text, &vowels, &consonants);

    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);

    return 0;
}