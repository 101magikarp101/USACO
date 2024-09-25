#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int a[200005];

struct node {
    int x;
    node *l, *r;
    node(int x) : x(x), l(0), r(0) {}
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    node* pt = new node(1);
    return 0;
}