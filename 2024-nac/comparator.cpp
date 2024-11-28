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

struct state {
    int x, y, z;
    int r;
    bool operator<(const state &a) const {
        if (x == a.x) {
            if (y == a.y) {
                return z < a.z;
            }
            return y < a.y;
        }
        return x < a.x;
    }
};

int N, K;
set<state> s;
vt<state> v;
int e;
bitset<1024> a[1024];

char solve(vt<char> &v) {
    // !
    vt<char> t;
    each(c,v) {
        if (c == '!') {
            t.pb('!');
        } else {
            while (!t.empty() && t.back() == '!') {
                t.pop_back();
                c = (1-(c-'0'))+'0';
            }
            t.pb(c);
        }
    }
    v = t;
    t.clear();
    // =
    each(c,v) {
        if (c == '=' || c == '&' || c == '|' || c == '^') {
            t.pb(c);
        } else {
            if (!t.empty() && t.back() == '=') {
                t.pop_back();
                char a = t.back(); t.pop_back();
                t.pb((a == c)+'0');
            } else {
                t.pb(c);
            }
        }
    }
    v = t;
    t.clear();
    // &
    each(c,v) {
        if (c == '&' || c == '|' || c == '^') {
            t.pb(c);
        } else {
            if (!t.empty() && t.back() == '&') {
                t.pop_back();
                char a = t.back(); t.pop_back();
                t.pb((a == '1' && c == '1')+'0');
            } else {
                t.pb(c);
            }
        }
    }
    v = t;
    t.clear();
    // |
    each(c,v) {
        if (c == '|' || c == '^') {
            t.pb(c);
        } else {
            if (!t.empty() && t.back() == '|') {
                t.pop_back();
                char a = t.back(); t.pop_back();
                t.pb((a == '1' || c == '1')+'0');
            } else {
                t.pb(c);
            }
        }
    }
    v = t;
    t.clear();
    // ^
    each(c,v) {
        if (c == '^') {
            t.pb(c);
        } else {
            if (!t.empty() && t.back() == '^') {
                t.pop_back();
                char a = t.back(); t.pop_back();
                t.pb((a != c)+'0');
            } else {
                t.pb(c);
            }
        }
    }
    v = t;
    return v[0];
}

char interpret(string &s) {
    vt<char> v;
    each(c,s) {
        if (c != ')') {
            v.pb(c);
        } else {
            vt<char> t;
            while (v.back() != '(') {
                t.pb(v.back());
                v.pop_back();
            }
            v.pop_back();
            reverse(all(t));
            char res = solve(t);
            v.pb(res);
        }
    }
    return solve(v);
}

int run(int n, int m) {
    rep(i,0,sz(v)) {
        int x = (n>>(K-(v[i].x)))&1;
        int y = (m>>(K-(v[i].y)))&1;
        if ((x<<1|y) == v[i].z) {
            return v[i].r;
        }
    }
    return e;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    rep(i,0,N) {
        int x, y; string str; int r;
        cin >> x >> y >> str >> r;
        rep(j,0,2) {
            rep(k,0,2) {
                string t = str;
                rep(l,0,sz(t)) {
                    if (t[l] == 'x') {
                        t[l] = j + '0';
                    } else if (t[l] == 'y') {
                        t[l] = k + '0';
                    }
                }
                char res = interpret(t);
                if (res == '1') {
                    int z = j<<1|k;
                    state st = {x, y, z, r};
                    if (!s.count(st)) {
                        s.insert(st);
                        v.pb(st);
                    }
                }
            }
        }
    }
    cin >> e;
    rep(i,0,1<<K) {
        rep(j,0,1<<K) {
            a[i][j] = run(i, j);
        }
    }
    int ans1 = 0, ans2 = 0, ans3 = 0;
    rep(i,0,1<<K) {
        ans1 += a[i][i];
    }
    rep(i,0,1<<K) {
        rep(j,0,1<<K) {
            ans2 += a[i][j] & a[j][i];
        }
    }
    rep(i,0,1<<K) {
        rep(j,0,1<<K) {
            if (a[i][j]) {
                auto res = ~a[i] & a[j];
                ans3 += res.count();
            }
        }
    }
    cout << ans1 << ' ' << ans2 << ' ' << ans3 << endl;
    return 0;
}