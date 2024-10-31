#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>

#define ll long long

using namespace std;

int main() {
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    int N;
    cin >> N;
    set<int, greater<int>> opp;
    set<int, greater<int>> own;
    for (int i = 1; i <= 2*N; i++) {
        own.insert(i);
    }
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        opp.insert(a);
        own.erase(a);
    }
    auto it = opp.begin();
    auto it2 = own.begin();
    int ans = 0;
    while (it != opp.end() && it2 != own.end()) {
        if (*it2 > *it) {
            ans++;
            it2++;
            it++;
        } else {
            it++;
        }
    }
    cout << ans << endl;
}