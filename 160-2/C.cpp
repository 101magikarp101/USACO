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
#include <unordered_set>

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

int M;
ll a[30];

bool solve(ll x) {
    ll tot = x;
    for (int i = 29; i >= 0; i--) {
        ll cur = (1 << i);
        if (a[i] > 0) {
            ll res = min(tot/cur, a[i]);
            tot -= res*cur;
        }
        if (tot == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> M;
    for (int i = 0; i < M; i++) {
        int x;
        ll y;
        cin >> x >> y;
        if (x == 1) {
            a[y]++;
        } else {
            bool res = solve(y);
            if (res) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}