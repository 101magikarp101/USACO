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

int T, N, K;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        vt<int> id(N+1);
        vt<int> cli(N+1);
        int ans = ceil((double)N/(double)K);
        K=min(K, N);
        int cnt = 1;
        for (int i = 1; i <= N; i+=K) {
            if (i+K>N) {
                K=N-i+1;
                // cout << "K: " << K << endl;
                for (int j = i; j<=N; j++) {
                    id[j]=j+(K/2);
                    if (id[j]>N) id[j]-=K;
                }
                for (int j = i; j<=N; j++) {
                    cli[j]=cnt;
                }
            } else {
                for (int j = i; j<i+K; j++) {
                    id[j]=j+(K/2);
                    if (id[j]>=i+K) id[j]-=K;
                }
                for (int j = i; j<i+K; j++) {
                    cli[j]=cnt;
                }
            }
            cnt++;
        }
        for (int i = 1; i <= N; i++) {
            cout << id[i] << " ";
        }
        cout << endl;
        cout << ans << endl;
        for (int i = 1; i <= N; i++) {
            cout << cli[i] << " ";
        }
        cout << endl;
    }
    return 0;
}