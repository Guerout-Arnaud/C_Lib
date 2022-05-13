#include <stdio.h>

void f1()
{
    printf("f1\n");
    return;
}

void f2()
{
    printf("f2\n");
    f1();
    return;
}

int main (void) 
{
    f1();
    f2();
    return (0);
}