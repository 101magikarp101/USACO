#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
struct pii {int x, y;};
struct pll {ll x, y;};

ll add(ll a, ll b) {
    return (a+b)%MOD2;
}

ll sub(ll a, ll b) {
    return (a-b+MOD2)%MOD2;
}

ll mul(ll a, ll b) {
    return (a*b)%MOD2;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b%2) res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

ll inv(ll a) {
    return binpow(a, MOD2-2);
}

ll di(ll a, ll b) {
    return mul(a, inv(b));
}

struct Matrix {
    vt<vt<ll>> a;
    int n, m;
    Matrix(int n, int m) : n(n), m(m) {
        a = vt<vt<ll>>(n, vt<ll>(m, 0));
    }
    Matrix operator*(Matrix b) {
        Matrix res(n, b.m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < b.m; j++) {
                for (int k = 0; k < m; k++) {
                    res.a[i][j] = add(res.a[i][j], mul(a[i][k], b.a[k][j]));
                }
            }
        }
        return res;
    }
    Matrix operator+(Matrix b) {
        Matrix res(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res.a[i][j] = add(a[i][j], b.a[i][j]);
            }
        }
        return res;
    }
    Matrix pow(ll b) {
        Matrix res(n, m);
        for (int i = 0; i < n; i++) {
            res.a[i][i] = 1;
        }
        Matrix x = *this;
        while (b > 0) {
            if (b%2) res = res*x;
            x = x*x;
            b /= 2;
        }
        return res;
    }
    Matrix operator!() {
        Matrix res(m, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res.a[j][i] = a[i][j];
            }
        }
        return res;
    }
    void print() {
        cout << "Matrix " << n << ' ' << m << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
    }
};

ll T, N, K;
char a[17][17];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool good(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N && a[x][y] != '#';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // auto start = chrono::high_resolution_clock::now();
    // cin >> N >> K;
    // Matrix n(N,N);
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         n.a[i][j] = 1;
    //     }
    // }
    // n = n.pow(K);
    // n.print();
    // auto end = chrono::high_resolution_clock::now();
    // cerr << "Time: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms" << endl;
    // Matrix A(N,N);
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         if (abs(i-j)==1) A.a[i][j] = 1;
    //     }
    // }
    // Matrix B = A;
    // for (int k = 1; k <= K; k++) {
    //     A = A*B;
    //     A.print();
    // }
    auto start = chrono::high_resolution_clock::now();
    cin >> N >> K;
    K = (1<<30)-1;
    int si = 0, sj = 0;
    // for (int i = 0; i < N; i++) {
    //     string s;
    //     cin >> s;
    //     for (int j = 0; j < N; j++) {
    //         a[i][j] = s[j];
    //         if (a[i][j] == 'S') {
    //             si = i;
    //             sj = j;
    //         }
    //     }
    // }
    Matrix n(N*N,N*N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 4; k++) {
                int x = i+dx[k];
                int y = j+dy[k];
                if (good(x,y)) {
                    n.a[i*N+j][x*N+y] = 1;
                }
            }
        }
    }
    n = n.pow(K);
    n.print();
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans = add(ans, n.a[si*N+sj][i*N+j]);
        }
    }
    cout << ans << endl;
    auto end = chrono::high_resolution_clock::now();
    cerr << "Time: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms" << endl;
    return 0;
}