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

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int T, N;
vt<string> a;
string hmm[3] = {"169", "961"};

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        a.clear();
        for (int i = 0; i < 2; i++) {
            a.push_back(hmm[i]);
        }
        a.push_back("196");
        if (N == 1) {
            cout << 1 << endl;
            continue;
        }
        for (int i = 1; i < (N-1)/2; i++) {
            vt<string> b;
            for (int j = 0; j < a.size(); j++) {
                b.push_back(a[j]+"00");
            }
            for (int j = 0; j < 2; j++) {
                string s = hmm[j][0] + string(i, '0') + hmm[j][1] + string(i, '0') + hmm[j][2];
                b.push_back(s);
            }
            a = b;
        }
        for (int i = 0; i < N; i++) {
            cout << a[i] << endl;
        }
    }
}