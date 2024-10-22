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
ll X;
pll a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> a[i].x;
        a[i].y = i+1;
    }
    sort(a,a+N);
    for (int i = 0; i < N; i++) {
        for (int j = i+3; j < N; j++) {
            int l = i+1, r = j-1;
            while (l<r) {
                ll s = a[i].x+a[j].x+a[l].x+a[r].x;
                if (s == X) {
                    cout << a[i].y << " " << a[j].y << " " << a[l].y << " " << a[r].y << endl;
                    return 0;
                }
                if (s > X) {
                    r--;
                } else {
                    l++;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}