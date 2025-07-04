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
ll a, b;

ll gcd (ll a, ll b) {
    if (a == 0) return b;
    return gcd(b%a, a);
}

ll lcm (ll a, ll b) {
    return (a*b)/gcd(a, b);
}

int main () {
    cin >> T;
    while (T--) {
        cin >> a >> b;
        ll g = gcd(a, b);
        ll l = lcm(a, b);
        if (l == b) {
            cout << b*b/g << endl;
        } else {
            cout << l << endl;
        }
    }
}