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
ll M;

int main () {
    cin >> N >> M;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll a, b; cin >> a >> b;
        ans = max((ll)ceil(((double)M-a)/b), ans);
    }
    cout << ans+1 << endl;
}