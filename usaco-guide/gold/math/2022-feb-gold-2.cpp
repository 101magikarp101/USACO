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

ll T, K;
double bico[1001];
double npow;

double binpow(double a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    double res = binpow(a, b/2);
    res *= res;
    if (b%2) res *= a;
    return res;
}

double solve(double a, double b, double y, ll n) {
    double bn = binpow(b, n);
    double hmm = a/(b-1);
    double ans = bn*(hmm+y)-hmm;
    return ans;
}

int main () {
    cin >> T >> K;
    T--;
    bico[0] = 1;
    for (ll i = 1; i <= T; i++) {
        bico[i] = bico[i-1]*(T-i+1)/i;
    }
    npow = binpow(2, T);
    ll next = T/2+1;
    double a = 0, b = 0;
    for (ll i = next; i <= T; i++) {
        a += bico[i]*i;
    }
    for (ll i = 0; i < next; i++) {
        b += bico[i];
    }
    a /= npow;
    b /= npow;
    double y = (double)T/2.0;
    if (T == 1) {
        double ans = 1-(1/binpow(2, K));
        cout << fixed << setprecision(10) << 1+ans << endl;
        return 0;
    }
    K--;
    while (K > 0) {
        double hmm = a/(b-1);
        double d1 = next+hmm;
        double d2 = hmm+y;
        double tar = log(d1/d2);
        tar /= log(b);
        cout << "a: " << a << " b: " << b << " y: " << y << " n: " << next << " K: " << K << " hmm: " << hmm << " d1: " << d1 << " d2: " << d2 << " tar: " << tar << endl;
        cout << "tar: " << tar << endl;
        ll n = ceil(tar);
        if (K >= n) {
            K -= n;
            y = solve(a, b, y, n);
            a -= bico[next]*next/npow;
            b += bico[next]/npow;
            next++;
        } else {
            y = solve(a, b, y, K);
            K = 0;
        }
        cout << "a: " << a << " b: " << b << " y: " << y << " n: " << n << endl;
    }
    cout << fixed << setprecision(10) << 1+y << endl;
}