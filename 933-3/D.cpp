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
struct pii {int x, y;};
struct pll {int x, y;};

int T, N, M, X;

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> M >> X;
        set<int> s;
        set<int> next;
        s.insert(X-1);
        for (int i = 0; i < M; i++) {
            int j; cin >> j;
            char c; cin >> c;
            if (c=='0') {
                for (int i : s) {
                    next.insert((i+j)%N);
                }
            } else if (c=='1') {
                for (int i : s) {
                    next.insert((i-j+N)%N);
                }
            } else {
                for (int i : s) {
                    next.insert((i+j)%N);
                    next.insert((i-j+N)%N);
                }
            }
            s = next;
            next.clear();
        }
        cout << s.size() << endl;
        for (int i : s) {
            cout << i+1 << " ";
        }
        cout << endl;
    }
    return 0;
}