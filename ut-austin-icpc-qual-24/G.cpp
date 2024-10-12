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

int T, N;
int a[105][105];
int b[105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
    set<int> s;
    for (int i = 0; i < N; i++) {
        int ma = 0;
        int idx = -1;
        for (int j = 1; j <= N; j++) {
            if (s.count(j)) continue;
            if (a[j][i] > ma) {
                ma = a[j][i];
                idx = j;
            }
        }
        s.insert(idx);
        b[i] = idx;
    }
    while (true) {
        bool done = 1;
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                int res = a[b[i]][i]*a[b[j]][j];
                int res1 = a[b[i]][j]*a[b[j]][i];
                if (res1 > res) {
                    swap(b[i], b[j]);
                    done = 0;
                }
            }
        }
        if (done) break;
    }
    for (int i = 0; i < N; i++) {
        cout << b[i];
        if (i < N-1) cout << " ";
    }
    cout << endl;
    return 0;
}