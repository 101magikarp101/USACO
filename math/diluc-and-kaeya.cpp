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

struct frac {
    ll d, k;
};

bool operator<(const frac& a, const frac& b) {
    return a.d*b.k < a.k*b.d;
}

int T, N;
string s;
int D, K;
map<frac, int> m;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a%b);
}

int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        cin >> s;
        m.clear();
        D = 0;
        K = 0;
        for (int i = 0; i < N; i++) {
            if (s[i] == 'D') {
                D++;
            } else {
                K++;
            }
            frac f;
            if (D == 0) {
                f = {0, 1};
                m[{0, 1}]++;
            } else if (K == 0) {
                f = {1, 0};
                m[{1, 0}]++;
            } else {
                int g = gcd(D, K);
                f = {D/g, K/g};
                m[f]++;
            }
            cout << m[f] << " ";
        }
        cout << endl;
    }
}