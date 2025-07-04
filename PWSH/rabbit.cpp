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
#include <unordered_set>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct point {
    ll x, y;
};

ll N, C;
point a[100005];
ll fib[50];
unordered_set<ll> s;

int main () {
    cin >> N >> C;
    a[0] = {0, 0};
    for (int i = 1; i <= C; i++) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a, a + C + 1, [](point a, point b) {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < 45; i++) {
        fib[i] = fib[i - 1] + fib[i - 2]+1;
    }
    for (int i = 0; i < 45; i++) {
        s.insert(fib[i]);
    }
    bool ans = true;
    for (int i = 1; i <= C; i++) {
        ll d = a[i].x - a[i - 1].x+a[i].y - a[i - 1].y;
        if (s.find(d) == s.end()) {
            ans = false;
            break;
        }
    }
    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}