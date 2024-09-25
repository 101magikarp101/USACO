#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int a[200005];
ll p[9];
map<ll, int> m;

ll boardtoll(vt<vt<char>> &b) {
    ll res = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int hm;
            if (b[i][j] == 'X') {
                hm = 1;
            } else if (b[i][j] == 'O') {
                hm = 2;
            } else {
                hm = 0;
            }
            res += p[i*3+j]*hm;
        }
    }
    return res;
}

vt<vt<char>> lltoboard(ll x) {
    vt<vt<char>> res(3, vt<char>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int hm = (x/p[i*3+j])%3;
            if (hm == 1) {
                res[i][j] = 'X';
            } else if (hm == 2) {
                res[i][j] = 'O';
            } else {
                res[i][j] = '.';
            }
        }
    }
    return res;
}

int win(vt<vt<char>> &b) {
    for (int i = 0; i < 3; i++) {
        if (b[i][0] == b[i][1] && b[i][1] == b[i][2] && b[i][0] != '.') {
            return b[i][0] == 'X' ? 1 : -1;
        }
        if (b[0][i] == b[1][i] && b[1][i] == b[2][i] && b[0][i] != '.') {
            return b[0][i] == 'X' ? 1 : -1;
        }
    }
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2] && b[0][0] != '.') {
        return b[0][0] == 'X' ? 1 : -1;
    }
    if (b[0][2] == b[1][1] && b[1][1] == b[2][0] && b[0][2] != '.') {
        return b[0][2] == 'X' ? 1 : -1;
    }
    return 0;
}

void dfs(vt<vt<char>> &b, int turn) {
    ll h = boardtoll(b);
    if (m.count(h)) {
        return;
    }
    int w = win(b);
    if (w!=0) {
        // cout << "WIN\n";
        // for (int i = 0; i < 3; i++) {
        //     for (int j = 0; j < 3; j++) {
        //         cout << b[i][j];
        //     }
        //     cout << '\n';
        // }
        m[h] = w;
        return;
    }
    if (turn == 1) {
        vt<int> v1, v2, v3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (b[i][j] == '.') {
                    b[i][j] = 'X';
                    dfs(b, 0);
                    int res = m[boardtoll(b)];
                    if (res > 0) {
                        v1.push_back(res);
                    } else if (res < 0) {
                        v3.push_back(res);
                    } else {
                        v2.push_back(res);
                    }
                    b[i][j] = '.';
                }
            }
        }
        sort(v1.begin(), v1.end());
        sort(v3.begin(), v3.end());
        if (v1.empty()) {
            if (v2.empty()) {
                if (v3.empty()) {
                    m[h] = 0;
                } else {
                    m[h] = v3[0];
                }
            } else {
                m[h] = 0;
            }
        } else {
            m[h] = v1[0]+1;
        }
    } else {
        vt<int> v1, v2, v3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (b[i][j] == '.') {
                    b[i][j] = 'O';
                    dfs(b, 1);
                    int res = m[boardtoll(b)];
                    if (res > 0) {
                        v1.push_back(res);
                    } else if (res < 0) {
                        v3.push_back(res);
                    } else {
                        v2.push_back(res);
                    }
                    b[i][j] = '.';
                }
            }
        }
        sort(v1.begin(), v1.end(), greater<int>());
        sort(v3.begin(), v3.end(), greater<int>());
        if (v3.empty()) {
            if (v2.empty()) {
                if (v1.empty()) {
                    m[h] = 0;
                } else {
                    m[h] = v1[0];
                }
            } else {
                m[h] = 0;
            }
        } else {
            m[h] = v3[0]-1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    p[0] = 1;
    for (int i = 1; i < 9; i++) {
        p[i] = p[i-1]*3;
    }
    vt<vt<char>> b(3, vt<char>(3, '.'));
    dfs(b, 1);
    // for (auto i : m) {
    //     int res = i.second;
    //     vt<vt<char>> c = lltoboard(i.first);
    //     if (win(c) != 0) {
    //         cout << i.first << " #" << endl;
    //     } else {
    //         if (res < 0) {
    //             res++;
    //         } else if (res > 0){
    //             res--;
    //         }
    //         if (res != 0) {
    //             cout << i.first << " #" << res << endl;
    //         } else {
    //             cout << i.first << " 0.0" << endl;
    //         }
    //     }
    //     for (int j = 0; j < 3; j++) {
    //         for (int k = 0; k < 3; k++) {
    //             cout << c[j][k];
    //         }
    //         cout << '\n';
    //     }
    // }
    vt<vt<char>> c(3, vt<char>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> c[i][j];
        }
    }
    ll h = boardtoll(c);
    if (win(c) != 0) {
        cout << "#\n";
    } else {
        if (m[h] < 0) {
            cout << "#" << m[h]+1 << '\n';
        } else if (m[h] > 0) {
            cout << "#" << m[h]-1 << '\n';
        } else {
            cout << "0.0\n";
        }
    }
    return 0;
}