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
#define repl(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define rrepl(i,a,b) for(ll i=a;i>=b;i--)
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
string b[200005];
vt<pii> c[200005][2];

int ad(int a, int b) {
    a+=b;
    if (a>=MOD2) a-=MOD2;
    return a;
}

int sub(int a, int b) {
    a-=b;
    if (a<0) a+=MOD2;
    return a;
}

int mul(int a, int b) {
    return (int)((a*1LL*b)%MOD2);
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
    return binpow(a, MOD2-2);
}

int di(int a, int b) {
    return mul(a, inv(b));
}

int c4(int n) {
    return mul(mul(mul(n, n-1), n-2), n-3);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    vt<int> ten(10);
    ten[0] = 1;
    rep(i,1,10) {
        ten[i] = mul(ten[i-1], 10);
    }

    cin >> N;
    rep(i,0,N) {
        cin >> a[i];
    }
    uset<int> st;
    umap<int,uset<int>> pre, suf; // i apologize in advance for making this problem
    umap<int,uset<int>> pre2, suf2;
    rep(i,0,N) {
        st.insert(a[i]);
    }
    rep(i,0,N) {
        b[i] = to_string(a[i]);
        int n = sz(b[i]);
        int l = 0;
        int r = a[i];
        rep(j,0,n-1) {
            l = l*10 + b[i][j]-'0';
            r = r - (b[i][j]-'0')*ten[n-j-1];
            if (b[i][j+1] != '0') {
                if (st.count(r)) {
                    pre[l].insert(r);
                    pre2[l].insert(a[i]);
                    c[i][0].pb({l,r});
                }
            }
            if (b[i][j+1] != '0') {
                if (st.count(l)) {
                    suf[r].insert(l);
                    suf2[r].insert(a[i]);
                    c[i][1].pb({r,l});
                }   
            }
        }
    }
    int ans = 0;
    rep(i,0,N) {
        each(j,c[i][0]) {
            pre[j.x].erase(j.y);
        }
        each(j,c[i][1]) {
            suf[j.x].erase(j.y);
        }
        int n = sz(b[i]);
        int l = 0;
        int r = a[i];
        rep(j,0,n-1) {
            l = l*10 + b[i][j]-'0';
            r = r - (b[i][j]-'0')*ten[n-j-1];
            if (b[i][j+1] != '0') {
                int res = pre[r].size();
                if (pre[r].count(a[i])) res--;
                if (pre[r].count(l)) res--;
                if (pre2[r].count(l)) res--;
                // cout << "i: " << i << " j: " << j << " l: " << l << " r: " << r << " lres: " << res*st.count(l) << endl;
                ans = ad(ans, res*st.count(l));
            }
            if (b[i][j+1] != '0') {
                int res = suf[l].size();
                if (suf[l].count(a[i])) res--;
                if (suf[l].count(r)) res--;
                if (suf2[l].count(r)) res--;
                // cout << "i: " << i << " j: " << j << " l: " << l << " r: " << r << " rres: " << res*st.count(r) << endl;
                ans = ad(ans, res*st.count(r));
            }
        }
        each(j,c[i][0]) {
            pre[j.x].insert(j.y);
        }
        each(j,c[i][1]) {
            suf[j.x].insert(j.y);
        }
    }
    ans = di(sub(c4(N), ans), 2);
    cout << ans << endl;


    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}