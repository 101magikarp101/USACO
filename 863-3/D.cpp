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

int T;
ll fib[50];
int N;

bool check(ll x, ll y, ll w, ll h) {
    if (h == 1) return true;
    if (x <= fib[w-2]) {
        return check(y, x, h, w-2);
    } else if (x >= fib[w-1]+1) {
        return check(y, x-fib[w-1], h, w-2);
    } else {
        return false;
    }
}

int main () {
    cin >> T;
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i <= 45; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    while (T-- > 0) {
        cin >> N;
        ll x, y;
        cin >> y >> x;
        bool ans = check(x, y, N+1, N);
        if (ans) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}