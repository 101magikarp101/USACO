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

struct DSU {
    vector<int> e;
    DSU(int N) { e = vector<int>(N, -1); }

    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
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

struct mat {
    vt<vt<int>> a;
    int n, m;
    mat(int n, int m) : n(n), m(m) {
        a.resize(n, vt<int>(m));
    }
    mat operator*(const mat &b) {
        mat c(n, b.m);
        rep(i,0,n) {
            rep(j,0,b.m) {
                rep(k,0,m) {
                    c.a[i][j] = ad(c.a[i][j], mul(a[i][k], b.a[k][j]));
                }
            }
        }
        return c;
    }
};

mat binpow(mat a, ll b) {
    mat res(a.n, a.m);
    rep(i,0,a.n) res.a[i][i] = 1;
    while (b) {
        if (b&1) res = res*a;
        a = a*a;
        b >>= 1;
    }
    return res;
}

ll N, M;
int adj[100][100];
vt<vt<int>> hm;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

bool valid(vt<int> &v) {
    vt<int> cnt(sz(v),0);
    rep(i,0,M) {
        int x = i+dx[v[i]];
        if (x<0||x>=M) return 0;
        if (dy[v[i]] == 0) {
            cnt[x]++;
        }
    }
    rep(i,0,M) if (cnt[i] > 1) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int siz = 1<<(2*M);
    rep(m,0,siz) {
        vt<int> a(M);
        rep(i,0,M) a[i] = (m>>(2*i))&3;
        if (!valid(a)) continue;
        hm.pb(a);
    }
    // cout << "hm: " << endl;
    // each(i,hm) {
    //     each(j,i) cout << j << " ";
    //     cout << endl;
    // }
    mat matrix(siz,siz);
    rep(i,0,siz) {
        vt<int> a(M);
        int x = i;
        rep(j,0,M) {
            a[j] = x%4;
            x /= 4;
        }
        rep(j,0,sz(hm)) {
            vt<int> b = hm[j];
            bool ok = 1;
            rep(k,0,M) {
                if ((a[k] == 2 || a[k] == 3) && b[k] == 2) {
                    ok = 0;
                    break;
                }
                if ((a[k] == 0 || a[k] == 1) && b[k] != 2) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) continue;
            vt<int> c(M);
            rep(k,0,M) {
                if (a[k]%2 == 1) {
                    c[k]++;
                }
            }
            rep(k,0,M) {
                int x = k+dx[b[k]];
                int y = dy[b[k]];
                if (y == 0) {
                    c[x]++;
                }
            }
            rep(k,0,M) {
                if (c[k] > 1) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) continue;
            vt<int> d(M);
            rep(k,0,M) {
                if (c[k] == 1) {
                    d[k]+=2;
                }
            }
            rep(k,0,M) {
                if (b[k] == 0) {
                    d[k]++;
                }
            }
            int y = 0;
            for (int k = M-1; k >= 0; k--) {
                y *= 4;
                y += d[k];
            }
            // cout << "i: " << i << " j: " << j << " y: " << y << endl;
            matrix.a[i][y]++;
        }
    }
    // cout << "matrix: " << endl;
    // rep(i,0,siz) {
    //     rep(j,0,siz) {
    //         cout << matrix.a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    mat start(siz,siz);
    rep(j,0,sz(hm)) {
        vt<int> a = hm[j];
        bool ok = 1;
        rep(k,0,M) {
            if (a[k] == 2) {
                ok = 0;
                break;
            }
        }
        if (!ok) continue;
        vt<int> b(M);
        rep(k,0,M) {
            int x = k+dx[a[k]];
            int y = dy[a[k]];
            if (y == 0) {
                b[x]+=2;
            }
        }
        rep(k,0,M) {
            if (a[k] == 0) {
                b[k]++;
            }
        }
        int y = 0;
        for (int k = M-1; k >= 0; k--) {
            y *= 4;
            y += b[k];
        }
        start.a[0][y]++;
    }
    mat res = binpow(matrix,N-1);
    // cout << "res: " << endl;
    // rep(i,0,siz) {
    //     rep(j,0,siz) {
    //         cout << res.a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int tar = 0;
    rep(i,0,M) {
        tar *= 4;
        tar += 2;
    }
    mat fin = start*res;
    // cout << "fin: " << endl;
    // rep(i,0,sz(fin.a)) {
    //     rep(j,0,sz(fin.a[i])) {
    //         cout << fin.a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // cout << "tar: " << tar << endl;
    int ans = fin.a[0][tar];
    cout << ans << endl;
    return 0;
}