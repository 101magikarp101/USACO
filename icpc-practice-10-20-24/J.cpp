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
//4:48

int a[9][9];
vt<bool> pos[9][9];

bool in(int x, int y) {
    return x >= 0 && x < 9 && y >= 0 && y < 9;
}

bool solve1(int x, int y) {
    vt<bool> can(10,1);
    for (int i = 0; i < 9; i++) {
        can[a[x][i]] = 0;
        can[a[i][y]] = 0;
    }
    int sx = x/3*3, sy = y/3*3;
    for (int i = sx; i < sx+3; i++) {
        for (int j = sy; j < sy+3; j++) {
            can[a[i][j]] = 0;
        }
    }
    int cnt = 0, num = 0;
    for (int i = 1; i <= 9; i++) {
        if (can[i]) {
            cnt++;
            num = i;
        }
    }
    for (int i = 0; i <= 9; i++) {
        pos[x][y][i] = can[i];
    }
    if (cnt == 1) {
        a[x][y] = num;
        return 1;
    }
    return 0;
}

bool solve2(int x, int y) {
    for (int i = 1; i <= 9; i++) {
        if (pos[x][y][i]) {
            bool good = 1;
            for (int j = 0; j < 9; j++) {
                if (j != y && a[x][j] == 0 && pos[x][j][i] == 1) {
                    good = 0;
                    break;
                }
            }
            if (good) {
                a[x][y] = i;
                return 1;
            }
            good = 1;
            for (int j = 0; j < 9; j++) {
                if (j != x && a[j][y] == 0 && pos[j][y][i] == 1) {
                    good = 0;
                    break;
                }
            }
            if (good) {
                a[x][y] = i;
                return 1;
            }
            good = 1;
            int sx = x/3*3, sy = y/3*3;
            for (int j = sx; j < sx+3; j++) {
                for (int k = sy; k < sy+3; k++) {
                    if (!(j == x && k == y) && a[j][k] == 0 && pos[j][k][i]) {
                        good = 0;
                        break;
                    }
                }
            }
            if (good) {
                a[x][y] = i;
                return 1;
            }
        }
    }
    return 0;
}

void reset() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            pos[i][j].assign(10,1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> a[i][j];
        }
    }
    int changed = 0;
    while (true) {
        changed = 0;
        reset();
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (a[i][j] == 0) {
                    bool res = solve1(i,j);
                    if (res) {
                        changed = 1;
                        break;
                    }
                }
            }
            if (changed) break;
        }
        if (changed) continue;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (a[i][j] == 0) {
                    bool res = solve2(i,j);
                    if (res) {
                        changed = 1;
                        break;
                    }
                }
            }
            if (changed) break;
        }
        if (!changed) break;
    }
    int cnt = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (a[i][j] == 0) cnt++;
        }
    }
    cout << (cnt!=0?"Not easy":"Easy") << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (a[i][j] == 0) cout << ".";
            else cout << a[i][j];
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}