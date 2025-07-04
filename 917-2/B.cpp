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

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

int T, N;
string s;
map<char, int> m;

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        cin >> s;
        m.clear();
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            m[s[i]]++;
            ans += m.size();
        }
        cout << ans << endl;
    }
}