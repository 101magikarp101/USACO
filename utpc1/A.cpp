#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

string s;
int n;
int arr[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    n = s.size();
    set<int> a, b, c, o;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i]=='A') {
            if (a.empty()) {
                if (o.empty()) {
                    arr[cnt] = 1;
                    b.insert(cnt);
                    c.insert(cnt);
                    cnt++;
                } else {
                    int x = *o.begin();
                    o.erase(o.begin());
                    arr[x] = 1;
                    b.insert(x);
                    c.insert(x);
                }
            } else {
                int x = *a.begin();
                a.erase(a.begin());
                arr[x] |= 1;
                if (arr[x]==7) {
                    o.insert(x);
                    arr[x]=0;
                }
            }
        } else if (s[i]=='B') {
            if (b.empty()) {
                if (o.empty()) {
                    arr[cnt] = 2;
                    a.insert(cnt);
                    c.insert(cnt);
                    cnt++;
                } else {
                    int x = *o.begin();
                    o.erase(o.begin());
                    arr[x] = 2;
                    a.insert(x);
                    c.insert(x);
                }
            } else {
                int x = *b.begin();
                b.erase(b.begin());
                arr[x] |= 2;
                if (arr[x]==7) {
                    o.insert(x);
                    arr[x]=0;
                }
            }
        } else {
            if (c.empty()) {
                if (o.empty()) {
                    arr[cnt] = 4;
                    a.insert(cnt);
                    b.insert(cnt);
                    cnt++;
                } else {
                    int x = *o.begin();
                    o.erase(o.begin());
                    arr[x] = 4;
                    a.insert(x);
                    b.insert(x);
                }
            } else {
                int x = *c.begin();
                c.erase(c.begin());
                arr[x] |= 4;
                if (arr[x]==7) {
                    o.insert(x);
                    arr[x]=0;
                }
            }
        }
        // cout << "a: ";
        // for (int x : a) {
        //     cout << x << " ";
        // }
        // cout << "\n";
        // cout << "b: ";
        // for (int x : b) {
        //     cout << x << " ";
        // }
        // cout << "\n";
        // cout << "c: ";
        // for (int x : c) {
        //     cout << x << " ";
        // }
        // cout << "\n";
        // cout << "o: ";
        // for (int x : o) {
        //     cout << x << " ";
        // }
        // cout << "\n";
        // cout << "arr: ";
        // for (int j = 0; j < cnt; j++) {
        //     cout << arr[j] << " ";
        // }
        // cout << "\n";
        // cout << "\n";
    }
    cout << cnt << "\n";
    return 0;
}