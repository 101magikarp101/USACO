#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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

int N, K;
ll dp[5005];
int trie[1000006][26];
bool en[1000006];
int ct = 0;

void insert(string s) {
    int node = 0;
    for (int i = 0; i < sz(s); i++) {
        if (!trie[node][s[i]-'a']) {
            trie[node][s[i]-'a'] = ++ct;
        }
        node = trie[node][s[i]-'a'];
    }
    en[node] = 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = sz(s);
    cin >> K;
    for (int i = 0; i < K; i++) {
        string t;
        cin >> t;
        insert(t);
    }
    dp[n] = 1;
    for (int i = n-1; i >= 0; i--) {
        string t = "";
        for (int j = i; j < n; j++) {
            t += s[j];
            
        }
    }
    cout << dp[n] << endl;
    return 0;
}