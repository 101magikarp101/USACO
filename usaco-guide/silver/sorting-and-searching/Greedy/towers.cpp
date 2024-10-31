#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>

#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    multiset<int> towers;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        auto it = towers.upper_bound(x);
        if (it == towers.end()) {
            towers.insert(x);
        } else {
            towers.erase(it);
            towers.insert(x);
        }
    }
    cout << towers.size() << endl;
}