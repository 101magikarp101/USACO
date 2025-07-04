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

using namespace std;

int main () {
    //print 100000 lines of strings of length 18 that randomly contain "G" and "H"
    //make a file
    freopen("e.2mil.txt", "r", stdin);
    cout << 18 << " " << 100000 << endl;
    for (int i = 0; i < 100000; i++) {
        for (int j = 0; j < 18; j++) {
            char c;
            c = getchar();
            int x = c - '0';
            if (x % 2 == 0) {
                cout << "G";
            } else {
                cout << "H";
            }
        }
        cout << endl;
    }
}