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

int T, N, K;
int c[200001];

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            cin >> c[i];
        }
        int count = 0;
        int l = -1;
        for (int i = 0; i < N; i++) {
            if (c[i] == c[0]) {
                count++;
            }
            if (count == K) {
                l = i;
                break;
            }
        }
        if (l == -1) {
            // cout << 1 << endl;
            cout << "NO" << endl;
            continue;
        }
        if (c[N-1] == c[0]) {
            // cout << 2 << endl;
            cout << "YES" << endl;
            continue;
        }
        count = 0;
        int r = -1;
        for (int i = N-1; i >= 0; i--) {
            if (c[i] == c[N-1]) {
                count++;
            }
            if (count == K) {
                r = i;
                break;
            }
        }
        if (r == -1) {
            // cout << 3 << endl;
            cout << "NO" << endl;
            continue;
        }
        if (l < r) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        memset(c, 0, sizeof(c));
    }
}