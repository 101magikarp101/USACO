#include <stdio.h>
#include <stdlib.h>

int main() {
    int * a = (int *)malloc(4*sizeof(int));
    int * c = a + 2;
    char *d = (char *)(a+2);

    *d = 0x10;
    c[1] = 0x04c;
    c[1] += c[0];
    for (int i = 0; i < 4; i++) {
        printf("%x\n", a[i]);
    }
}

