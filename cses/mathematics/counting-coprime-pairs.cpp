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
int num[1000005];
int mob[1000005];
int a[1000005];
int cnt[1000005];
int b[1000005];

void precalc(int n) {
    mob[1] = -1;
    for (int i = 1; i <= n; i++) {
        if (mob[i]) {
            mob[i] = -mob[i];
            for (int j = i+i; j <= n; j += i) {
                mob[j] += mob[i];
            }
        }
    }
}

void solvecnt(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j+=i) {
            cnt[i] += a[j];
        }
        cnt[i] *= mob[i];
    }
}

void solveb(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j+=i) {
            b[j] += cnt[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    precalc(1000000);
    cin >> N;
    int o = 0;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
        if (num[i] != 1) a[num[i]]++;
        else o++;
    }
    solvecnt(1000000);
    solveb(1000000);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (num[i] != 1) ans += b[num[i]];
    }
    ans /= 2;
    ans += o*(N-o);
    ans += o*(o-1)/2;
    cout << ans << endl;
    return 0;
}