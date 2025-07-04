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

int T, N;
int a[200005];
int s = 5;

bool check(vt<vt<int>> v) {
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            for (int k = i+1; k < s; k++) {
                for (int l = j+1; l < s; l++) {
                    int a = v[i][j], b = v[i][l], c = v[k][j], d = v[k][l];
                    if (a == b && b == c && c == d) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 1000);
    int cnt = 0;
    while (true) {
        vt<vt<int>> v(s, vt<int>(s));
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                int x = dis(gen);
                if (x <= 450) {
                    v[i][j] = 1;
                } else {
                    v[i][j] = 0;
                }
            }
        }
        if (check(v)) {
            for (int i = 0; i < s; i++) {
                for (int j = 0; j < s; j++) {
                    cout << v[i][j] << " ";
                }
                cout << endl;
            }
            break;
        }
        if (++cnt % 10000 == 0) {
            cout << cnt << endl;
        }
    }
    return 0;
}