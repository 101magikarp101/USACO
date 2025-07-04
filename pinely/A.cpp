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
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

struct point {
    int x, y;
};

int T, N;
point a[102];



int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
        for (int i = 0; i < N; i++) {
            cin >> a[i].x >> a[i].y;
        }
        bool ans = false;
        bool res = true;
        for (int i = 0; i < N; i++) {
            if (a[i].x < 0) {
                res = false;
                break;
            }
        }
        ans |= res;
        res = true;
        for (int i = 0; i < N; i++) {
            if (a[i].x > 0) {
                res = false;
                break;
            }
        }
        ans |= res;
        res = true;
        for (int i = 0; i < N; i++) {
            if (a[i].y < 0) {
                res = false;
                break;
            }
        }
        ans |= res;
        res = true;
        for (int i = 0; i < N; i++) {
            if (a[i].y > 0) {
                res = false;
                break;
            }
        }
        ans |= res;
        cout << (ans ? "YES" : "NO") << endl;
    }
}