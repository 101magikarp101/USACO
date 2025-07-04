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

int T, N, K;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i=0; i<2*N; i++) {
            cin >> a[i];
        }
        map<int, int> m1, m2;
        vt<int> v1, v2;
        for (int i=0; i<N; i++) {
            m1[a[i]]++;
            if (m1[a[i]]==2 && v1.size()<2*K) {
                v1.push_back(a[i]);
                v1.push_back(a[i]);
                m1.erase(a[i]);
            } else if (m1[a[i]]==2 && v1.size()>=2*K) {
                m1.erase(a[i]);
            }
        }
        for (int i=N; i<2*N; i++) {
            m2[a[i]]++;
            if (m2[a[i]]==2 && v2.size()<2*K) {
                v2.push_back(a[i]);
                v2.push_back(a[i]);
                m2.erase(a[i]);
            } else if (m2[a[i]]==2 && v2.size()>=2*K) {
                m2.erase(a[i]);
            }
        }
        while (v1.size()<2*K) {
            v1.push_back(m1.begin()->first);
            v2.push_back(m2.begin()->first);
            m1.erase(m1.begin());
            m2.erase(m2.begin());
        }
        for (int i=0; i<2*K; i++) {
            cout << v1[i] << " ";
        } 
        cout << endl;
        for (int i=0; i<2*K; i++) {
            cout << v2[i] << " ";
        }
        cout << endl;
    }
    return 0;
}