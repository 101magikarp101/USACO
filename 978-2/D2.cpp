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

int ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();
    int r;
    cin >> r;
    return r;
}

void tell(int i) {
    cout << "! " << i << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        if (N == 3) {
            if (ask(1,2) == ask(2,1)) {
                tell(3);
            } else {
                if (ask(1,3) != ask(3,1)) {
                    tell(1);
                } else {
                    tell(2);
                }
            }
        } else if (N%2) {
            int r1 = ask(1,2);
            int r2 = ask(2,3);
            int r3 = ask(3,1);
            int s = r1+r2+r3;
            if (s==2 || s==0) {
                if (ask(2,1) == r1) {
                    tell(3);
                } else {
                    if (ask(3,2) == r2) {
                        tell(1);
                    } else {
                        tell(2);
                    } 
                }
            } else {
                int imp = -1;
                for (int i = 4; i <= N; i+=2) {
                    if (i+1 == N) {
                        imp = i;
                        break;
                    }
                    if (ask(i,i+1) != ask(i+1,i)) {
                        imp = i;
                        break;
                    }
                }
                int j = (imp+2)%N;
                if (ask(imp,j) == ask(j,imp)) {
                    tell(imp+1);
                } else {
                    tell(imp);
                }
            }
        } else {
            int imp = -1;
            for (int i = 1; i <= N; i+=2) {
                if (i+1 == N) {
                    imp = i;
                    break;
                }
                if (ask(i,i+1) != ask(i+1,i)) {
                    imp = i;
                    break;
                }
            }
            int j = (imp+2)%N;
            if (ask(imp,j) == ask(j,imp)) {
                tell(imp+1);
            } else {
                tell(imp);
            }
        }
    }
    return 0;
}