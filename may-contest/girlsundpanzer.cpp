#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, K;
ll a[100005][10];
bool b[100005][10];
ll l[100005][10];
ll dp[100005];
ll pre[100005];

int main() {
    freopen("input.txt", "w", stdout);
    srand(time(0));
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> n(1, 4);
    uniform_int_distribution<int> k(1, 4);
    uniform_int_distribution<int> m(-4, 4);
    int t = 3;
    cout << t << endl;
    while (t--) {
        int n1 = n(gen);
        int k1 = k(gen);
        cout << n1 << ' ' << k1 << endl;
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < k1; j++) {
                cout << (m(gen)<0?"X":to_string(m(gen))) << ' ';
            }
            cout << endl;
        }
    }
    fclose(stdout);
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < K; j++) {
                string s; cin >> s;
                if (s=="X") {
                    b[i][j] = 0;
                    a[i][j] = 0;
                } else {
                    b[i][j] = 1;
                    a[i][j] = stoll(s);
                }
            }
        }
        for (int j = 0; j < K; j++) {
            ll cur = 0;
            for (int i = 0; i < N; i++) {
                l[i][j] = cur;
                if (b[i][j]) {
                    cur = i;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            dp[i] = 0;
            pre[i] = 0;
        }
        for (int i = 0; i < K; i++) {
            dp[0] = max(dp[0], a[0][i]);
        }
        dp[0]+=1;
        if (dp[0]<=0) {
            cout << "NO" << endl;
            continue;
        }
        pre[0] = dp[0];
        bool ans = 1;
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < K; j++) {
                // cout << "i: " << i << " j: " << j << " a[i][j]: " << a[i][j] << " pre[i-1]: " << pre[i-1] << " l[i][j]: " << l[i][j] << " dp[i-1]: " << dp[i-1] << endl;
                if (b[i][j]) {
                    dp[i] = max(dp[i], dp[i-1]+a[i][j]+pre[i-1]-(l[i][j]==0?0:pre[l[i][j]-1]));
                } else {
                    dp[i] = max(dp[i], dp[i-1]);
                }
            }
            if (dp[i] >= 1e14) {
                break;
            }
            if (dp[i] <= 0) {
                ans = 0;
                break;
            }
            pre[i] = pre[i-1]+dp[i];
        }
        cout << "dp: " << endl;
        for (int i = 0; i < N; i++) {
            cout << dp[i] << ' ';
        }
        cout << endl;
        cout << (ans?"YES":"NO") << endl;
    }
    return 0;
}