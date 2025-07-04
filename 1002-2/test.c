#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *str = "ra2342afafaf";
    int r = 0;
    sscanf(str, "r%d", &r);
    printf("%d\n", r);
}