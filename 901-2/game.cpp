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

using namespace std;

ll T, N, M, K;
deque<ll> a, b;

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> M >> K;
        for (int i = 0; i < N; i++) {
            ll x;
            cin >> x;
            a.push_back(x);
        }
        for (int i = 0; i < M; i++) {
            ll x;
            cin >> x;
            b.push_back(x);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool swapped = false;
        if (a[0] > b.back()) {
            swap(a, b);
            swapped = true;
            K--;
        }
        if (K >= 2) {
            if (a[0] > b[0]) {
                ll tmp = a[0];
                ll tmp1 = b[0];
                a.pop_front();
                b.pop_front();
                a.push_front(tmp1);
                b.push_front(tmp);
            }
            if (a.back() > b.back()) {
                ll tmp = a.back();
                ll tmp1 = b.back();
                a.pop_back();
                b.pop_back();
                a.push_back(tmp1);
                b.push_back(tmp);
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (K % 2 == 1 && a.front() <= b.back()) {
            ll tmp = a.front();
            ll tmp1 = b.back();
            a.pop_front();
            b.pop_back();
            a.push_front(tmp1);
            b.push_back(tmp);
        }
        if (swapped) {
            swap(a, b);
        }
        ll ans = 0;
        for (int i = 0; i < a.size(); i++) {
            ans += a[i];
        }
        cout << ans << endl;
        a.clear();
        b.clear();
    }
}