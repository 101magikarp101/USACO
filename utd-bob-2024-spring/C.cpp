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

int T, N, M;
char a[205][205];
bool safe[205][205];

void reset() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] != '#') safe[i][j] = 1;
            else safe[i][j] = 0;
        }
    }
}

void calcnorth() {
    reset();
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            if (a[i][j] == '#') break;
            safe[i][j] = 0;
        }
    }
}

void calceast() {
    reset();
    for (int i = 0; i < N; i++) {
        for (int j = M-1; j >= 0; j--) {
            if (a[i][j] == '#') break;
            safe[i][j] = 0;
        }
    }
}

void calcsouth() {
    reset();
    for (int j = 0; j < M; j++) {
        for (int i = N-1; i >= 0; i--) {
            if (a[i][j] == '#') break;
            safe[i][j] = 0;
        }
    }
}

void calcwest() {
    reset();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == '#') break;
            safe[i][j] = 0;
        }
    }
}

void printsafe() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (safe[i][j]) {
                cout << i*N+j << " ";
            }
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            string s; cin >> s;
            for (int j = 0; j < M; j++) {
                a[i][j] = s[j];
            }
        }
        calcnorth();
        cout << "Testcase " << tt << " NORTH: ";
        printsafe();
        calceast();
        cout << "Testcase " << tt << " EAST : ";
        printsafe();
        calcsouth();
        cout << "Testcase " << tt << " SOUTH: ";
        printsafe();
        calcwest();
        cout << "Testcase " << tt << " WEST : ";
        printsafe();
    }
    return 0;
}