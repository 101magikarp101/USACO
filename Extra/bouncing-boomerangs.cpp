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

struct boom {
    int r, c, v;
};

int N;
deque<boom> two;
deque<boom> three;

int main () {
    cin >> N;
    bool ans = true;
    vt<boom> v;
    int next = 1;
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        if (!ans) continue;
        if (x == 1) {
            if (!two.empty()) {
                boom b = two.front();
                two.pop_front();
                v.push_back({b.r, i, 1});
            } else if (!three.empty()) {
                boom b = three.front();
                three.pop_front();
                v.push_back({b.r, i, 1});
                v.push_back({next, i, 1});
                next++;
            } else {
                v.push_back({next, i, 1});
                next++;
            }
        } else if (x == 2) {
            if (!three.empty()) {
                boom b = three.front();
                three.pop_front();
                v.push_back({b.r, i, 2});
                v.push_back({next, i, 2});
                two.push_back({next, i, 2});
                next++;
            } else {
                two.push_back({next, i, 2});
                v.push_back({next, i, 2});
                next++;
            }
        } else if (x == 3) {
            if (!three.empty()) {
                boom b = three.front();
                three.pop_front();
                v.push_back({b.r, i, 3});
                v.push_back({next, i, 3});
                three.push_back({next, i, 3});
                next++;
            } else {
                v.push_back({next, i, 3});
                three.push_back({next, i, 3});
                next++;
            }
        }
    }
    if (!three.empty()) ans = false;
    if (!two.empty()) ans = false;
    if (next > N+1) ans = false;
    if (!ans) {
        cout << -1 << endl;
    } else {
        cout << v.size() << endl;
        for (int i = 0; i < v.size(); i++) {
            cout << v[i].r << " " << v[i].c << endl;
        }
    }
}