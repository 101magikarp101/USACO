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
#include <chrono>

#define ll long long

using namespace std;


int T, N;
int a[101];

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        if (N%2 == 0) {
            cout << 2 << endl;
            cout << 1 << " " << N << endl;
            cout << 1 << " " << N << endl;
        } else {
            cout << 4 << endl;
            cout << 1 << " " << N << endl;
            cout << 1 << " " << N-1 << endl;
            cout << N-1 << " " << N << endl;
            cout << N-1 << " " << N << endl;
        }
    }
}