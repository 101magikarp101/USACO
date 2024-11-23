#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)((x).size())
#define uset unordered_set
#define umap unordered_map
#define mset multiset
#define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define each(i,a) for(auto &i:a)
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

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

int N;
int a[200005];
int mob[1000005];
int cnt[1000005];

void mobius(int n) {
    mob[1] = -1;
    for (int i = 1; i <= n; i++) {
        if (mob[i]) {
            mob[i] = -mob[i];
            for (int j = i+i; j <= n; j += i) {
                mob[j] += mob[i];
            }
        }
    }
    mob[1] = 0;
    rep(i,1,n+1) {
        mob[i] = -mob[i];
    }
}

int ad(int a, int b) {
    return ((a+b)%MOD+MOD)%MOD;
}

int sub(int a, int b) {
    a-=b;
    if (a<0) a+=MOD;
    return a;
}

int mul(int a, int b) {
    return (int)((a*1LL*b)%MOD);
}

int binpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b&1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return binpow(a, MOD-2);
}

int di(int a, int b) {
    return mul(a, inv(b));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    mobius(1000000);
    cin >> N;
    rep(i,0,N) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i*i <= a[0]; i++) {
        if (a[0]%i == 0) {
            cnt[i]++;
            if (i*i != a[0]) cnt[a[0]/i]++;
        }
    }
    rep(i,1,N) {
        int x = 0;
        for (int j = 1; j*j <= a[i]; j++) {
            if (a[i]%j == 0) {
                x = ad(x, mob[j]*cnt[j]);
                if (j*j != a[i]) x = ad(x, mob[a[i]/j]*cnt[a[i]/j]);
            }
        }
        // cout << "x: " << x << endl;
        for (int j = 1; j*j <= a[i]; j++) {
            if (a[i]%j == 0) {
                cnt[j] = ad(cnt[j], x);
                if (j*j != a[i]) cnt[a[i]/j] = ad(cnt[a[i]/j], x);
            }
        }
        if (i == N-1) {
            ans = x;
        }
    }
    cout << ans << endl;
    return 0;
}