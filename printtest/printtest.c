#include <stdlib.h>
#include <stdio.h>
#include <linux/unistd.h>
#include <sys/syscall.h>
#include <string.h>
#define __NR_printcall 286

char *input;

long reverseString(char *str)
{
     return syscall(__NR_printcall,str);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Incorrect input format");
        exit(1);
    }

    if(reverseString(argv[1]) >= 0) {
        return 1;
    }

    printf("System call was unsuccessful");
    return -1;
}
