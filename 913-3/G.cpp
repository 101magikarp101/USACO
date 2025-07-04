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

struct node {
    bool on = false;
    bool vis = false;
    vector<int> from;
    int to = -1;
};

int T, N;
string s;
node* a[100005];

int main () {
    cin >> T;
    while (T--) {
        cin >> N >> s;
        for (int i = 1; i <= N; i++) {
            int x; cin >> x;
            a[i] = new node();
            a[i]->on = s[i-1] == '1';
            a[i]->to = x;
            a[x]->from.push_back(i);
        }
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            if (a[i]->vis) continue;
            if (a[i]->on) {
            }
        }
        cout << ans << endl;
    }
}
