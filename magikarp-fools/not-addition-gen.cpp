#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n = opt<int>(1);
    rnd.setSeed(n);
    printf("%d %d %lld\n", rnd.next(1, 1000000000), rnd.next(1, 1000000000), rnd.next(1LL, 1000000000000000000LL));
}