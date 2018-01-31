#include <stdio.h>

void main()
{
    int x = 0;
    while(x<10) {
        printf("Not Hello World!\n");
        if (x < 9){
            for(int y=0; y<=x; y=y+1) {
                printf(" ");
            }
        }
        x = x + 1;
    }
}
