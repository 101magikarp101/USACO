#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <bitset>
#include <string>
#include <unordered_map>
#include <deque>
#include <climits>
#include <unordered_set>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct state {
    ll val, x;
};

ll N, K;
ll a[405][405];
ll pre[405][405];
ll suf[405][405];
state dp[405][405];
unordered_map<char, ll> m;

int main () {
    cin >> N >> K;
    m.insert({'p', 1}); //pawn
    m.insert({'n', 3}); //knight
    m.insert({'b', 3}); //bishop
    m.insert({'r', 5}); //rook
    m.insert({'q', 9}); //queen
    m.insert({'_', 0}); //empty
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= N; j++) {
            a[i][j] = m[s[j-1]];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            pre[i][j] = a[i][j] + max(pre[i-1][j], pre[i][j-1]);
        }
    }
    for (int i = N; i >= 1; i--) {
        for (int j = N; j >= 1; j--) {
            suf[i][j] = a[i][j] + max(suf[i+1][j], suf[i][j+1]);
        }
    }
    cout << "pre" << endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << pre[i][j] << " ";
        }
        cout << endl;
    }
    cout << "suf" << endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << suf[i][j] << " ";
        }
        cout << endl;
    }
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N-1; j++) {
            ans = max(ans, pre[i][j]+suf[i][j+1]+K*(a[i][j]+a[i][j+1]));
        }
    }
    for (int i = 1; i <= N-1; i++) {
        for (int j = 1; j <= N; j++) {
            ans = max(ans, pre[i][j]+suf[i+1][j]+K*(a[i][j]+a[i+1][j]));
        }
    }
    cout << ans << endl;
}