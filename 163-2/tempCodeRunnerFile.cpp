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
        if (N==2) {
            cout << "2 1" << endl;
            cout << (K>1?1:2) << endl;
            cout << "1 1" << endl;
            continue;
        }
        vt<int> id(N+1);
        vt<int> cli(N+1);
        int ans = ceil((double)N/(double)K);
        int cnt = 1;
        for (int i = 1; i <= N; i+=K) {
            if (i+K>N) {
                id[i]=i;
                for (int j = i+1; j<=N; j++) {
                    id[j]=N-(j-i)+1;
                }
                for (int j = i; j<=N; j++) {
                    cli[j]=cnt;
                }
            } else {
                id[i]=i;
                for (int j = i+1; j<i+K; j++) {
                    id[j]=i+K-(j-i);
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