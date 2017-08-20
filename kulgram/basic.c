#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int basic(int x, int y,int z){
    if((x%2) != (y*z)%2){            
        z = y*x+z;                   
        if(z%2 == 0){
            z -= x;
            y += z;
        }
    }else{
        z = z*x+y;
        if(z%2 == 1){
            z += x;
            y -= z;
        }
    }
    return y+z-x;
}
int main(int argc, char* argv[]){
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int z = atoi(argv[3]);
    printf("%d\n", basic(x, y, z));
    assert(basic(x, y, z) == 31337);
}
