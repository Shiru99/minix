#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <stdlib.h>

void forkPrint(char str[], int i, int len){
    
    if(i <= len){
        int id = fork();
        if(id > 0){ 
            printf("%c %d\n", str[i], id);
            sleep(rand()%4 + 1);
            forkPrint(str, i+1, len);
        }
    }
    return;  
}

int main() 
{ 
    char str[] = "Hello World";
    setbuf(stdout, NULL);
    forkPrint(str, 0, 10);
    return 0; 
}