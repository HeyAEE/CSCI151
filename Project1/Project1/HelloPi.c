#include <stdio.h>
#include <math.h>

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
        printf("Also... ");
        //printf("%.2f \n", M_PI);
        x = x + 1;
    }
}
