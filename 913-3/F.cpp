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
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 1000000007

using namespace std;

int T, N;
int a[100004];

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        if (N==1) {
            cout << 0 << endl;
            continue;
        }
        int pos1 =-1, pos2=-1;
        for (int i = 1; i < N; i++) {
            if (a[i] < a[i-1]) {
                if (pos1 == -1) {
                    pos1 = i;
                } else {
                    pos1 = -1;
                    break;
                }
            }
        }
        for (int i = N-2; i >= 0; i--) {
            if (a[i] < a[i+1]) {
                if (pos2 == -1) {
                    pos2 = i;
                } else {
                    pos2 = -1;
                    break;
                }
            }
        }
        int res = 0;
        if (is_sorted(a, a+N)) {
            res = 0;
        } else if (pos1 == -1) {
            res = -1;
        } else {
            if (a[N-1] <= a[0]) {
                res = min(N-pos1, pos1+2);
            } else {
                res = -1;
            }
        }
        int res2 = 0;
        if (is_sorted(a, a+N, greater<int>())) {
            res2 = 1;
        } else if (pos2 == -1) {
            res2 = -1;
        } else {
            if (a[0] <= a[N-1]) {
                res2 = min(N-pos2, pos2+2);
            } else {
                res2 = -1;
            }
        }
        // cout << "pos1: " << pos1 << " pos2: " << pos2 << endl;
        // cout << "res: " << res << " res2: " << res2 << endl;
        if (res == -1 && res2 == -1) {
            cout << -1 << endl;
        } else if (res == -1) {
            cout << res2 << endl;
        } else if (res2 == -1) {
            cout << res << endl;
        } else {
            cout << min(res, res2) << endl;
        }
    }
}