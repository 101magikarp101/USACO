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
#include <unordered_set>

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

int T, N;
int a[2002];
int tar[2002];

void xo(int x) {
    for (int i = 0; i < N; i++) {
        if (i+x < N && i+x >= 0) {
            a[i] ^= a[i+x];
        }
    }
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        string s;
        cin >> s;
        int fone = -1;
        for (int i = 0; i < N; i++) {
            a[i] = s[i]-'0';
            if (a[i] == 1 && fone == -1) {
                fone = i;
            }
        }
        cin >> s;
        for (int i = 0; i < N; i++) {
            tar[i] = s[i]-'0';
        }
        vector<int> ans;
        bool good = true;
        for (int i = 0; i < N; i++) {
            if (tar[i] != a[i]) {
                good = false;
                break;
            }
        }
        if (good) {
            cout << 0 << endl;
            continue;
        }
        if (fone == -1) {
            cout << -1 << endl;
            continue;
        }
        good = true;
        for (int i = 0; i < N; i++) {
            if (a[i] == tar[i]) {
                continue;
            }
            int shift = fone-i;
            fone = min(fone, i);
            if (shift == 0) {
                good = false;
                break;
            }
            xo(shift);
            ans.push_back(shift);
        }
        if (!good) {
            cout << -1 << endl;
            continue;
        } else {
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
}