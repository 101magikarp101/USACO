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
#include <unordered_map>
#include <deque>
#include <climits>

using namespace std;

#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int C, D, X;
int T;

int cnt (int x) {
    int y = 0;
    for (int i = 2; i*i <= x; i++) {
        if (x%i == 0) {
            while (x%i == 0) {
                x /= i;
            }
            y++;
        }
    }
    if (x > 1) {
        y++;
    }
    return y;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> C >> D >> X;
        int ans = 0;
        vector<int> v;
        for (int i = 2; i*i <= X; i++) {
            if (X%i == 0) {
                v.push_back(i);
                if (i*i != X) {
                    v.push_back(X/i);
                }
            }
        }
        cout << ans << endl;
    }
}