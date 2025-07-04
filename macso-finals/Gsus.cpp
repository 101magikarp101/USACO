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

int N;
int a[1000005];
int cnt[1000005];
int b[1000005];
int mob[1000005];

void precalc(int n) {
    mob[1] = -1;
    for (int i = 1; i <= n; i++) {
        if (mob[i]) {
            mob[i] = -mob[i];
            for (int j = i+i; j <= n; j+=i) {
                mob[j] += mob[i];
            }
        }
    }
}

void calccnt(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            cnt[i] += a[j];
        }
        cnt[i] *= mob[i];
    }
}

void calcb(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j+=i) {
            b[j] += cnt[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // auto start = chrono::high_resolution_clock::now();
    precalc(1000000);
    cin >> N;
    int x;
    for (int i = 1; i <= N; i++) {
        cin >> x;
        a[x]++;
    }
    calccnt(1000000);
    calcb(1000000);
    int Q; cin >> Q;
    while (Q--) {
        cin >> x;
        cout << b[x] << endl;
    }
    // auto end = chrono::high_resolution_clock::now();
    // cerr << chrono::duration_cast<chrono::milliseconds>(end-start).count() << " ms" << endl;
    return 0;
}