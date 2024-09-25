#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define uset unordered_set
#define umap unordered_map
#define mset multiset
struct pii {
    int x, y;
    bool operator<(const pii &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pii &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pii &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pii &a) const { return x != a.x || y != a.y; }
    pii operator+(const pii &a) const { return {x+a.x, y+a.y}; }
    pii operator-(const pii &a) const { return {x-a.x, y-a.y}; }
    pii operator*(const int &a) const { return {x*a, y*a}; }
    pii operator/(const int &a) const { return {x/a, y/a}; }
};
struct pll {
    ll x, y;
    bool operator<(const pll &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pll &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pll &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pll &a) const { return x != a.x || y != a.y; }
    pll operator+(const pll &a) const { return {x+a.x, y+a.y}; }
    pll operator-(const pll &a) const { return {x-a.x, y-a.y}; }
    pll operator*(const ll &a) const { return {x*a, y*a}; }
    pll operator/(const ll &a) const { return {x/a, y/a}; }
};

ll ad(ll a, ll b) {
    return (a+b)%MOD2;
}

ll sub(ll a, ll b) {
    return (a-b+MOD2)%MOD2;
}

ll mul(ll a, ll b) {
    return (a*b)%MOD2;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b%2) res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

ll inv(ll a) {
    return binpow(a, MOD2-2);
}

ll di(ll a, ll b) {
    return mul(a, inv(b));
}

int N, M;
ll dp[1<<10][1005];
vt<int> a[1<<10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int m = 0; m < 1<<N; m++) {
        for (int n = 0; n < 1<<N; n++) {
            // cout << "check " << n << endl;
            bool good = 1;
            for (int i = 0; i < N; i++) {
                if (m&(1<<i)) {
                    if ((n&(1<<i)) != 0) {
                        good = 0;
                        break;
                    }
                } else {
                    if ((n&(1<<i)) == 0) {
                        if (i+1 >= N || (n&(1<<(i+1)))!=0 || (m&(1<<(i+1)))!=0) {
                            // cout << "n1" << endl;
                            good = 0;
                            break;
                        }
                        i++;
                    }
                }
            }
            if (good) a[m].pb(n);
        }
    }
    // for (int m = 0; m < 1<<N; m++) {
    //     cout << "m: " << bitset<10>(m) << endl;
    //     for (int n : a[m]) {
    //         cout << bitset<10>(n) << " " << endl;
    //     }
    // }
    dp[0][1] = 1;
    for (int i = 1; i <= M; i++) {
        for (int m = 0; m < 1<<N; m++) {
            for (int n : a[m]) {
                dp[n][i+1] = ad(dp[n][i+1], dp[m][i]);
            }
        }
    }
    cout << dp[0][M+1] << endl;
    return 0;
}