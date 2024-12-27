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
umap<string,uset<string>> adj;
set<string> tot;
vt<string> v;

string maxclique(vt<int> &cur) {
    string ans = "";
    rep(i,0,sz(cur)) {
        ans += v[cur[i]];
        if (i < sz(cur)-1) {
            ans += ",";
        }   
    }
    rep(i,cur[sz(cur)-1], sz(v)) {
        bool ok = 1;
        each(j,cur) {
            if (adj[v[j]].find(v[i]) == adj[v[j]].end()) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            cur.pb(i);
            string res = maxclique(cur);
            if (sz(res) > sz(ans)) {
                ans = res;
            }
            cur.pop_back();
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto start = chrono::high_resolution_clock::now();
    string s;
    while (cin >> s) {
        string u = s.substr(0,2);
        string v = s.substr(3,2);
        tot.insert(u);
        tot.insert(v);
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for (auto &i:tot) {
        v.pb(i);
    }
    cout << sz(v) << endl;
    sort(all(v));
    string ans = "";
    rep(i,0,sz(v)) {
        vt<int> cur;
        cur.pb(i);
        string res = maxclique(cur);
        if (sz(res) > sz(ans)) {
            ans = res;
        }
    }
    cout << ans << endl;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end-start;
    cerr << "Time: " << elapsed.count() << endl;
    return 0;
}