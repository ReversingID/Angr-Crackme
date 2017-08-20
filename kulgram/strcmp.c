#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char pass[14];
    printf("Masukkan password : ");
    fgets(pass, 13, stdin);
    if(!strcmp(pass, "C0D3BR34K3R\n"))
    {
        printf("Password benar\n");
    }
    else
    {
        printf("Password salah\n");
    }
}
