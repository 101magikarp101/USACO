#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    multiset<int, greater<int>> tickets;
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        tickets.insert(t);
    }
    for (int i = 0; i < M; i++) {
        int p;
        cin >> p;
        auto it = tickets.lower_bound(p);
        if (it == tickets.end()) {
            cout << -1 << endl;
        } else {
            cout << *it << endl;
            tickets.erase(it);
        }
    }
}