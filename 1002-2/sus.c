#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

unsigned char code[] = {
    0xb8, 0x2a, 0x00, 0x00, 0x00,
    0xc3
};

int main() {
    void *exec_mem = mmap(NULL, sizeof(code), PROT_READ | PROT_WRITE | PROT_EXEC,
                          MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (exec_mem == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    memcpy(exec_mem, code, sizeof(code));

    int (*func)() = (int (*)())exec_mem;
    int result = func();

    printf("The result is: %d\n", result);
    munmap(exec_mem, sizeof(code));
    return 0;
}