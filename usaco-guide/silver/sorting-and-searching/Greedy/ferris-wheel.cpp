#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>

#define ll long long

using namespace std;

int main() {
    ll N, X;
    cin >> N >> X;
    ll arr[200000];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N, greater<ll>());
    multiset<ll, greater<ll>> gondolas;
    int count = 0;
    for (int i = 0; i < N; i++) {
        auto it = gondolas.lower_bound(X - arr[i]);
        if (it == gondolas.end()) {
            gondolas.insert(arr[i]);
        } else {
            gondolas.erase(gondolas.find(*it));
            count++;
        }
        // cout << "Gondolas: ";
        // for (auto it = gondolas.begin(); it != gondolas.end(); it++) {
        //     cout << *it << " ";
        // }
        // cout << endl;
    }
    cout << count + gondolas.size() << endl;
}