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

int N, Q;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(INT_MIN, INT_MAX);
    uniform_int_distribution<int> dis2(1, 200000);
    N = 200000;
    cout << N << endl;
    for (int i = 0; i < N; i++) {
        a[i] = dis(gen);
        cout << a[i] << " ";
    }
    cout << endl;
    Q = 200000;
    cout << Q << endl;
    for (int i = 0; i < Q; i++) {
        int x = abs(dis(gen)) % 2;
        cout << x << " ";
        if (x==0) {
            int l = dis2(gen);
            int r = dis2(gen);
            int v = dis(gen);
            if (l > r) swap(l, r);
            cout << l << " " << r << " " << v << endl;
        } else {
            int l = dis2(gen);
            int r = dis2(gen);
            if (l > r) swap(l, r);
            cout << l << " " << r << endl;
        }
    }
    return 0;
}