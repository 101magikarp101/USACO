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
ll C;
ll a[300005];

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> C;
        ll hmm = 0;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < N; i++) {
            hmm += max(0LL, min(a[i]+1))
        }
    }
    return 0;
}