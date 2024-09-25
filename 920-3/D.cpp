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

int T, N, M;
ll a[200005], b[200005];
ll pre[200005], suf[200005];

int main () {
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> b[i];
        }
        sort(a, a+N);
        sort(b, b+M, greater<ll>());
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            pre[i] = abs(a[i]-b[i]);
            if (i > 0) pre[i]+=pre[i-1];
        }
        for (int i = N-1; i >= 0; i--) {
            suf[i] = abs(a[i]-b[i-(N-M)]);
            if (i < N-1) suf[i]+=suf[i+1];
        }
        for (int i = 0; i < N; i++) {
            if (i == N-1) ans = max(ans, pre[i]);
            else if (i == 0) ans = pre[i]+suf[i+1];
            else ans = max(ans, pre[i]+suf[i+1]);
        }
        ans = max(ans, suf[0]);
        cout << ans << endl;
    }
}