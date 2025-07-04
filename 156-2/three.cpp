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

int T, N;

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        if (N <= 6 || N == 9) {
            cout << "NO" << endl;
        } else if (N % 3 == 1 || N % 3 == 2) {
            cout << "YES" << endl;
            cout << 1 << " " << 2 << " " << N-3 << endl;
        } else if (N % 3 == 0) {
            cout << "YES" << endl;
            cout << 1 << " " << 4 << " " << N-5 << endl;
        }
    }
}