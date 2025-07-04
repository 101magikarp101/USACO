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

int N;
ll a[21];
ll b[21];

int main () {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
    sort(a, a+N);
    sort(b, b+N);
    ll ans = 1;
    for (int i = N-1; i >= 0; i--) {
        int idx = lower_bound(b, b+N, a[i])-b;
        ans *= N-idx - (N-1-i);
    }
    cout << ans << endl;
}