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

int N;
vt<int> adj[200005];
int a[200005];
set<int> s;
multiset<int> s1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        s.insert(i);
    }
    for (int i = 0; i < N-2; i++) {
        scanf("%d", &a[i]);
        s1.insert(a[i]);
        if (s.count(a[i])) {
            s.erase(a[i]);
        }
    }
    for (int i = 0; i < N-2; i++) {
        int x = *s.begin();
        adj[x].pb(a[i]);
        s.erase(x);
        s1.erase(s1.find(a[i]));
        if (!s1.count(a[i])) {
            s.insert(a[i]);
        }
    }
    int x = *s.begin();
    int y = *s.rbegin();
    adj[x].pb(y);
    for (int i = 1; i <= N; i++) {
        for (int j: adj[i]) {
            cout << i << " " << j << endl;
        }
    }
    return 0;
}