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
int a[105];
int idx[105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        idx[i] = i;
    }
    for (int i = 0; i < M; i++) {
        string s, t; cin >> s >> t;
        int x = stoi(s.substr(1)), y = stoi(t.substr(1));
        if (idx[x] > idx[y]) {
            int ix = idx[x];
            int iy = idx[y];
            for (int j = 1; j <= N; j++) {
                if (iy < idx[j] && idx[j] <= ix) {
                    idx[j]--;
                }
            }
            idx[y] = ix;
        }
        // cout << "idx: ";
        // for (int j = 1; j <= N; j++) {
        //     cout << idx[j] << " ";
        // }
        // cout << endl;
    }
    for (int i = 1; i <= N; i++) {
        a[idx[i]] = i;
    }
    for (int i = 1; i <= N; i++) {
        cout << "T" << a[i] << " ";
    }
    cout << endl;
    return 0;
}