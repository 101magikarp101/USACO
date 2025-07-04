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
#define LLONG_MAX 9223372036854775807

using namespace std;

ll N, M;
ll s[100001];
ll dp[100001];

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }
    int prev = 0;
    for (int i = N-2; i >= 0; i--) {
        if (s[i+1]-s[i] > M) {
            s[i] = s[i+1]-M;
        }
    }
    for (int i = 1; i < N; i++) {
        if (s[i-1]-s[i] > M) {
            s[i] = s[i-1]-M;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << s[i] << " ";
    }
    cout << endl;
}