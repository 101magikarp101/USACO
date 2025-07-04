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

int N;
double a[50002];

int sim(double n, double d) {
    bool lf = false;
    bool rf = false;
    int l = upper_bound(a, a+N, n) - a;
    int r = lower_bound(a, a+N, n) - a;
    cout << "n: " << n << " d: " << d << " l: " << l << " r: " << r << endl;
    int n1 = n;
    int d1 = d;
    while (d1 > 0) {
        while (l>0 && a[l-1] >= n1-d1) {
            l--;
        }
        if (l <= 0) {
            if (a[0] >= n1-d1) {
                lf = true;
                break;
            } else {
                break;
            }
        }
        if (a[l] < n1-d1) {
            break;
        }
        n1 -= d1;
        d1--;
    }
    n1 = n;
    d1 = d;
    while (d1 > 0) {
        while (r<N-1 && a[r+1] <= n1+d1) {
            r++;
        }
        if (r >= N-1) {
            if (r == N || a[r] <= n1+d1) {
                rf = true;
                break;
            } else {
                break;
            }
        }
        if (a[r] > n1+d1) {
            break;
        }
        n1 += d1;
        d1--;
    }
    cout << "n: " << n << " d: " << d << " l: " << l << " r: " << r << " lf: " << lf << " rf: " << rf << endl;
    if (lf && rf) {
        return 0;
    } else if (lf) {
        return -1;
    } else if (rf) {
        return 1;
    } else {
        return 2;
    }
}

bool check(double r) {
    double mi = 0;
    for (double i = N; i >= 0.01; i/=2) {
        int res = sim(mi+i, r);
        if (res == -1) {
            mi += i;
        } else if (res == 0) {
            cout << "mi: " << mi << " i: " << i << endl;
            return true;
        } else if (res == 2) {
            cout << "mi: " << mi << endl;
            return false;
        }
    }
    cout << "mi: " << mi << endl;
    return false;
}

int main() {
    // freopen("angry.in", "r", stdin);
    // freopen("angry.out", "w", stdout);
    cin >> N;
    double mi = 0;
    double ma = 0;
    for (int i = 0; i<N; i++) {
        cin >> a[i];
        a[i] *= 2;
        ma = max(ma, a[i]);
    }
    sort(a, a+N);
    for (double i = ma/2; i >= 0.01; i/=2) {
        if (!check(mi+i)) {
            mi += i;
        }
    }
    cout << fixed << setprecision(1) << mi << endl;
}