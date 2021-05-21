#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

int main(int ac, char **av)
{
    int fw = open("ch.txt", O_APPEND | O_WRONLY);
    dup2(fw, 1);
    fprintf(, "Comment tu vas\n");
}