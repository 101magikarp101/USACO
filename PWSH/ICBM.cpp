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

int N, Q;
int a[1005][1005];
unordered_map<char, int> m;
int pre[1005][1005];

int getval (char c) {
    if (c=='p') return 1;
    if (c=='n') return 3;
    if (c=='b') return 3;
    if (c=='r') return 5;
    if (c=='q') return 9;
    return 0;
}

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= N; j++) {
            char c = s[j-1];
            if ((int)c >= 65 && (int)c <= 90) {
                a[i][j] = -getval(c+32);
            } else {
                a[i][j] = getval(c);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            pre[i][j] = a[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }
    for (int i = 0; i < Q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1] << endl;
    }
}