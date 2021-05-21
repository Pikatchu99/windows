/*
** EPITECH PROJECT, 2020
** test [WSL: Ubuntu]
** File description:
** palindrome.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>

char *reverse_string(char *str)
{
    int i = 0, j = 0, len = 0;
    for (i = 0; str[i] != '\0'; i++);
    char *cpy = malloc(sizeof(char) * (i + 2));
    len = i, i -= 1;
    for (j = 0; j < len && i >= 0; i--) {
        cpy[j] = str[i];
        j++;
    }
    cpy[j] = '\0';
    return (cpy);
}

char *lowercase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    return (str);
}

void palindrome(char *str_1, char *str_2)
{
    // setlocale(LC_ALL, "");
        setlocale(LC_ALL, "en_US.UTF-8");
    int i = 0, j = strlen(str_2) - 1;
    // printf("str1 = %s\n str2 = %s", str_1, str_2);
    for (i = 0; str_1[i] != '\0' && str_2[i]; i++) {
        printf("%c       %c\n", str_1[i], str_2[i]);
        // if (str_1[i] == str_2[i])
        //     continue;
        // else {
        //     fprintf(stderr, "Thiw word %c%s%c is not in a palindrome\n", 34, str_1, 34);
        //     exit (0);
        // }
    }
    // fprintf(stderr, "Thiw word %c%s%c is a palindrome\n", 34, str_1, 34);
}

int main(int ac, char **av)
{
    char *str = lowercase(av[1]);
    str = reverse_string(av[1]);
    palindrome(av[1], str);
    return (0);    
}