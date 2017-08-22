// gcc -m32 -no-pie -fno-pic pass.c -o pass
#include <stdio.h>
#include <string.h>

char buffer[32];

int main()
{
    int I, x;
    char KEY[]      = "Reversing.ID Crackme";
    int  SOLUSI[15] = { 41, 17, 2, 95, 19, 10, 70, 19, 192, 160, 54, 15, 28, 82, 89 };
    int  KEYOUT[15];
    
    printf("Masukkan password: ");
    scanf("%s", buffer);
    for (x = 0, I = 3; x < 15; x++, I = (I+1) % 255)
    {
        KEYOUT[x] = (buffer[x] + I ^ KEY[I]) % 255;
        if (SOLUSI[x] != KEYOUT[x])
            break;
    }

    if (x >= 15)
        printf("Itu dia password yang benar\n");
    else
        printf("Password salah! Coba lagi\n");
}