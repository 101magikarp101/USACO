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

int N, K;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int k1 = (K+1)/2, k2 = K/2;
    mset<int> s1, s2;
    for (int i = 0; i < K; i++) {
        s1.insert(a[i]);
    }
    for (int i = 0; i < k2; i++) {
        auto it = --s1.end();
        s2.insert(*it);
        s1.erase(it);
    }
    cout << *s1.rbegin() << " ";
    for (int i = K; i < N; i++) {
        if (s1.count(a[i-K])) {
            s1.erase(s1.find(a[i-K]));
        } else {
            s2.erase(s2.find(a[i-K]));
        }
        if (!s1.empty() && a[i] <= *s1.rbegin()) {
            s1.insert(a[i]);
        } else {
            s2.insert(a[i]);
        }
        if (sz(s1) < k1) {
            auto it = s2.begin();
            s1.insert(*it);
            s2.erase(it);
        } else if (sz(s1) > k1) {
            auto it = --s1.end();
            s2.insert(*it);
            s1.erase(it);
        }
        cout << *s1.rbegin() << " ";
    }
    return 0;
}