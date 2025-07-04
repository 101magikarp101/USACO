#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)((x).size())
#define uset unordered_set
#define umap unordered_map
#define mset multiset
#define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repl(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define rrepl(i,a,b) for(ll i=a;i>=b;i--)
#define each(i,a) for(auto &i:a)
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

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

int T, N, M, U, R, D, L;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> T;
    while (T--) {
        cin >> N >> M >> U >> R >> D >> L;
        if (R < M-1 || U < N-1) {
            cout << "impossible" << endl;
            if (T) cout << endl;
            continue;
        }
        vt<vt<char>> a = vt<vt<char>>(N, vt<char>(M, 0));
        a[0][M-1] = '*';
        rep(i,0,M-1) {
            a[0][i] = 'R';
        }
        rep(i,1,N) {
            a[i][M-1] = 'U';
        }
        R -= M-1;
        U -= N-1;
        rep(j,0,M-1) {
            rep(i,0,N-1) {
                if (D) {
                    a[i][j] = 'D';
                    a[i+1][j] = 'R';
                    D--;
                }
            }
        }
        rrep(i,N-1,1) {
            rrep(j,M-1,1) {
                if (L && a[i][j-1] == 0) {
                    a[i][j] = 'L';
                    a[i][j-1] = 'U';
                    L--;
                }
            }
        }
        rep(i,0,N) {
            rep(j,0,M) {
                if (a[i][j] == 0) {
                    if (U) {
                        a[i][j] = 'U';
                        U--;
                    } else if (R) {
                        a[i][j] = 'R';
                        R--;
                    }
                }
            }
        }
        // cout << U << " " << R << " " << D << " " << L << endl;
        rep(i,0,N) {
            rep(j,0,M) {
                cout << a[i][j];
            }
            cout << endl;
        }
        if (T) cout << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}