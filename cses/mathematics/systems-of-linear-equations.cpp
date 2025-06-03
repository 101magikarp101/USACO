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

int N, M;
vt<vt<int>> m;

void red(vt<int> &a, vt<int> &b, int j) {
    if (b[j] == 0) return;
    int hm = b[j];
    rep(i,j,M+1) {
        b[i] = sub(b[i], mul(a[i], hm));
    }
}

vt<int> solve() {
    // 1: Echelon form
    int fixed = 0;
    rep(j,0,M) {
        int idx = -1;
        rep(i,fixed,N) {
            if (m[i][j] != 0) {
                idx = i;
                break;
            }
        }
        if (idx == -1) {
            continue;
        }
        swap(m[fixed], m[idx]);
        int in = inv(m[fixed][j]);
        rep(i,j,M+1) {
            m[fixed][i] = mul(m[fixed][i], in);
        }
        rep(i,fixed+1,N) {
            red(m[fixed], m[i], j);
        }
        fixed++;
    }
    // 2: Reduced row echelon form
    rrep(i,N-1,0) {
        bool found = 0;
        rep(j,0,M) {
            if (m[i][j] != 0) {
                rep(k,0,i) {
                    m[k][M] = sub(m[k][M], mul(m[k][j], m[i][M]));
                    m[k][j] = 0;
                }
                found = 1;
                break;
            }
        }
        if (found) continue;
        if (m[i][M] != 0) {
            return {-1};
        }
    }
    // 3: Get solution
    vt<int> ans(M,0);
    rep(i,0,N) {
        rep(j,0,M) {
            if (m[i][j] != 0) {
                ans[j] = m[i][M];
                break;
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> M;
    rep(i,0,N) {
        vt<int> a(M+1);
        rep(j,0,M+1) cin >> a[j];
        m.pb(a);
    }
    vt<int> ans = solve();
    each(i,ans) {
        cout << i << " ";
    }
    cout << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}