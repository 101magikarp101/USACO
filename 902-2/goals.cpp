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
int a[102];

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N-1; i++) {
            cin >> a[i];
        }
        ll sum = 0;
        for (int i = 0; i < N-1; i++) {
            sum += a[i];
        }
        cout << -sum << endl;
    }
}