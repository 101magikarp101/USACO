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

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int T, N, K, X;
ll pre[200005];
ll a[200005];

int hmm(int x) {
    return max(0, x);
}

int main () {
    cin >> T;
    while (T--) {
        cin >> N >> K >> X;
        for (int i = 1; i <= N;i++) {
            cin >> a[i];
        }
        sort(a+1, a+N+1);
        pre[0]=0;
        for (int i = 1; i <= N; i++) {
            pre[i] = pre[i-1] + a[i];
        }
        ll sum = pre[N];
        ll ans = sum - 2*(pre[N]-pre[hmm(N-X)]);
        for (int i = N; i >= N-K+1; i--) {
            sum -= a[i];
            ll res = sum - 2*(pre[hmm(i-1)]-pre[hmm(i-X-1)]);
            ans = max(res, ans);
        }
        cout << ans << endl;
    }
}