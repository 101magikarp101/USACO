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

struct node {
    int l, r;
    int v;
    vt<node*> c = {nullptr, nullptr};
};

int N;
node* root;
int a[200005];
int ans[200005];

void build(int l, int r, node* n, int i) {
    // cout << "l: " << l << " r: " << r << " v: " << a[i] << " i: " << i << '\n';
    n->v = a[i];
    n->l = l;
    n->r = r;
    if (a[i] <= l || a[i] > r) return;
    // cout << "l: " << l << " r: " << r << " v: " << n->v << " i: " << i << '\n';
    if (l==r) return;
    n->c[1] = new node();
    build(n->v, r, n->c[1], i+1);
    if (n->v > l) {
        n->c[0] = new node();
        build(l, n->v-1, n->c[0], i+1);
    }
}

void run(node* n, int prev, int cur, int x) {
    if (prev==0&&cur==1) x++;
    // cout << "l: " << n->l << " r: " << n->r << " v: " << n->v << " x: " << x << '\n';
    if (n->l==n->r) {
        ans[n->l] = x;
        return;
    }
    run(n->c[1], cur, 1, x);
    if (n->v > n->l) run(n->c[0], cur, 0, x);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    root = new node();
    build(0, N, root, 0);
    // cout << "done building" << '\n';
    run(root, -1, -1, 0);
    for (int i = 0; i <= N; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}