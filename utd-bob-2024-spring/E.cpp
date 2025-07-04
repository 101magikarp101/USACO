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

int T, N, M;
ll a[550000];
ll b[550000];
vt<int> in;

void inorder(int n) {
    if (n >= (1<<N)) return;
    if (a[n] == -1) return;
    inorder(n*2);
    in.pb(n);
    inorder(n*2+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= (1<<N)-1; i++) {
        string s; cin >> s;
        if (s == "X") a[i] = -1;
        else if (s == "_") a[i] = 0;
        else a[i] = stoll(s);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> b[i];
    }
    sort(b, b+M);
    inorder(1);
    int cur = 0;
    for (int i = 0; i < sz(in); i++) {
        if (a[in[i]] >= 1) continue;
        a[in[i]] = b[cur++];
    }
    for (int i = 1; i <= (1<<N)-1; i++) {
        if (a[i] == -1) cout << "X ";
        else cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}