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
#define rrep(i,a,b) for(int i=a;i>=b;i--)
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
int a[200005];
vt<pii> pad = {{1,0},{0,1},{1,1},{2,1},{0,2},{1,2},{2,2},{0,3},{1,3},{2,3}};

struct state {
    char end = 'A';
    map<string,ll> m;
};

ll total(state &s) {
    ll ans = 0;
    for (auto x : s.m) {
        ans += x.se;
    }
    return ans;
}

pii coord1(char c) {
    if (c == 'L') return {0,0};
    else if (c == 'D') return {1,0};
    else if (c == 'R') return {2,0};
    else if (c == 'U') return {1,1};
    else return {2,1};
}

void add(state &s, char c, ll x, ll y) {
    if (x*y == 0) return;
    if (s.end != '-') {
        string str; str += s.end; str += c;
        s.m[str] += x;
    }
    s.end = c;
    if (y <= 1) return;
    string str; str += c; str += c;
    s.m[str] += x*max(y-1,0LL);
}

void run(state &next, pii d, pii c1, pii c2, ll x) {
    bool b = d.x > 0;
    pii corner = {min(c1.x,c2.x),min(c1.y,c2.y)};
    if (corner == pii{0,0}) b = !b;
    if (b) {
        char n1 = (d.y > 0 ? 'U' : 'D');
        char n2 = (d.x > 0 ? 'R' : 'L');
        add(next,n1,x,abs(d.y));
        add(next,n2,x,abs(d.x));
    } else {
        char n1 = (d.x > 0 ? 'R' : 'L');
        char n2 = (d.y > 0 ? 'U' : 'D');
        add(next,n1,x,abs(d.x));
        add(next,n2,x,abs(d.y));
    }
    add(next,'A',x,1);
}

state conv(state s) {
    state next;
    bool started = 0;
    for (auto x : s.m) {
        pii c1 = coord1(x.fi[0]);
        pii c2 = coord1(x.fi[1]);
        pii d = c2-c1;
        run(next,d,c1,c2,x.se);
    }
    return next;
}

pii coord(char c) {
    if (c == 'A') return {2,0};
    else return pad[c-'0'];
}

ll solve(string s) {
    state st;
    rep(i,0,sz(s)-1) {
        pii c1 = coord(s[i]);
        pii c2 = coord(s[i+1]);
        pii d = c2-c1;
        run(st,d,c1,c2,1);
    }
    rep(i,0,25) {
        st = conv(st);
    }
    return total(st);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    N = 5;
    ll ans = 0;
    rep(i,0,N) {
        string s; cin >> s;
        int n = stoi(s.substr(0,3));
        s = 'A'+s;
        cout << "s: " << s << endl;
        ll res = solve(s);
        cout << "res: " << res << endl;
        ans += res*n;
    }
    cout << ans << endl;
    return 0;
}