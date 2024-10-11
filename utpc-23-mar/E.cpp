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

int N, M;
string a[100005];
set<string> words;
vt<string> b;
map<string,int> cnt;
map<string,int> m, m1;

vt<string> split(string s, string delim) {
    vt<string> res;
    int start = 0;
    int end = s.find(delim);
    while (end != string::npos) {
        res.pb(s.substr(start, end-start));
        start = end+delim.size();
        end = s.find(delim, start);
    }
    res.pb(s.substr(start, end-start));
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        words.insert(a[i]);
    }
    string omegasus; getline(cin, omegasus);
    for (int i = 0; i < M; i++) {
        string s; getline(cin, s);
        s = s.substr(0,sz(s)-1);
        vt<string> v = split(s, " ");
        for (string x : v) {
            if (words.find(x) == words.end()) continue;
            b.pb(x);
            cnt[x]++;
        }
    }
    int n = sz(b);
    int ans = 0;
    string prev = "";
    for (int i = 0; i < n; i++) {
        if (b[i] != prev) {
            ans++;
            prev = b[i];
        } else {
            m1[b[i]]++;
        }
    }
    int r = 0;
    for (int i = 0; i < n; i++) {
        r = i;
        while (r < n-1 && b[r+1]==b[i]) r++;
        if (i>0) {
            if (r < n-1 && b[r+1]==b[i-1]) m[b[i]]++;
        }
        i = r;
    }
    for (int i = 0; i < N; i++) {
        int res = ans-cnt[a[i]]+m1[a[i]]-m[a[i]];
        cout << res << endl;
    }
    return 0;
}