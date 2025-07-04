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

int T, N;
ll F, A, B;
ll m[200005];

int main () {
    cin >> T;
    while (T--) {
        cin >> N >> F >> A >> B;
        for (int i = 1; i <= N; i++) {
            cin >> m[i];
        }
        bool ans = true;
        for (int i = 1; i <= N; i++) {
            F-=min((m[i]-m[i-1])*A, B);
            if (F <= 0) {
                ans = false;
                break;
            }
        }
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}