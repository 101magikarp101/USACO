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
struct pii {int x, y;};
struct pll {int x, y;};

int T, N, M;
ll a[100005];
ll nei[100005];
ll pre[100005], suf[100005];

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
            pre[i]=suf[i]=0;
        }
        nei[1]=2;
        nei[N]=N-1;
        pre[1]=1;
        suf[N]=1;
        for (int i = 2; i < N; i++) {
            ll d1 = abs(a[i]-a[i-1]);
            ll d2 = abs(a[i]-a[i+1]);
            nei[i]=(d1<d2?i-1:i+1);
            if (nei[i]==i-1) {
                suf[i]=1;
                pre[i]=d2;
            } else {
                pre[i]=1;
                suf[i]=d1;
            }
        }
        for (int i = 1; i <= N; i++) {
            pre[i]+=pre[i-1];
        }
        for (int i = N; i >= 1; i--) {
            suf[i]+=suf[i+1];
        }
        // cout << "pre: ";
        // for (int i = 1; i <= N; i++) {
        //     cout << pre[i] << " ";
        // }
        // cout << endl;
        // cout << "suf: ";
        // for (int i = 1; i <= N; i++) {
        //     cout << suf[i] << " ";
        // }
        // cout << endl;
        cin >> M;
        for (int i = 0; i < M; i++) {
            int s, e; cin >> s >> e;
            ll ans = 0;
            if (e>s) {
                ans = pre[e-1]-pre[s-1];
            } else {
                ans = suf[e+1]-suf[s+1];
            }
            cout << ans << endl;
        }
    }
    return 0;
}