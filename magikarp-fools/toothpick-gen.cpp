#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = opt<int>(1);
    printf("%d", rnd.next(1, 9));
    for (int i = 1; i < n; i++) {
        printf("%d", rnd.next(0, 9));
    }
    printf("\n");
}