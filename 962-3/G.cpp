#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, M;
ull a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<ull> ra(1, ULLONG_MAX);
        for (int i = 0; i <= N; i++) {
            a[i] = 0;
        }
        for (int i = 0; i < M; i++) {
            int l, r; cin >> l >> r;
            ull x = ra(gen);
            a[l] ^= x;
            a[r] ^= x;
        }
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            a[i] ^= a[i-1];
        }
        // cout << "a = ";
        // for (int i = 1; i <= N; i++) {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        map<ull, int> mp;
        for (int i = 1; i <= N; i++) {
            mp[a[i]]++;
            ans = max(ans, mp[a[i]]);
        }
        cout << N-ans << endl;
    }
    return 0;
}