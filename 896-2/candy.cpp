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


int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        ll total = 0;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            total += a[i];
        }
        if (total%N != 0) {
            cout << "No" << endl;
            continue;
        }
        ll avg = total/N;
        ll get[200001];
        ll give[200001];
        memset(get, 0, sizeof(get));
        memset(give, 0, sizeof(give));
        bool works = true;
        for (int i = 0; i < N; i++) {
            if (a[i] > avg) {
                give[i] = a[i]-avg;
                int n = give[i];
                //find the number of 0s at the end of give
                int zeros = 0;
                while ((n&1) == 0) {
                    zeros++;
                    n >>= 1;
                }
                int ones = 0;
                while (n > 0) {
                    if ((n&1) == 1) {
                        ones++;
                    } else {
                        works = false;
                        break;
                    }
                    n >>= 1;
                }
                if (!works) {
                    break;
                }
                get[i] = zeros;
                give[i] = ones+zeros;
            } else if (a[i] < avg) {
                get[i] = avg-a[i];
                int n = get[i];
                //find the number of 0s at the end of get
                int zeros = 0;
                while ((n&1) == 0) {
                    // cout << bitset<10>(n).to_string() << endl;
                    zeros++;
                    n >>= 1;
                }
                int ones = 0;
                while (n > 0) {
                    // cout << bitset<10>(n).to_string() << endl;
                    if ((n&1) == 1) {
                        ones++;
                    } else {
                        works = false;
                        break;
                    }
                    n >>= 1;
                }
                if (!works) {
                    break;
                }
                give[i] = zeros;
                get[i] = ones+zeros;
            } else {
                get[i] = -1;
                give[i] = -1;
            }
        }
        if (!works) {
            cout << "No" << endl;
            continue;
        }
        sort(get, get+N);
        sort(give, give+N);
        for (int i = 0; i < N; i++) {
            if (get[i] != give[i]) {
                works = false;
                break;
            }
        }
        if (works) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}