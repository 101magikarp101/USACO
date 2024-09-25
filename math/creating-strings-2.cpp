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



string s;
ll fac[1000003];
ll cnt[26];

int main () {
    cin >> s;
    int N = s.size();
    fac[0] = 1;
    for (int i = 1; i <= N; i++) {
        fac[i] = mult(fac[i-1], i);
    }
    for (int i = 0; i < N; i++) {
        cnt[s[i]-'a']++;
    }
    ll ans = fac[N];
    for (int i = 0; i < 26; i++) {
        ans = di(ans, fac[cnt[i]]);
    }
    cout << ans << endl;
}