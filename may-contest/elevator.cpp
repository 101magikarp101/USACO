#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int N, K;
vt<int> a[1000005];

int main() {
    // freopen("input.txt", "w", stdout);
    // srand(time(0));
    // int n = 10;
    // int k = 100000;
    // int m = 10;
    // cout << n << ' ' << k << endl;
    // for (int i = 0; i < n; i++) {
    //     int cnt = rand()%m+1;
    //     cout << cnt << ' ';
    //     for (int j = 0; j < cnt; j++) {
    //         int x = rand()%n+1;
    //         while (x == i+1) {
    //             x = rand()%n+1;
    //         }
    //         cout << x << ' ';
    //     }
    //     cout << endl;
    // }
    // fclose(stdout);
    // freopen("output.txt", "w", stdout);
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        int cnt; cin >> cnt;
        for (int j = 0 ; j < cnt; j++) {
            int x; cin >> x;
            a[i].push_back(x);
        }
    }
    for (int i = 1; i <= N; i++) {
        sort(a[i].begin(), a[i].end());
    }
    int u = 0, d = 0;
    multiset<int> s;
    for (int i = 1; i <= N; i++) {
        while (s.find(i) != s.end()) {
            s.erase(s.find(i));
        }
        while (!a[i].empty() && *a[i].rbegin()>i) {
            s.insert(*a[i].rbegin());
            a[i].pop_back();
        }
        u = max(u, (int)ceil((double)s.size()/K));
    }
    s.clear();
    for (int i = N; i >= 1; i--) {
        while (s.find(i) != s.end()) {
            s.erase(s.find(i));
        }
        while (!a[i].empty()) {
            s.insert(*a[i].rbegin());
            a[i].pop_back();
        }
        d = max(d, (int)ceil((double)s.size()/K));
    }
    int ans = max(2*u-2, 2*d-1);
    cout << ans << "\n";
    return 0;
}