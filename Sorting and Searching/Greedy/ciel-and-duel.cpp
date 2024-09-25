#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>

#define ll long long

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    multiset<int> atk;
    multiset<int> def;
    multiset<int> self;
    for (int i = 0; i < N; i++) {
        string name;
        int a;
        cin >> name >> a;
        if (name == "ATK") {
            atk.insert(a);
        } else {
            def.insert(a);
        }
    }
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        self.insert(a);
    }
    // cout << "atk: ";
    // for (auto it = atk.begin(); it != atk.end(); it++) {
    //     cout << *it << " ";
    // }
    // cout << endl;
    // cout << "def: ";
    // for (auto it = def.begin(); it != def.end(); it++) {
    //     cout << *it << " ";
    // }
    // cout << endl;
    // cout << "self: ";
    // for (auto it = self.begin(); it != self.end(); it++) {
    //     cout << *it << " ";
    // }
    // cout << endl;
    int ans = 0;
    auto it = atk.begin();
    auto it2 = self.end();
    it2--;
    int current = 0;
    while (true) {
        if (*it > *it2 || it == atk.end()) {
            break;
        } else {
            current += *it2 - *it;
            it++;
            if (it == atk.end()) {
                break;
            }
            if (it2 == self.begin()) {
                break;
            }
            it2--;
        }
        //cout << "current: " << current << endl;
    }
    ans = max(ans, current);
    //cout << ans << endl;
    if (M > N) {
        bool flag = false;
        for (auto it = def.begin(); it != def.end(); it++) {
            auto it2 = self.upper_bound(*it);
            if (it2 == self.end()) {
                flag = true;
                break;
            } else {
                self.erase(it2);
            }
        }
        // cout << "flag: " << flag << endl;
        // cout << "self: ";
        // for (auto it = self.begin(); it != self.end(); it++) {
        //     cout << *it << " ";
        // }
        // cout << endl;
        if (!flag) {
            current = 0;
            while (true) {
                auto it = atk.begin();
                auto it2 = self.lower_bound(*it);
                if (it == atk.end() || it2 == self.end()) {
                    break;
                } else {
                    current += *it2 - *it;
                    self.erase(it2);
                    atk.erase(it);
                }
            }  
            if (atk.empty()) {
                for (auto it = self.begin(); it != self.end(); it++) {
                    current += *it;
                }
            }
            ans = max(ans, current);
        }
    }
    cout << ans << endl;
}