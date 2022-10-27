#include <stdio.h>

void roundInt(int *d, int pos);

int main(){
    int d = 123, pos = 2;
    printf("%i", d);
    roundInt(&d, pos);
    printf(" rounded to %i\n", d);
}

void roundInt(int *d, int pos){
    int digit = 1;
    for(int i = 0; i < pos; i++){
        digit *= 10;
    }
    *d += 5 * (digit / 10);
    *d = (*d / digit) * digit;
}