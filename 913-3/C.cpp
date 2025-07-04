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
#define MOD 1000000007

using namespace std;

int T, N;
string s;
map<char, int> m;

int main() {
    cin >> T;
    while (T--) {
        m.clear();
        cin >> N;
        cin >> s;
        for (int i = 0; i < N; i++) {
            m[s[i]]++;
        }
        int ma = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second > ma) {
                ma = it->second;
            }
        }
        cout << max(N%2==0?0:1, ma-(N-ma)) << endl;
    }
}