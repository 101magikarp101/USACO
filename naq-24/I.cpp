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
char a[32][32];
bool lit[32][32];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool in(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool isblock(char c) {
    return c=='X'||(c>='0'&&c<='4');
}

bool light(int x, int y) {
    lit[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x, ny = y;
        while (true) {
            nx += dx[i];
            ny += dy[i];
            if (!in(nx,ny)) break;
            if (a[nx][ny] == '?') return 0;
            if (isblock(a[nx][ny])) break;
            lit[nx][ny] = 1;
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < N; j++) {
            a[i][j] = s[j];
            lit[i][j] = 0;
        }
    }
    bool good = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] == '?') {
                good &= light(i,j);
            } else if (a[i][j] >= '0' && a[i][j] <= '4') {
                int tar = a[i][j]-'0';
                for (int k = 0; k < 4; k++) {
                    int nx = i+dx[k], ny = j+dy[k];
                    if (!in(nx,ny)) continue;
                    if (a[nx][ny] == '?') tar--;
                }
                good &= (tar==0);
            }
            if (!good) break;
        }
        if (!good) break;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            good &= (lit[i][j] || isblock(a[i][j]));
        }
    }
    cout << good << endl;
    return 0;
}