#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>

#define ll long long

using namespace std;

int main() {
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int N;
    cin >> N;
    set<int, greater<int>> opp1;
    set<int> opp2;
    set<int, greater<int>> own;
    for (int i = 1; i <= 2*N; i++) {
        own.insert(i);
    }
    for (int i = 0; i < N/2; i++) {
        int a;
        cin >> a;
        opp1.insert(a);
        own.erase(a);
    }
    for (int i = 0; i < N/2; i++) {
        int a;
        cin >> a;
        opp2.insert(a);
        own.erase(a);
    }
    set<int, greater<int>> own1;
    set<int> own2;
    for (int i = 1; i <= N/2; i++) {
        own1.insert(*own.begin());
        own.erase(own.begin());
    }
    for (int i = 1; i <= N/2; i++) {
        own2.insert(*own.begin());
        own.erase(own.begin());
    }
    int ans = 0;
    auto it = opp1.begin();
    auto it2 = own1.begin();
    while (it != opp1.end() && it2 != own1.end()) {
        if (*it2 > *it) {
            ans++;
            it2++;
            it++;
        } else {
            it++;
        }
    }
    it = opp2.begin();
    it2 = own2.begin();
    while (it != opp2.end() && it2 != own2.end()) {
        if (*it2 < *it) {
            ans++;
            it2++;
            it++;
        } else {
            it++;
        }
    }
    cout << ans << endl;
}