#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
    unsigned int cari[] = {71, 219, 1754, 7497, 24328, 111623,
                          413702, 1802245, 3407876, 28835843,
                          59768834, 398458881};
    int i;
    if(argc < 2){
        printf("Use : %s <password>\n", argv[0]);
        exit(-1);
    }
    if(strlen(argv[1]) != 12){
SALAH:
        printf("Password salah\n");
        exit(-1);
    }
    for(i=0; i<12; i++){
        if((unsigned int)(argv[1][i] << (2*i) ^ (12-i)) != cari[i])
            goto SALAH;
    }
    printf("Password benar\n");
}
