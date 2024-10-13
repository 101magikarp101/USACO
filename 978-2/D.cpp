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
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        int imp = -1;
        bool done = 0;
        for (int i = 1; i <= N; i+=2) {
            if (i == N) {
                cout << "! " << N << endl;
                cout.flush();
                done = 1;
                break;
            }
            if (i+1 == N) {
                imp = i;
                break;
            }
            int r1, r2;
            cout << "? " << i << " " << i+1 << endl;
            cout.flush();
            cin >> r1;
            cout << "? " << i+1 << " " << i << endl;
            cout.flush();
            cin >> r2;
            if (r1 != r2) {
                imp = i;
                break;
            }
        }
        if (done) continue;
        int r1, r2;
        if (imp+1 == N) {
            cout << "? " << imp << " " << 1 << endl;
            cout.flush();
            cin >> r1;
            cout << "? " << 1 << " " << imp << endl;
            cout.flush();
            cin >> r2;
        } else {
            cout << "? " << imp << " " << N << endl;
            cout.flush();
            cin >> r1;
            cout << "? " << N << " " << imp << endl;
            cout.flush();
            cin >> r2;
        }
        if (r1 != r2) {
            cout << "! " << imp << endl;
        } else {
            cout << "! " << imp+1 << endl;
        }
        cout.flush();
    }
    return 0;
}