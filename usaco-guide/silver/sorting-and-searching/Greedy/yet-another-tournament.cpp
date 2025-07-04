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

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353

using namespace std;

int T, N;
ll M;
pll a[500005];
ll b[500005];

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            ll x;
            cin >> x;
            a[i] = {x, i};
        }
        sort(a, a+N);
        ll sum = 0;
        ll ans = -1;
        for (int i = 0; i < N; i++) {
            sum += a[i].first;
            if (sum > M) {
                ans = i;
                break;
            }
        }
        if (ans == -1) {
            cout << 1 << endl;
            continue;
        } else {
            for (int i = 0; i < N; i++) {
                b[i] = i+1;
            }
            for (int i = 0; i < ans; i++) {
                b[a[i].second]--;
            }
            cout << "b: ";
            for (int i = 0; i < N; i++) {
                cout << b[i] << " ";
            }
            cout << endl;
            cout << "ans: " << ans << endl;
            sort(b, b+N, greater<ll>());
            for (int i = 0; i < N; i++) {
                if (ans >= b[i]) {
                    cout << i+1 << endl;
                    break;
                }
            }
            if (ans < b[N-1]) {
                cout << N+1 << endl;
            }
        }
    }
}