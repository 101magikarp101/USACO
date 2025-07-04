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

using namespace std;

int T;

int main() {
    cin >> T;
    for (int t = 0; t < T; t++) {
        string s;
        cin >> s;
        int m;
        cin >> m;
        string l, r;
        cin >> l >> r;
        int index = 0;
        set<int> target;
        for (int i = l[index]; i <= r[index]; i++) {
            target.insert(i);
        }
        for (int i = 0; i < s.length(); i++) {
            if (target.find(s[i]) != target.end()) {
                target.erase(s[i]);
            }
            if (target.size() == 0) {
                index++;
                if (index == m) {
                    cout << "NO" << endl;
                    break;
                }
                for (int i = l[index]; i <= r[index]; i++) {
                    target.insert(i);
                }
            }
        }
        if (target.size() != 0) {
            cout << "YES" << endl;
        }
    }
}