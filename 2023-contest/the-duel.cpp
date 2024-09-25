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

using namespace std;

ll gcd(ll a, ll b) {
    if (a == 0) {
        return b;
    }
    return gcd(b%a, a);
}

pair<ll, ll> sub(pair<ll, ll> a, pair<ll, ll> b) {
    pair<ll, ll> c = {a.first*b.second-b.first*a.second, a.second*b.second};
    ll g = gcd(c.first, c.second);
    c.first /= g;
    c.second /= g;
    return c;
}

ll N;
int M;

void solve(pair<ll, ll> n, int m, vector<ll> v) {
    if (m == 2) {
        // cout << n.first << " " << n.second << endl;
        ll b = n.second*n.second;
        // cout << b << endl;
        for (int i = 1; i <= n.second; i++) {
            if (b%i == 0 && (i+n.second) % n.first == 0 && (i+n.second)/n.first >= v.back() && (b/i+n.second) % n.first == 0) {
                // cout << i << " " << N/i << endl;
                for (int j = 0; j < v.size(); j++) {
                    cout << v[j] << " ";
                }
                cout << (i+n.second)/n.first << " " << (b/i+n.second)/n.first << endl;
                // double sum = 0;
                // for (int j = 0; j < v.size(); j++) {
                //     sum += 1.0/v[j];
                // }
                // sum += 1.0/((i+n.second)/n.first);
                // sum += 1.0/((b/i+n.second)/n.first);
                // cout << sum << endl;
            }
        }
    } else {
        ll mi = max((n.second/n.first)+1, v.size() == 0 ? 1 : v.back());
        ll ma = n.second*m/n.first;
        for (ll i = mi; i <= ma; i++) {
            pair<ll, ll> n1 = sub(n, {1, i});
            vector<ll> v1 = v;
            v1.push_back(i);
            solve(n1, m-1, v1);
        }
    }
}

ll solve1(pair<ll, ll> n, int m, vector<ll> v) {
    if (m == 2) {
        // cout << n.first << " " << n.second << endl;
        ll b = n.second*n.second;
        // cout << b << endl;
        ll count = 0;
        for (int i = 1; i <= n.second; i++) {
            if (b%i == 0 && (i+n.second) % n.first == 0 && (i+n.second)/n.first >= v.back() && (b/i+n.second) % n.first == 0) {
                // cout << i << " " << N/i << endl;
                count++;
                // double sum = 0;
                // for (int j = 0; j < v.size(); j++) {
                //     sum += 1.0/v[j];
                // }
                // sum += 1.0/((i+n.second)/n.first);
                // sum += 1.0/((b/i+n.second)/n.first);
                // cout << sum << endl;
            }
        }
        return count;
    } else {
        ll count = 0;
        ll mi = max((n.second/n.first)+1, v.size() == 0 ? 1 : v.back());
        ll ma = n.second*m/n.first;
        for (ll i = mi; i <= ma; i++) {
            pair<ll, ll> n1 = sub(n, {1, i});
            vector<ll> v1 = v;
            v1.push_back(i);
            count += solve1(n1, m-1, v1);
        }
        return count;
    }
}

int main() {
    cin >> M >> N;
    // solve({1, N}, M, {});
    // start timer in nano seconds
    auto start = chrono::high_resolution_clock::now();
    cout << solve1({1, N}, M, {}) << endl;
    // stop timer in micro seconds
    auto stop = chrono::high_resolution_clock::now();
    cout << "Time taken: " << chrono::duration_cast<chrono::microseconds>(stop-start).count() << " microseconds" << endl;
}