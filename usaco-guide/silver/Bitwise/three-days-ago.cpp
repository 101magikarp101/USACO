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

using namespace std;

map<ll, ll> m;

int main() {
    string s;
    cin >> s;
    int N = s.length();
    ll ans = 0;
    bool cur[10];
    memset(cur, 0, sizeof(cur));
    m[0] = 1;
    for (int i = 0; i < N; i++) {
        int temp = s[i]-'0';
        cur[temp] = !cur[temp];
        ll rep = 0;
        for (int j = 0; j < 10; j++) {
            rep += cur[j] << j;
        }
        ans += m[rep];
        m[rep]++;
    }
    cout << ans << endl;
}