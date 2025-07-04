#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <bitset>
#include <string>

#define ll long long

using namespace std;

int main() {
    //print to file
    freopen("out.txt", "w", stdout);
    for (int i = 0; i < 20000; i++) {
        cout << "if(n==" << i << "){return " << (i%2==0?"true":"false") << ";}" << endl;
    }
    //close file
    fclose(stdout);
}