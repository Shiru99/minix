#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void printHello(char str[], int i, int len)
{
    if (i <= len)
    {
        int id = fork();
        if (id > 0)
        {
            printf("%c %d\n", str[i], id);
            sleep((rand() % 4) + 1);
            printHello(str, i + 1, len);
        }
    }
    return;
}

int main()
{
    char str[] = "Hello World";
    setbuf(stdout, NULL);
    printHello(str, 0, 10);
    return 0;
}