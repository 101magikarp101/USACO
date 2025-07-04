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

int N;
map<ll, ll> m;

int main() {
    cin >> N;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        ll x = 0;
        for (int j = 0; j < s.size(); j++) {
            x^=(1LL<<(s[j]-'a'));
        }
        ans += m[x];
        for (int j = 0; j < 26; j++) {
            ans += m[x^(1LL<<j)];
        }
        m[x]++;
    }
    cout << ans << endl;
    return 0;
}