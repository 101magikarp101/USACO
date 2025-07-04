#include "testlib.h"
#include <iostream>
 
using namespace std;
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
 
    /* Read number from command line. */
    int n = opt<int>(1);
    rnd.setSeed(n);
 
    println(rnd.next("[a-zA-Z0-9]{4}"));
}
