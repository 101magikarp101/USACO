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

int T, N;
int cnt[1000005][3];
int pot[1000005][3];

int ad(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
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
    cin >> T;
    while (T--) {
        cin >> N;
        cnt[2][0] = 1;
        pot[2][0] = 1;
        vt<int> ncnt(3,0);
        vt<int> npot(3,0);
        rep(i,3,N+1) {
            rep(j,0,3) {
                ncnt[j] = cnt[i-1][j];
                npot[j] = pot[i-1][j];
            }

            npot[1] = ad(npot[1], mul(pot[i-1][0],i-1));
            ncnt[1] = ad(ncnt[1], pot[i-1][0]);

            npot[2] = ad(npot[2], mul(pot[i-1][1],i));
            ncnt[2] = ad(ncnt[2], pot[i-1][1]);

            npot[2] = ad(npot[2], mul(pot[i-1][2],i));
            ncnt[2] = ad(ncnt[2], pot[i-1][2]);

            rep(j,0,3) {
                cnt[i][j] = ncnt[j];
                pot[i][j] = npot[j];
            }
            rep(j,0,3) {
                ncnt[j] = 0;
                npot[j] = 0;
            }
        }
        int ans = 0;
        rep(i,0,3) {
            ans = ad(ans, cnt[N][i]);
        }
        cout << ans << endl;
    }
    return 0;
}