#include <iostream>
#include <algorithm>
#include <set>
#include <map>

#define ll long long

using namespace std;

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    ll N, G;
    cin >> N >> G;
    map<ll, ll> cows;
    ll count = 0;
    map<ll, ll, greater<ll>> milk;
    milk[G] = 1000000000;
    tuple<ll, ll, ll> events[100000];
    pair<ll, ll> currentTop = {milk.begin()->first, milk.begin()->second};
    for (ll i = 0; i < N; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        events[i] = {a, b, c};
        cows[b] = G;
    }
    sort(events, events + N, [](tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) {
        return get<0>(a) < get<0>(b);
    });
    for (ll i = 0; i < N; i++) {
        ll index = get<1>(events[i]);
        ll oldMilk = cows[index];
        milk[cows[index]]--;
        if (milk[cows[index]] == 0) {
            milk.erase(cows[index]);
        }
        cows[index] += get<2>(events[i]);
        ll newMilk = cows[index];
        milk[cows[index]]++;
        pair<ll, ll> newTop = {milk.begin()->first, milk.begin()->second};
        // cout << "New top: " << newTop.first << " " << newTop.second << endl;
        // cout << "Current top: " << currentTop.first << " " << currentTop.second << endl;
        if (newTop.first != currentTop.first) {
            if (newTop.second == 1 && currentTop.second == 1 && oldMilk == currentTop.first && newMilk == newTop.first) {
                currentTop = newTop;
            } else {
                count += 1;
                currentTop = newTop;
            }
        } else if (newTop.second != currentTop.second) {
            count += 1;
            currentTop = newTop;
        }
        
        // cout << "Count: " << count << endl;
    }
    cout << count << endl;
}