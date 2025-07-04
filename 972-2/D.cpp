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

int T, L, N, M;
int a[303];
int b[303][303];
int c[303][303], c1[303][303];
int dp[303][303][303];
map<int,int> mp;

bool in(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> L >> N >> M;
        for (int i = 0; i < L; i++) {
            cin >> a[i];
            mp[a[i]] = i;
        }
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < M; j++) {
                c[i][j] = -1;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> b[i][j];
                c[mp[b[i][j]]][i] = max(c[mp[b[i][j]]][i], j);
            }
        }
        for (int i = 0; i < L; i++) {
            int ma = -1;
            for (int j = M-1; j >= 0; j--) {
                ma = max(ma, c[i][j]);
                c[i][j] = ma;
            }
        }
        for (int i = L-1; i >= 0; i--) {
            for (int j = 0; j < M; j++) {
                if (i == L-1) {
                    c1[i][j] = c[i][j];
                } else {
                    if (c[i][j] == N-1) {
                        c1[i][j] = c[i][j];
                    } else if (j == M-1) {
                        c1[i][j] = c[i][j];
                    } else {
                        if (c1[i][j] > c1[i+1][j+1]) {
                            c1[i][j] = c[i][j];
                        } else {
                            c1[i][j] = -1;
                        }
                    }
                }
            }
            int ma = -1;
            for (int j = M-1; j >= 0; j--) {
                ma = max(ma, c1[i][j]);
                c1[i][j] = ma;
            }
        }
        cout << "c1" << endl;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < M; j++) {
                cout << c1[i][j] << " ";
            }
            cout << endl;
        }
        bool good = 0;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < M; j++) {
                if (c1[i][j] != -1) {
                    good = 1;
                    break;
                }
            }
        }
        cout << (good ? "T" : "N") << endl;
    }
    return 0;
}