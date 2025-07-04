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
    int val;
    int c[2];
};

int T, N;
node* tree[300005];

int solve(int n) {
    if (tree[n]->c[0] == 0 && tree[n]->c[1] == 0) {
        return 0;
    }
    if (tree[n]->c[0] == 0 && tree[n]->c[1] != 0) {
        if (tree[n]->val == 0 || tree[n]->val == 2) {
            return 1 + solve(tree[n]->c[1]);
        } else {
            return solve(tree[n]->c[1]);
        }
    }
    if (tree[n]->c[0] != 0 && tree[n]->c[1] == 0) {
        if (tree[n]->val == 1 || tree[n]->val == 2) {
            return 1 + solve(tree[n]->c[0]);
        } else {
            return solve(tree[n]->c[0]);
        }
    }
    if (tree[n]->c[0] != 0 && tree[n]->c[1] != 0) {
        int res0 = solve(tree[n]->c[0]);
        if (tree[n]-> val == 1 || tree[n]->val == 2) {
            res0++;
        }
        int res1 = solve(tree[n]->c[1]);
        if (tree[n]-> val == 0 || tree[n]->val == 2) {
            res1++;
        }
        return min(res0, res1);
    }
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        string s;
        cin >> s;
        for (int i = 1; i <= N; i++) {
            int l, r;
            cin >> l >> r;
            tree[i] = new node();
            if (s[i-1] == 'L') {
                tree[i]->val = 0;
            } else if (s[i-1] == 'R') {
                tree[i]->val = 1;
            } else {
                tree[i]->val = 2;
            }
            tree[i]->c[0] = l;
            tree[i]->c[1] = r;
        }
        int ans = solve(1);
        cout << ans << endl;
    }
}