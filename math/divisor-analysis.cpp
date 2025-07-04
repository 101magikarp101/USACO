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

struct prime {
    ll p, e;
};

int N;
prime a[100005];

ll add(ll a, ll b) {
    return (a+b)%MOD2;
}

ll mult(ll a, ll b) {
    return (a*b)%MOD2;
}

ll binpow(ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    ll res = binpow(a, b/2);
    res = mult(res, res);
    if (b%2 == 1) {
        res = mult(res, a);
    }
    return res;
}

ll di(ll a, ll b) {
    return mult(a, binpow(b, MOD2-2));
}

int main () {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i].p >> a[i].e;
    }
    ll num = 1;
    ll num1 = 1;
    for (int i = 0; i < N; i++) {
        num = mult(num, a[i].e+1);
        num1 *= a[i].e+1;
        num1 %= MOD2-1;
    }
    ll sum = 1;
    ll M = 1;
    ll sqm = 1;
    bool sq = true;
    for (int i = 0; i < N; i++) {
        if (a[i].e%2 == 1) {
            sq = false;
        }
        M = mult(M, binpow(a[i].p, a[i].e));
        if (sq) {
            sqm = mult(sqm, binpow(a[i].p, a[i].e/2));
        }
        sum = mult(sum, di(binpow(a[i].p, a[i].e+1)-1, a[i].p-1));
    }
    // cout << "M: " << M << endl;
    cout << binpow(M, num1) << endl;
    cout << "num1: " << num1 << endl;
    ll pro = binpow(M, num1/2);
    if (sq) {
        pro = mult(pro, sqm);
    }
    cout << num << " " << sum << " " << pro << endl;
}