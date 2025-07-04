#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    printf("num args: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("arg[%d]: %s\n", i, argv[i]);
    }
    int sum = 0;
    FILE* file = fopen("test.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    int n; fscanf(file, "%d", &n);
    printf("n: %d\n", n);
    for (int i = 0; i < n; i++) {
        int x;
        fscanf(file, "%d", &x);
        sum += x;
    }
    printf("Sum: %d\n", sum);
}