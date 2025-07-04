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

struct Trie {
    Trie *c[2];
    Trie() {
        c[0] = c[1] = NULL;
    }
};

int N;
int a[200005];
Trie *root = new Trie();

void add(int x) {
    Trie *cur = root;
    for (int i = 29; i >= 0; i--) {
        int b = (x>>i)&1;
        if (!cur->c[b]) {
            cur->c[b] = new Trie();
        }
        cur = cur->c[b];
    }
}

int getmax(int x) {
    Trie *cur = root;
    int ans = 0;
    for (int i = 29; i >= 0; i--) {
        int b = (x>>i)&1;
        if (cur->c[!b]) {
            ans |= 1<<i;
            cur = cur->c[!b];
        } else {
            cur = cur->c[b];
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < N; i++) {
        a[i] ^= a[i-1];
    }
    int ans = 0;
    add(0);
    for (int i = 0; i < N; i++) {
        ans = max(ans, getmax(a[i]));
        add(a[i]);
    }
    cout << ans << endl;
    return 0;
}