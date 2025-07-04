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

int T;

int main() {
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n %3==0) {
            cout << "Second" << endl;
        } else {
            cout << "First" << endl;
        }
    }
}