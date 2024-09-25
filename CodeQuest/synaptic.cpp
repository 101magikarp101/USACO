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

struct node {
    double d, y;
    vt<double> w;
    node () {}
};

int T, N;
double in[64];

double solve(int i, int j, vt<vt<node>> &a) {
    if (i==0) {
        double res = a[i][j].d;
        for (int k = 0; k < 64; k++) {
            res += in[k]*a[i][j].w[k];
        }
        return max(0.0, res);
    } else {
        double res = a[i][j].d;
        for (int k = 0; k < a[i-1].size(); k++) {
            res += a[i-1][k].y*a[i][j].w[k];
        }
        return max(0.0, res);
    }
}

int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        vt<vt<node>> a(N);
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            a[i].resize(x);
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < a[i].size(); j++) {
                if (i==0) {
                    for (int k = 0; k < 64; k++) {
                        double x; cin >> x;
                        a[i][j].w.push_back(x);
                    }
                    double d; cin >> d;
                    a[i][j].d = d;
                } else {
                    for (int k = 0; k < a[i-1].size(); k++) {
                        double x; cin >> x;
                        a[i][j].w.push_back(x);
                    }
                    double d; cin >> d;
                    a[i][j].d = d;
                }
            }
        }
        for (int i = 0; i < 64; i++) {
            cin >> in[i];
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < a[i].size(); j++) {
                a[i][j].y = solve(i, j, a);
            }
        }
        double ans = -1;
        int idx = -1;
        for (int i = 0; i < a[N-1].size(); i++) {
            if (a[N-1][i].y > ans) {
                ans = a[N-1][i].y;
                idx = i;
            }
        }
        if (idx == 0) {
            cout << "STOP_SIGN" << endl;
        } else if (idx == 1) {
            cout << "YIELD" << endl;
        } else if (idx == 2) {
            cout << "LANE_ENDS" << endl;
        } else if (idx == 3) {
            cout << "SPEED_LIMIT" << endl;
        } else if (idx == 4) {
            cout << "CROSSWALK" << endl;
        }
    }
}