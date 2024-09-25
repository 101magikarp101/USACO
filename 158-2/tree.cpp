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

#define ll long long

using namespace std;

struct node {
    ll val;
    vector<int> c;
};

int T, N;
node* arr[500005];
bool vis[500005];
vector<ll> v;
int root = 0;

ll search(int n) {
    if (vis[n]) {
        return 0;
    }
    vis[n] = true;
    ll cur = 0;
    if (arr[n]->c.size() == 1) {
        cur += arr[n]->val;
    } else if (arr[n]->c.size() == 2) {
        for (int i = 0; i < arr[n]->c.size(); i++) {
            if (!vis[arr[n]->c[i]]) {
                cur += max(arr[n]->val, search(arr[n]->c[i]));
            }
        }
    } else {
        vector<ll> vals;
        for (int i = 0; i < arr[n]->c.size(); i++) {
            vals.push_back(search(arr[n]->c[i]));
        }
        sort(vals.begin(), vals.end(), greater<ll>());
        ll temp = 0;
        ll cnt = 0;
        for (int i = 0; i < vals.size(); i++) {
            if (vals[i] > 0) {
                temp += vals[i];
                cnt++;
            }
        }
        if (cnt == 1) {
            temp = max(arr[n]->val, vals[0]);
        } else if (n == root && cnt == 2) {
            temp = max(arr[n]->val, vals[0]+vals[1]);
        } else if (temp == 0) {
            temp = max(arr[n]->val, vals[0]);
        } else {
            temp += arr[n]->val;
        }
        cur += temp;
    }
    cout << "n: " << n << " cur: " << cur << endl;
    return cur;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        v.clear();
        for (int i = 1; i <= N; i++) {
            arr[i] = new node;
            arr[i]->val = 0;
            arr[i]->c.clear();
        }
        // cout << "pass1" << endl;
        for (int i = 1; i <= N; i++) {
            ll x;
            cin >> x;
            arr[i]->val = x;
            v.push_back(x);
        }
        // cout << "pass2" << endl;
        for (int i = 0; i < N-1; i++) {
            int a, b;
            cin >> a >> b;
            arr[a]->c.push_back(b);
            arr[b]->c.push_back(a);
        }
        // cout << "pass3" << endl;
        sort(v.begin(), v.end(), greater<ll>());
        ll ans = v[0]+v[1];
        // cout << "ans: " << ans << endl;
        for (int i = 1; i <= N; i++) {
            if (arr[i]->c.size() >= 3) {
                memset(vis, false, sizeof(vis));
                cout << "i: " << i << endl;
                root = i;
                ans = max(ans, search(i));
            }
        }
        cout << max((ll)0, ans) << endl;
    }
}