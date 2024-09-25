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
#include <chrono>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

int T, N;
ll a[200001];
pll orig[200001];
pll mod[200001]; // give, get
map<int, map<int, int>> m;

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        ll total = 0;
        for (int i = 1; i <= N; i++) {
            ll x;
            cin >> x;
            a[i] = x;
            total += x;
        }
        if (total%N != 0) {
            cout << "No" << endl;
            continue;
        }
        ll avg = total/N;
        for (int i = 0; i < N; i++) {
            if (a[i] > avg) {
                orig[i] = {a[i]-avg, 0};
                int n = a[i]-avg;
                int z = 0;
                while ((n&1) == 0) {
                    z++;
                    n >>= 1;
                }
                bool works = true;
                int o = 0;
                while (n > 0) {
                    if ((n&1) == 1) {
                        o++;
                    } else {
                        works = false;
                        break;
                    }
                    n >>= 1;
                }
                if (!works) {
                    mod[i] = {-1, -1};
                } else {
                    mod[i] = {z, o+z};
                    m[z][o+z]++;
                }
            } else if (a[i] < avg) {
                orig[i] = {0, avg-a[i]};
                int n = avg-a[i];
                int z = 0;
                while ((n&1) == 0) {
                    z++;
                    n >>= 1;
                }
                bool works = true;
                int o = 0;
                while (n > 0) {
                    if ((n&1) == 1) {
                        o++;
                    } else {
                        works = false;
                        break;
                    }
                    n >>= 1;
                }
                if (!works) {
                    mod[i] = {-1, -1};
                } else {
                    mod[i] = {z, o+z};
                    m[z][o+z]++;
                }
            } else {
                orig[i] = {0, 0};
                mod[i] = {-2, -2};
            }
        }
        bool works = true;

    }
}