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
#define INT_MAX 2147483647

using namespace std;

ll N;

ll binexp(ll a, ll b);
ll inv(ll a);
ll di(ll a, ll b);

ll mult(ll a, ll b) {
    return (a*b)%MOD;
}

ll add(ll a, ll b) {
    return (a+b)%MOD;
}

ll di(ll a, ll b) {
    return (a*inv(b))%MOD;
}

ll inv(ll a) {
    return binexp(a, MOD-2);
}

ll binexp(ll a, ll b) {
    if (b == 1) return a;
    ll res = binexp(a, b/2);
    res = (res*res)%MOD;
    if (b%2) res = (res*a)%MOD;
    return res;
}

int main() {
    cin >> N;
    // ll ans = binexp(2, N*N);
    // ll hm = N%2==0 ? N/2*N/2 : N*N/4+1;
    // ans = add(ans, mult(2, binexp(2, hm)));
    // ll hmm = N%2==0 ? N*N/2 : N*N/2+1;
    // ans = add(ans, binexp(2, hmm));
    // ans = di(ans, 4);
    // cout << ans << endl;
    ll ans = di(add(binexp(2, N*N), add(mult(2, binexp(2, N*N/4+(N%2!=0))), binexp(2, N*N/2+(N%2!=0)))),4);
    cout << ans << endl;
}