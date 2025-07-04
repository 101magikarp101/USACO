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
#define pll pair<ll, ll>
#define LLONG_MAX 9223372036854775807
#define MOD 1000000007

using namespace std;

struct node {
    ll val = 0;
    node* c[26];
};

int N;
node* root;
string str[1000001];

void add(string s) {
    node* cur = root;
    for (int i = 0; i < s.size(); i++) {
        if (cur->c[s[i]-'a'] == NULL) {
            cur->c[s[i]-'a'] = new node();
        }
        cur = cur->c[s[i]-'a'];
        cur->val++;
    }
}

ll find(string s) {
    node* cur = root;
    ll res = 0;
    for (int i = 0; i < s.size(); i++) {
        // cout << "s[i]: " << s[i] << endl;
        if (cur->c[s[i]-'a'] == NULL) {
            break;
        }
        cur = cur->c[s[i]-'a'];
        res += cur->val;
    }
    // cout << "s: " << s << ", res: " << res << endl;
    return res;
}

int main() {
    root = new node();
    cin >> N;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        add(s);
        sum += s.size();
        str[i] = s;
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        string s = str[i];
        reverse(s.begin(), s.end());
        ans += N*s.size()+sum-2*find(s);
    }
    cout << ans << endl;
}