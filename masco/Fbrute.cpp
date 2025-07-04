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

int r = 10, c = 9;
vt<vt<int>> v;
vt<vt<int>> cnts = vt<vt<int>>(r, vt<int>(4, 0));
vt<vt<int>> ords = {{1,2,3}, {1,3,2}, {2,1,3}, {2,3,1}, {3,1,2}, {3,2,1}};
ll cnt = 0;
random_device rd;
mt19937 rng(rd());
uniform_int_distribution<int> uni(0, 5);
vt<int> graph = vt<int>(r*c, 0);
bool solved = 0;

bool check(int n) {
    int x = n / c, y = n % c;
    for (int i = x-1; i >= 0; i--) {
        for (int j = y-1; j >= 0; j--) {
            int a = v[i][j], b = v[i][y], c = v[x][j], d = v[x][y];
            if (a == b && b == c && c == d) {
                return false;
            }
        }
    }
    return true;
}

bool solve (int n) {
    graph[n]++;
    if (n == 89) {
        for (int i = 0; i < graph.size(); i++) {
            cerr << "i: " << i << " " << graph[i] << endl;
        }
    }
    int x = n / c, y = n % c;
    auto ord = ords[uni(rng)];
    for (int i = 0; i < 3; i++) {
        int o = ord[i];
        v[x][y] = o;
        cnts[x][o]++;
        // if (cnts[x][o] > 4) {
        //     cnts[x][o]--;
        //     continue;
        // }
        cnt++;
        if (n == r*c-1) {
            if (check(n)) {
                solved = 1;
                return true;
            }
        } else if (check(n)) {
            bool res = solve(n+1);
            if (res) {
                return true;
            }
        }
        cnts[x][o]--;
    }
    v[x][y] = 0;
    return false;
}

// bool solve(int n) {
//     int x = n % r, y = n / r;
//     vt<int> ord = ords[uni(rng)];
//     v[x][y] = ord[0];
//     cnt++;
//     if (n == r*c-1) {
//         if (check(n)) {
//             solved = 1;
//             return true;
//         }
//     } else if (check(n)) {
//         bool res = solve(n+1);
//         if (res) {
//             return true;
//         }
//     }
//     v[x][y] = ord[1];
//     cnt++;
//     if (n == r*c-1) {
//         if (check(n)) {
//             solved = 1;
//             return true;
//         }
//     } else if (check(n)) {
//         bool res = solve(n+1);
//         if (res) {
//             return true;
//         }
//     }
//     v[x][y] = ord[2];
//     cnt++;
//     if (n == r*c-1) {
//         if (check(n)) {
//             solved = 1;
//             return true;
//         }
//     } else if (check(n)) {
//         bool res = solve(n+1);
//         if (res) {
//             return true;
//         }
//     }
//     if (cnt >= 100000000) {
//         cout << "No solution found" << endl;
//         cnt = 0;
//         return false;
//     }
//     v[x][y] = 0;
//     return false;
// }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        v = vt<vt<int>>(r, vt<int>(c, 0));
        solve(0);
        if (!solved) {
            continue;
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << v[i][j];
            }
            cout << endl;
        }
        cout << cnt << endl;
        break;
    }
    return 0;
}